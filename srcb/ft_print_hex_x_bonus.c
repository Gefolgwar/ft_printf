#include "../inc/ft_printf_bonus.h"

int	ft_recursive_hex_print(t_format f, size_t n, size_t iteration);

static char	*ft_sharp(t_format f)
{
	if (f.specifier == 'X')
		return ("0X");
	return ("0x");
}

static int	ft_print_x_output(t_format f, unsigned int n, int len)
{
	int	count;

	count = 0;
	if (f.sharp && n)
		f.width -= 2;
	count += ft_putstrn_fd(ft_sharp(f), 1, 2 * (f.sharp && f.zero && n));
	if (!f.minus && f.width > f.precision && (!f.dot || f.neg_prec) && f.zero)
		count += ft_putnchar_fd('0', 1, (f.width - f.precision));
	else if (!f.minus && f.width > f.precision)
		count += ft_putnchar_fd(' ', 1, (f.width - f.precision));
	count += ft_putstrn_fd(ft_sharp(f), 1, 2 * (f.sharp && !f.zero && n));
	count += ft_putnchar_fd('0', 1, (f.precision - len));
	if (len)
		count += ft_recursive_hex_print(f, n, n);
	if (f.minus && f.width > f.precision)
		count += ft_putnchar_fd(' ', 1, f.width - f.precision);
	return (count);
}

int	ft_print_x(t_format f, va_list ap)
{
	int				len;
	unsigned int	n;

	n = va_arg(ap, unsigned int);
	len = ft_nbrlen(n, 16);
	if (!n && !f.precision && f.dot)
		len = 0;
	if (f.precision < 0 || f.precision < len || !f.dot)
		f.precision = len;
	if (n == 0 && !f.dot)
	{
		if (len == 0)
			len = 1;
		if (f.precision == 0)
			f.precision = 1;
	}
	return (ft_print_x_output(f, n, len));
}
