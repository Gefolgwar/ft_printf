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
	f.neg_prec = f.precision < 0;
	if (f.neg_prec)
	{
		f.dot = 0;
	}
	return (f);
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
		new_format = ft_parse_precision(str + 1, ap, new_format);
		str++;
		while (ft_isdigit(*str) || *str == '*')
			str++;
	}
	new_format = ft_handle_flags(new_format);
	new_format.specifier = *str;
	return (ft_print_format(new_format, ap));
}
