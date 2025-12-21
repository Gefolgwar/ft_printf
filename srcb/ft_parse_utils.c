#include "../inc/ft_printf_bonus.h"

t_format	ft_parse_bonus(char *str, t_format f)
{
	while (*str != '.' && !ft_strchr(SPECIFIERS, *str))
	{
		if (*str == '+')
			f.plus = 1;
		if (*str == ' ')
			f.space = 1;
		if (*str == '#')
			f.sharp = 1;
		str++;
	}
	return (f);
}

t_format	ft_parse_width(char *str, va_list ap, t_format f)
{
	int	specified;

	specified = 0;
	while (*str != '.' && !ft_strchr(SPECIFIERS, *str))
	{
		if (*str == '-')
			f.minus = 1;
		if (*str == '0' && !ft_isdigit(*(str - 1)))
			f.zero = 1;
		else if (((*str > '0' && *str <= '9') || *str == '*') && !specified)
		{
			if (*str == '*')
				f.width = va_arg(ap, int);
			else
				f.width = ft_atoi(str);
			specified = 1;
		}
		str++;
	}
	return (f);
}

static t_format	ft_get_precision_value(char **str, va_list ap, t_format f,
						int *specified)
{
	if (**str == '*')
	{
		f.precision = va_arg(ap, int);
		*specified = 1;
		(*str)++;
	}
	else
	{
		f.precision = ft_atoi(*str);
		*specified = 1;
		while (ft_isdigit(**str))
			(*str)++;
	}
	return (f);
}

t_format	ft_parse_precision(char *str, va_list ap, t_format f)
{
	int	specified;

	specified = 0;
	while (!ft_strchr(SPECIFIERS, *str))
	{
		if ((ft_isdigit(*str) || *str == '*') && !specified)
		{
			f = ft_get_precision_value(&str, ap, f, &specified);
			continue ;
		}
		str++;
	}
	return (f);
}
