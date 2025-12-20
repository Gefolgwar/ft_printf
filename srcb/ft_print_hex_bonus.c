#include "../inc/ft_printf_bonus.h"

static char     *ft_sharp(t_format f)
{
        if (f.specifier == 'X')
                return ("0X");
        return ("0x");
}

/* Допоміжна функція для підрахунку довжини саме size_t (покажчиків) */
static int      ft_ptr_len(size_t n)
{
        int     len;

        len = 0;
        if (n == 0)
                return (0);
        while (n != 0)
        {
                len++;
                n /= 16;
        }
        return (len);
}

static int      ft_recursive_hex(t_format f, size_t n, size_t iteration)
{
        int             count;
        int             remainder;
        char    character;

        count = 0;
        // Ключова умова: n>0 або (якщо n=0, але ми не в режимі точної обробки pointer (f.specifier != 'p' || !f.dot))
        // Оскільки для %o, %x, %X при n=0 і негативній точності f.dot=0, умова f.specifier != 'p' || !f.dot) буде true
        if (n > 0 || (!iteration && (f.specifier != 'p' || !f.dot)))
        {
                // ... (решта логіки) ...
                remainder = n % 16;
                if (f.specifier != 'X')
                        character = HEXALOW[remainder];
                else
                        character = HEXAUP[remainder];
                n /= 16;
                iteration = 1;
                count += ft_recursive_hex(f, n, iteration);
                count += ft_putchar_fd(character, 1);
        }
        return (count);
}

int     ft_print_x(t_format f, va_list ap)
{
        int                             count;
        unsigned int    n;
        int                             len;

        count = 0;
        n = va_arg(ap, unsigned int);
        // Припускаємо, що для %o ви викликаєте ft_nbrlen(n, 8) і ft_recursive_octal
        len = ft_nbrlen(n, 16); 
        
        // 1. Обробка n=0 та .0 (precision=0)
        if (!n && !f.precision && f.dot)
                len = 0;
        
        // 2. Встановлення f.precision
        if (f.precision < 0 || f.precision < len || !f.dot)
                f.precision = len;
        
        // --- !!! КРИТИЧНЕ ВИПРАВЛЕННЯ ДЛЯ НЕГАТИВНОЇ ТОЧНОСТІ І n=0 !!! ---
        // Якщо n=0, f.dot вимкнено (через негативну точність) і len=0, це означає
        // що число 0 було проаналізовано як "порожній рядок", а має бути "0".
        // Якщо точність ігнорується (!f.dot), і число 0, len має бути 1.
        if (n == 0 && !f.dot)
        {
            if (len == 0)
                len = 1; // Гарантуємо вивід "0"
            if (f.precision == 0)
                 f.precision = 1; // Гарантуємо, що precision дозволить вивести len=1
        }
        // -----------------------------------------------------------------

        if (f.sharp && n)
                f.width -= 2;
        count += ft_putstrn_fd(ft_sharp(f), 1, 2 * (f.sharp && f.zero && n));
        if (!f.minus && f.width > f.precision && (!f.dot || f.neg_prec) && f.zero)
                count += ft_putnchar_fd('0', 1, (f.width - f.precision));
        else if (!f.minus && f.width > f.precision)
                count += ft_putnchar_fd(' ', 1, (f.width - f.precision));
        count += ft_putstrn_fd(ft_sharp(f), 1, 2 * (f.sharp && !f.zero && n));
        count += ft_putnchar_fd('0', 1, (f.precision - len));
        
        // Тут len може дорівнювати 1 для n=0, тому число друкується.
        if (len)
                count += ft_recursive_hex(f, n, n); 
        
        if (f.minus && f.width > f.precision)
                count += ft_putnchar_fd(' ', 1, f.width - f.precision);
        return (count);
}

static int      ft_recursive_octal(t_format f, unsigned int n)
{
        int             count;
        
        count = 0;
        if (n >= 8)
                count += ft_recursive_octal(f, n / 8);
        count += ft_putchar_fd(HEXALOW[n % 8], 1);
        return (count);
}

// Припустимо, ви маєте функцію ft_nbrlen(n, base)
// Якщо ні, використовуйте:
/*
static int      ft_nbrlen_base(unsigned int n, int base)
{
        int     len;

        len = 0;
        if (n == 0)
                return (1); // 0 займає 1 символ
        while (n != 0)
        {
                len++;
                n /= base;
        }
        return (len);
}
*/

int     ft_print_o(t_format f, va_list ap)
{
        int                             count;
        unsigned int    n;
        int                             len;
        int                             len_with_sharp;

        count = 0;
        n = va_arg(ap, unsigned int);
        
        // Використовуємо базу 8
        len = ft_nbrlen(n, 8); 
        
        // 1. Обробка n=0 та .0 (precision=0)
        // Якщо n=0, точність 0, і крапка є -> len = 0 (порожній рядок)
        if (!n && !f.precision && f.dot)
                len = 0;

        // 2. Обробка прапору # (для %o це префікс '0')
        len_with_sharp = len;
        if (f.sharp && n)
        {
            // Якщо # присутній і число не 0, довжина збільшується на 1 (для '0')
            // Але якщо len < precision, то '0' враховується в precision
            if (f.precision <= len)
                len_with_sharp = len + 1; // Додаємо 1 для префіксу '0'
        }
        
        // 3. Встановлення f.precision
        // Якщо precision < len (або len_with_sharp) АБО точність ігнорується (!f.dot)
        if (f.precision < len_with_sharp || !f.dot)
                f.precision = len_with_sharp;

        // --- ВИПРАВЛЕННЯ ДЛЯ НЕГАТИВНОЇ ТОЧНОСТІ І n=0 (Test 4194) ---
        // Якщо точність ігнорується (!f.dot), і len=0 (через n=0 та .0),
        // ми повинні повернути len=1, щоб надрукувати "0".
        if (n == 0 && !f.dot && len == 0) 
        {
            len = 1;
            f.precision = 1; 
        }
        // -------------------------------------------------------------
        
        // 4. Обробка ширини
        // Встановлюємо загальну довжину для обчислення пробілів
        int total_len = f.precision;
        
        if (f.sharp && n && f.precision > len)
            total_len = f.precision; // # враховано в нулях
        else if (f.sharp && n && f.precision == len)
             total_len = len + 1; // # додає 1 символ (префікс '0')

        if (f.sharp && n && f.precision > len)
            f.width -= 1; // "0" вже буде частиною заповнення нулями

        // Вивід заповнення пробілами зліва
        if (!f.minus && f.width > total_len && (!f.zero || (f.dot && !f.neg_prec)))
            count += ft_putnchar_fd(' ', 1, (f.width - total_len));

        // Вивід заповнення нулями (якщо f.zero) або пробілами (якщо f.dot відсутній і f.zero)
        if (!f.minus && f.width > total_len && f.zero && (!f.dot || f.neg_prec))
            count += ft_putnchar_fd('0', 1, (f.width - total_len));

        // 5. Вивід префіксу '0' (якщо # і не враховано в нулях)
        if (f.sharp && n && f.precision == len)
            count += ft_putchar_fd('0', 1);

        // 6. Вивід нулів точності
        count += ft_putnchar_fd('0', 1, (f.precision - len));

        // 7. Вивід числа
        if (len)
                count += ft_recursive_octal(f, n);
        
        // 8. Вивід пробілів справа
        if (f.minus && f.width > total_len)
                count += ft_putnchar_fd(' ', 1, f.width - total_len);
        
        return (count);
}

int     ft_print_p(t_format f, va_list ap)
{
        int             count;
        size_t  n;
        int             len;
        char    *nil_str;
        int             nil_len;
        int             spaces_to_print;

        count = 0;
        nil_str = "(nil)";
        nil_len = 5;
        n = va_arg(ap, size_t);

        // 1. ОБРОБКА NULL
        if (n == 0)
        {
                spaces_to_print = 0;
                if (f.width > nil_len)
                        spaces_to_print = f.width - nil_len;
                if (!f.minus && spaces_to_print > 0)
                        count += ft_putnchar_fd(' ', 1, spaces_to_print);
                count += write(1, nil_str, nil_len);
                if (f.minus && spaces_to_print > 0)
                        count += ft_putnchar_fd(' ', 1, spaces_to_print);
                return (count);
        }

        // 2. ОБРОБКА НЕ-NULL (Використовуємо ft_ptr_len замість ft_nbrlen)
        len = ft_ptr_len(n);
        
        f.precision = len; 
        int total_len = 2 + len; // 2 ("0x") + довжина цифр
        
        spaces_to_print = 0;
        if (f.width > total_len)
                spaces_to_print = f.width - total_len;

        // Пробіли зліва
        if (!f.minus && spaces_to_print > 0)
                count += ft_putnchar_fd(' ', 1, spaces_to_print);

        // Префікс і число
        count += write(1, "0x", 2);
        count += ft_recursive_hex(f, n, n);

        // Пробіли справа (Minus flag)
        if (f.minus && spaces_to_print > 0)
                count += ft_putnchar_fd(' ', 1, spaces_to_print);

        return (count);
}