#include "../inc/ft_printf_bonus.h"

static int	ft_print_pct(void)
{
	char	c;
	int		count;

	c = '%';
	count = 0;
	count += ft_putchar_fd(c, 1);
	return (count);
}

int	ft_print_c_pct(t_format f, va_list ap)
{
	char	c;
	int		count;
	int		len_to_print;
	char	padding_char;

	count = 0;
	if (f.specifier == 'c')
		c = va_arg(ap, int);
	else
	{
		return (ft_print_pct());
	}
	len_to_print = 1;
	padding_char = ' ';
	if (!f.minus && f.width > len_to_print)
		count += ft_putnchar_fd(padding_char, 1, f.width - len_to_print);
	count += ft_putchar_fd(c, 1);
	if (f.minus && f.width > len_to_print)
		count += ft_putnchar_fd(' ', 1, f.width - len_to_print);
	return (count);
}

static int	ft_get_str_len(t_format f, char **string)
{
	int	s_len;

	if (!*string && f.dot && f.precision < 6)
		*string = "";
	else if (!*string)
	{
		*string = "(null)";
	}
	s_len = ft_strlen(*string);
	if (f.dot && f.precision >= 0)
	{
		if (f.precision < s_len)
			s_len = f.precision;
		if (f.precision == 0)
			s_len = 0;
	}
	return (s_len);
}

int	ft_print_s(t_format f, va_list ap)
{
	char	*string;
	int		count;
	int		has_malloc;
	int		s_len;

	count = 0;
	has_malloc = 0;
	string = va_arg(ap, char *);
	s_len = ft_get_str_len(f, &string);
	if (!f.dot || f.precision < 0)
		f.precision = s_len;
	if (!f.minus && f.width > s_len)
		count += ft_putnchar_fd(' ', 1, f.width - s_len);
	count += ft_putstrn_fd(string, 1, s_len);
	if (f.minus && f.width > s_len)
		count += ft_putnchar_fd(' ', 1, f.width - s_len);
	if (has_malloc)
		free(string);
	return (count);
}
