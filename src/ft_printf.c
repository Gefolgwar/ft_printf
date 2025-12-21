#include "ft_printf.h"

static int	exec_conversion(char spec_ltr, va_list ap)
{
	if (spec_ltr == '%')
		return (write(1, "%", 1));
	else if (spec_ltr == 'c')
	{
		ft_putchar_fd(va_arg(ap, int), 1);
		return (1);
	}
	else if (spec_ltr == 's')
		return (prt_str(va_arg(ap, char *)));
	else if (spec_ltr == 'p')
		return (prt_ptr(va_arg(ap, void *)));
	else if (spec_ltr == 'd' || spec_ltr == 'i')
		return (prt_int(va_arg(ap, int)));
	else if (spec_ltr == 'u')
		return (prt_unsigned(va_arg(ap, unsigned int)));
	else if (spec_ltr == 'x')
		return (prt_hexa(va_arg(ap, unsigned int), false));
	else if (spec_ltr == 'X')
		return (prt_hexa(va_arg(ap, unsigned int), true));
	return (0);
}

int	ft_printf(const char *fmt, ...)
{
	int		i;
	int		len;
	va_list	args;

	if (!fmt)
		return (0);
	i = 0;
	len = 0;
	va_start(args, fmt);
	while (fmt[i])
	{
		if (fmt[i] == '%')
		{
			i++;
			len = len + exec_conversion(fmt[i], args);
		}
		else
			len = len + write(1, &fmt[i], 1);
		i++;
	}
	va_end(args);
	return (len);
}
