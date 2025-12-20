#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include "libft.h"
#include <stdio.h>
#include <stdarg.h>
#include <limits.h>
#include <stdbool.h>

int	ft_printf(const char *__format, ...);
int	prt_str(char const *str);
int	prt_ptr(void *addr);
int	prt_int(int n);
int	prt_unsigned(unsigned int nbr);
int	prt_hexa(unsigned int nbr, bool upper_case);
#endif