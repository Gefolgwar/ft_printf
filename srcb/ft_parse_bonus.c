#include "../inc/ft_printf_bonus.h"

t_format	ft_parse_bonus(char *str, t_format f);
t_format	ft_parse_width(char *str, va_list ap, t_format f);
t_format	ft_parse_precision(char *str, va_list ap, t_format f);

static t_format	ft_handle_flags(t_format f)
{
	if (f.width < 0)
	{
		f.minus = 1;
		f.width *= -1;
	}
	if (f.precision < 0)
		f.neg_prec = 1;
	else
		f.neg_prec = 0;
	if (f.neg_prec)
		f.dot = 0;
	return (f);
}

static int	ft_print_format(t_format f, va_list ap)
{
	int	count;

	count = 0;
	if (f.specifier == 'c' || f.specifier == '%')
		count = ft_print_c_pct(f, ap);
	else if (f.specifier == 's')
		count = ft_print_s(f, ap);
	else if (f.specifier == 'd' || f.specifier == 'i' || f.specifier == 'u')
		count = ft_print_d_i_u(f, ap);
	else if (f.specifier == 'x' || f.specifier == 'X')
		count = ft_print_x(f, ap);
	else if (f.specifier == 'o')
		count = ft_print_o(f, ap);
	else if (f.specifier == 'p')
		count = ft_print_p(f, ap);
	return (count);
}

int	ft_parse(char *str, va_list ap)
{
	t_format	new_format;

	new_format = ft_parse_width(str, ap, ft_newformat());
	new_format = ft_parse_bonus(str, new_format);
	while (!ft_strchr(SPECIFIERS, *str) && *str != '.')
		str++;
	if (*str == '.' && !new_format.specifier)
	{
		new_format.dot = 1;
		str++;
		new_format = ft_parse_precision(str, ap, new_format);
		if (*str == '*')
			str++;
		else
			while (ft_isdigit(*str))
				str++;
	}
	new_format = ft_handle_flags(new_format);
	new_format.specifier = *str;
	return (ft_print_format(new_format, ap));
}
