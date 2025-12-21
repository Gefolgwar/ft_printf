#include "../inc/ft_printf_bonus.h"

int	ft_recursive_hex_print(t_format f, size_t n, size_t iteration);

static int	ft_ptr_len(size_t n)
{
	int	len;

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

static int	ft_print_p_non_null(t_format f, size_t n, int len)
{
	int	count;
	int	total_len;
	int	spaces_to_print;

	count = 0;
	total_len = 2 + len;
	spaces_to_print = 0;
	if (f.width > total_len)
		spaces_to_print = f.width - total_len;
	if (!f.minus && spaces_to_print > 0)
		count += ft_putnchar_fd(' ', 1, spaces_to_print);
	count += write(1, "0x", 2);
	count += ft_recursive_hex_print(f, n, n);
	if (f.minus && spaces_to_print > 0)
		count += ft_putnchar_fd(' ', 1, spaces_to_print);
	return (count);
}

static int	ft_print_p_null(t_format f)
{
	int	count;
	int	spaces_to_print;

	count = 0;
	spaces_to_print = 0;
	if (f.width > 5)
		spaces_to_print = f.width - 5;
	if (!f.minus && spaces_to_print > 0)
		count += ft_putnchar_fd(' ', 1, spaces_to_print);
	count += write(1, "(nil)", 5);
	if (f.minus && spaces_to_print > 0)
		count += ft_putnchar_fd(' ', 1, spaces_to_print);
	return (count);
}

int	ft_print_p(t_format f, va_list ap)
{
	size_t	n;
	int		len;

	n = va_arg(ap, size_t);
	if (n == 0)
	{
		return (ft_print_p_null(f));
	}
	len = ft_ptr_len(n);
	f.precision = len;
	return (ft_print_p_non_null(f, n, len));
}
