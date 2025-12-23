#ifndef FT_PRINTF_BONUS_H

# define FT_PRINTF_BONUS_H

# include "libft.h"
# include <stdarg.h>

typedef struct s_format
{
	int		minus;
	int		plus;
	int		width;
	int		precision;
	int		neg_prec;
	char	specifier;
	int		zero;
	int		dot;
	int		space;
	int		sharp;
}	t_format;

typedef struct s_num_info
{
	int	neg;
	int	len;
	int	char_to_skip;
}	t_num_info;

typedef struct s_print_data
{
	int	len;
	int	neg;
	int	padding_len;
	int	char_to_print;
}	t_print_data;

# define INT_MIN -2147483648
# define UINT_MAX 4294967295
# define SPECIFIERS	"cspdiuxX%o"
# define HEXALOW	"0123456789abcdef"
# define HEXAUP		"0123456789ABCDEF"

int			ft_printf(const char *str, ...);
t_format	ft_newformat(void);
int			ft_print_c_pct(t_format f, va_list ap);
int			ft_print_s(t_format f, va_list ap);
int			ft_print_d_i_u(t_format f, va_list ap);
int			ft_print_x(t_format f, va_list ap);
int			ft_print_p(t_format f, va_list ap);
int			ft_parse(char *str, va_list	ap);
int			ft_print_o(t_format f, va_list ap);
int			ft_print_p(t_format f, va_list ap);
int			ft_print_x(t_format f, va_list ap);
char		*ft_uitoa_base(unsigned int n, int base);
char		*ft_handle_d_i_u_data(t_format *f, va_list ap, t_num_info *info);
int			ft_print_d_i_u(t_format f, va_list ap);
#endif
