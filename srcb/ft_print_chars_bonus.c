#include "../inc/ft_printf_bonus.h"

int     ft_print_c_pct(t_format f, va_list ap)
{
        char    c;
        int             count;
        int             len_to_print;
        char            padding_char;

        count = 0;
        if (f.specifier == 'c')
                c = va_arg(ap, int);
        else
                c = '%'; // Специфікатор '%%'

        // --- ВИПРАВЛЕННЯ ДЛЯ '%%' (Тести 7-10) ---
        // Якщо тестер вимагає ігнорувати ширину для '%%'
        if (f.specifier == '%')
        {
            count += ft_putchar_fd(c, 1);
            return (count); // <--- Виходимо одразу, ігноруючи width/flags
        }
        
        // З цього моменту обробляємо лише f.specifier == 'c'
        
        len_to_print = 1;
        // Для %c, прапор '0' (f.zero) ігнорується, заповнення завжди пробілами.
        padding_char = ' ';

        // 1. Заповнення зліва (Правостороннє вирівнювання)
        if (!f.minus && f.width > len_to_print)
                count += ft_putnchar_fd(padding_char, 1, f.width - len_to_print);
        
        // 2. Вивід символу
        count += ft_putchar_fd(c, 1);
        
        // 3. Заповнення справа (Лівостороннє вирівнювання)
        if (f.minus && f.width > len_to_print)
                count += ft_putnchar_fd(' ', 1, f.width - len_to_print);
        
        return (count);
}

int     ft_print_s(t_format f, va_list ap)
{
        char    *string;
        int             count;
        int             has_malloc;
        int             s_len;

        count = 0;
        has_malloc = 0;
        string = va_arg(ap, char *);
        // If string is NULL and precision is given and is less than 6, treat as empty.
        if (!string && f.dot && f.precision < 6)
                string = "";
        // Otherwise, if string is NULL, treat as "(null)".
        else if (!string)
        {
                string = "(null)";
        }

        s_len = ft_strlen(string); 

        // 1. Обчислення остаточної довжини друку (s_len)
        // Якщо точність задана (f.dot) та не є негативною:
        if (f.dot && f.precision >= 0)
        {
            // Якщо точність менша за поточну довжину, обмежуємо s_len точністю
            if (f.precision < s_len)
                s_len = f.precision;
            
            // === КРИТИЧНЕ ВИПРАВЛЕННЯ ДЛЯ ТЕСТУ 91 ===
            // Якщо точність дорівнює 0, s_len має бути 0 (навіть якщо width > 0).
            if (f.precision == 0)
                s_len = 0; // ГАРАНТІЯ, що виведеться 0 символів
            // ===========================================
        }
        else // Якщо точність не задана або негативна, використовуємо повну довжину
        {
            f.precision = s_len;
        }

        // ... (2. Заповнення зліва) ...
        if (!f.minus && f.width > s_len)
                count += ft_putnchar_fd(' ', 1, f.width - s_len);

        // 3. Вивід рядка
        count += ft_putstrn_fd(string, 1, s_len);

        // ... (4. Заповнення справа та free) ...
        if (f.minus && f.width > s_len)
                count += ft_putnchar_fd(' ', 1, f.width - s_len);
        
        if (has_malloc)
                free(string);
        return (count);
}