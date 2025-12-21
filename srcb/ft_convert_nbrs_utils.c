#include "../inc/ft_printf_bonus.h"
#include <stdlib.h>

static int	ft_nbrlen_base(unsigned int n, int base)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		len++;
		n /= base;
	}
	return (len);
}

char	*ft_uitoa_base(unsigned int n, int base)
{
	char	*str;
	int		len;
	char	*set;

	set = "0123456789abcdef";
	len = ft_nbrlen_base(n, base);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len] = '\0';
	if (n == 0)
	{
		str[0] = '0';
		return (str);
	}
	while (n)
	{
		str[--len] = set[n % base];
		n /= base;
	}
	return (str);
}
