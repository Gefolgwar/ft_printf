#include "../inc/ft_printf_bonus.h" 
#include <stdlib.h> 
#include <unistd.h> 
#include <stdio.h> // Видаліть, якщо не потрібен

// --- Допоміжні функції для обробки октального формату (%o) ---
static int ft_nbrlen_base(unsigned int n, int base)
{
    int len;

    len = 0;
    if (n == 0)
        return (1);
    while (n != 0)
    {
        len++;
        n /= base;
    }
    return (len);
}

static char *ft_uitoa_base(unsigned int n, int base)
{
    char    *str;
    int     len;
    char    *set = "0123456789abcdef"; 

    len = ft_nbrlen_base(n, base);
    str = (char *)malloc(sizeof(char) * (len + 1));
    if (!str)
        return (NULL);
    str[len] = '\0';
    if (n == 0)
    {
        str[0] = '0';
        return (str);
    }
    while (n)
    {
        str[--len] = set[n % base];
        n /= base;
    }
    return (str);
}
// ----------------------------------------------------------------

static int      ft_print_nbr(t_format f, char *nbr, int len, int neg)
{
        int     c;
        int     char_to_print; 
        int     content_len;
        int     padding_len;
        
        c = 0;
        char_to_print = neg || f.plus || (f.space && !neg && !f.plus);

        // 1. Обчислення загальної довжини контенту (числа + знаку/пробілу)
        // total_len = max(precision, len) + (1 якщо знак/пробіл)
        content_len = f.precision; // f.precision вже max(precision, len)

        if (char_to_print)
                content_len += 1; // Додаємо 1 для знаку/пробілу
        
        // 2. Обчислення довжини заповнення (завжди невід'ємне)
        padding_len = 0;
        if (f.width > content_len)
                padding_len = f.width - content_len; 
        
        // 3. Ліве заповнення (ПРОБІЛИ)
        // Якщо !f.minus І не використовується прапор '0' (або '0' ігнорується через крапку)
        if (!f.minus && padding_len > 0 && (!f.zero || f.dot))
            c += ft_putnchar_fd(' ', 1, padding_len);
        
        // 4. Вивід Знаку/Пробілу
        // Знак друкується завжди перед нулями заповнення/точності
        if (char_to_print)
        {
                if (neg)
                        c += ft_putchar_fd('-', 1);
                else if (f.plus)
                        c += ft_putchar_fd('+', 1);
                else if (f.space)
                        c += ft_putchar_fd(' ', 1);
        }
        
        // 5. Заповнення НУЛЯМИ (для прапору '0')
        // Якщо !f.minus І використовується прапор '0' І крапка відсутня (!f.dot)
        if (!f.minus && padding_len > 0 && f.zero && !f.dot)
            c += ft_putnchar_fd('0', 1, padding_len);

        // 6. Вивід Нулів Точності
        c += ft_putnchar_fd('0', 1, f.precision - len);
        
        // 7. Вивід Цифр
        if (len > 0)
            c += write(1, nbr, len); 
        
        // 8. Праве заповнення (Пробіли, якщо f.minus)
        if (f.minus && padding_len > 0) 
                c += ft_putnchar_fd(' ', 1, padding_len);
        
        return (c);
}


int     ft_print_d_i_u(t_format f, va_list ap)
{
        char    *nbr;
        long long   n_ll; 
        unsigned int n_u; 
        int             c;
        int             len;
        int             neg;
        int             char_to_skip = 0; 
        int             is_octal;

        c = 0;
        is_octal = (f.specifier == 'o');
        
        // 1. Зчитування аргументів та визначення знаку
        if (f.specifier == 'u' || is_octal)
        {
            n_u = va_arg(ap, unsigned int);
            n_ll = n_u; 
            neg = 0;
        }
        else // d or i
        {
            n_ll = va_arg(ap, int); 
            n_u = n_ll; 
            neg = (n_ll < 0);
            if (neg)
                f.plus = 0;
        }

        // 2. Конвертація на рядок
        if (is_octal)
            nbr = ft_uitoa_base(n_u, 8); 
        else if (f.specifier == 'u')
            nbr = ft_uitoa(n_u); 
        else if (n_ll < 0 && f.specifier == 'u')
            nbr = ft_uitoa((unsigned)n_ll); 
        else
            nbr = ft_itoa(n_ll); 
        
        if (!nbr) 
            return (0);

        // 3. Корекція довжини
        len = ft_strlen(nbr);
        if (neg && nbr[0] == '-') 
        {
            char_to_skip = 1;
            len--; 
        }

        // 4. Обробка довжини (коли n=0, .0)
        // Якщо число '0':
        if (*(nbr + char_to_skip) == '0')
        {
            // Якщо присутня крапка (f.dot) І точність явно нульова (f.precision == 0)
            // І це НЕ негативна точність (!f.neg_prec)
            if (f.dot && f.precision == 0 && !f.neg_prec)
                len = 0;
        }
        
        // 5. Встановлення фінальної точності (f.precision)
        
        // Якщо точність була негативною (f.neg_prec) або крапка відсутня (!f.dot), 
        // точність має дорівнювати фактичній довжині числа (len).
        if (f.neg_prec || !f.dot)
        {
            f.precision = len; 
        }
        // В іншому випадку, якщо точність менша за довжину, використовуємо довжину.
        else if (f.precision < len)
            f.precision = len;
        
        // 6. Друк
        c += ft_print_nbr(f, nbr + char_to_skip, len, neg); 
        
        free(nbr); 
        return (c);
}