#include "../inc/ft_printf_bonus.h"
#include <stdlib.h>
#include <unistd.h>

static int	ft_print_nbr_parts(t_format f, char *nbr, t_print_data data)
{
	int	c;

	c = 0;
	if (!f.minus && data.padding_len > 0 && (!f.zero || f.dot))
		c += ft_putnchar_fd(' ', 1, data.padding_len);
	if (data.char_to_print)
	{
		if (data.neg)
			c += ft_putchar_fd('-', 1);
		else if (f.plus)
			c += ft_putchar_fd('+', 1);
		else if (f.space)
			c += ft_putchar_fd(' ', 1);
	}
	if (!f.minus && data.padding_len > 0 && f.zero && !f.dot)
		c += ft_putnchar_fd('0', 1, data.padding_len);
	c += ft_putnchar_fd('0', 1, f.precision - data.len);
	if (data.len > 0)
		c += write(1, nbr, data.len);
	if (f.minus && data.padding_len > 0)
		c += ft_putnchar_fd(' ', 1, data.padding_len);
	return (c);
}

static void	ft_calculate_char_to_print(t_format f, t_print_data *data)
{
	data->char_to_print = 0;
	if (data->neg)
	{
		data->char_to_print = 1;
	}
	else if (f.plus)
	{
		data->char_to_print = 1;
	}
	else if (f.space && !data->neg && !f.plus)
	{
		data->char_to_print = 1;
	}
}

static int	ft_print_nbr(t_format f, char *nbr, int len, int neg)
{
	t_print_data	data;
	int				c;
	int				content_len;

	c = 0;
	data.neg = neg;
	data.len = len;
	ft_calculate_char_to_print(f, &data);
	content_len = f.precision;
	if (data.char_to_print)
		content_len += 1;
	data.padding_len = 0;
	if (f.width > content_len)
		data.padding_len = f.width - content_len;
	c += ft_print_nbr_parts(f, nbr, data);
	return (c);
}

int	ft_print_d_i_u(t_format f, va_list ap)
{
	char				*nbr;
	int					c;
	t_num_info			info;

	c = 0;
	nbr = ft_handle_d_i_u_data(&f, ap, &info);
	if (!nbr)
		return (0);
	c += ft_print_nbr(f, nbr + info.char_to_skip, info.len, info.neg);
	free(nbr);
	return (c);
}
