#include "../inc/ft_printf_bonus.h"

static int	ft_recursive_octal(t_format f, unsigned int n)
{
	int	count;

	count = 0;
	if (n >= 8)
		count += ft_recursive_octal(f, n / 8);
	count += ft_putchar_fd(HEXALOW[n % 8], 1);
	return (count);
}

static int	ft_print_o_output(t_format f, unsigned int n, int len,
					int total_len)
{
	int	count;

	count = 0;
	if (f.sharp && n && f.precision > len)
		f.width -= 1;
	if (!f.minus && f.width > total_len && (!f.zero || (f.dot && !f.neg_prec)))
		count += ft_putnchar_fd(' ', 1, (f.width - total_len));
	if (!f.minus && f.width > total_len && f.zero && (!f.dot || f.neg_prec))
		count += ft_putnchar_fd('0', 1, (f.width - total_len));
	if (f.sharp && n && f.precision == len)
		count += ft_putchar_fd('0', 1);
	count += ft_putnchar_fd('0', 1, (f.precision - len));
	if (len)
		count += ft_recursive_octal(f, n);
	if (f.minus && f.width > total_len)
		count += ft_putnchar_fd(' ', 1, f.width - total_len);
	return (count);
}

static void	ft_get_octal_len(unsigned int n, t_format *f, int *len)
{
	int	len_with_sharp;

	if (!n && !f->precision && f->dot)
		*len = 0;
	len_with_sharp = *len;
	if (f->sharp && n)
	{
		if (f->precision <= *len)
			len_with_sharp = *len + 1;
	}
	if (f->precision < len_with_sharp || !f->dot)
		f->precision = len_with_sharp;
	if (n == 0 && !f->dot && *len == 0)
	{
		*len = 1;
		f->precision = 1;
	}
}

int	ft_print_o(t_format f, va_list ap)
{
	unsigned int	n;
	int				len;
	int				total_len;

	n = va_arg(ap, unsigned int);
	len = ft_nbrlen(n, 8);
	ft_get_octal_len(n, &f, &len);
	total_len = f.precision;
	if (f.sharp && n && f.precision > len)
		total_len = f.precision;
	else if (f.sharp && n && f.precision == len)
		total_len = len + 1;
	return (ft_print_o_output(f, n, len, total_len));
}
