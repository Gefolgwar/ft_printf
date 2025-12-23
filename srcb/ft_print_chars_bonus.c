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

	count = 0;
	if (f.specifier == 'c')
		c = va_arg(ap, int);
	else
	{
		return (ft_print_pct());
	}
	if (!f.minus && f.width > 1)
		count += ft_putnchar_fd(' ', 1, f.width - 1);
	count += ft_putchar_fd(c, 1);
	if (f.minus && f.width > 1)
		count += ft_putnchar_fd(' ', 1, f.width - 1);
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
	int		s_len;

	count = 0;
	string = va_arg(ap, char *);
	s_len = ft_get_str_len(f, &string);
	if (!f.dot || f.precision < 0)
		f.precision = s_len;
	if (!f.minus && f.width > s_len)
		count += ft_putnchar_fd(' ', 1, f.width - s_len);
	count += ft_putstrn_fd(string, 1, s_len);
	if (f.minus && f.width > s_len)
		count += ft_putnchar_fd(' ', 1, f.width - s_len);
	return (count);
}
