#include "../inc/ft_printf_bonus.h"
#include <stdlib.h>
#include <unistd.h>

static long long	ft_get_num_arg(t_format *f, va_list ap, int *neg)
{
	long long	n_ll;
	int			is_octal;

	is_octal = (f->specifier == 'o');
	if (f->specifier == 'u' || is_octal)
	{
		n_ll = va_arg(ap, unsigned int);
		*neg = 0;
	}
	else
	{
		n_ll = va_arg(ap, int);
		*neg = (n_ll < 0);
		if (*neg)
			f->plus = 0;
	}
	return (n_ll);
}

static char	*ft_read_and_convert_num(t_format *f, va_list ap, int *neg)
{
	long long	n_ll;
	int			is_octal;

	n_ll = ft_get_num_arg(f, ap, neg);
	is_octal = (f->specifier == 'o');
	if (is_octal)
		return (ft_uitoa_base((unsigned int)n_ll, 8));
	else if (f->specifier == 'u')
		return (ft_uitoa((unsigned int)n_ll));
	else if (n_ll < 0 && f->specifier == 'u')
		return (ft_uitoa((unsigned int)n_ll));
	else
		return (ft_itoa(n_ll));
}

static int	ft_adjust_precision_and_len(t_format *f, char *nbr,
						t_num_info *info)
{
	info->len = ft_strlen(nbr);
	info->char_to_skip = 0;
	if (info->neg && nbr[0] == '-')
	{
		info->char_to_skip = 1;
		info->len--;
	}
	if (*(nbr + info->char_to_skip) == '0')
	{
		if (f->dot && f->precision == 0 && !f->neg_prec)
			info->len = 0;
	}
	if (f->neg_prec || !f->dot)
		f->precision = info->len;
	else if (f->precision < info->len)
		f->precision = info->len;
	return (info->len);
}

char	*ft_handle_d_i_u_data(t_format *f, va_list ap, t_num_info *info)
{
	char	*nbr;

	nbr = ft_read_and_convert_num(f, ap, &info->neg);
	if (!nbr)
		return (NULL);
	info->len = ft_adjust_precision_and_len(f, nbr, info);
	return (nbr);
}
