/* ************************************************************************** */
/* */
/* :::      ::::::::   */
/* ft_parse_bonus.c                                   :+:      :+:    :+:   */
/* +:+ +:+         +:+     */
/* By: aperez-b <marvin@42.fr>                    +#+  +:+       +#+        */
/* +#+#+#+#+#+   +#+           */
/* Created: 2021/07/08 09:01:25 by aperez-b          #+#    #+#             */
/* Updated: 2021/12/19 19:30:58 by user1            ###   ########.fr       */
/* */
/* ************************************************************************** */

#include "../inc/ft_printf_bonus.h"

static t_format	ft_parse_bonus(char *str, t_format f)
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

static t_format	ft_parse_width(char *str, va_list ap, t_format f)
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

static t_format	ft_parse_precision(char *str, va_list ap, t_format f)
{
	int	specified;

	specified = 0;
	while (!ft_strchr(SPECIFIERS, *str))
	{
		if ((ft_isdigit(*str) || *str == '*') && !specified)
		{
			if (*str == '*')
			{
				f.precision = va_arg(ap, int);
				specified = 1;
				str++;      // Просуваємось після '*'
				continue ;
			}
			else
			{
				f.precision = ft_atoi(str);
				specified = 1;
				// Просуваємо str на довжину числа
				while (ft_isdigit(*str))
					str++;
				continue ;
			}
		}
		str++; // Це для символів, які ми ігноруємо
	}
	return (f);
}

int	ft_parse(char *str, va_list ap)
{
	t_format	new_format;

	new_format = ft_parse_width(str, ap, ft_newformat());
	new_format = ft_parse_bonus(str, new_format);
	
	// Знаходимо крапку або специфікатор
	while (!ft_strchr(SPECIFIERS, *str) && *str != '.')
		str++;

	if (*str == '.' && !new_format.specifier)
	{
		new_format.dot = 1;
		
		// Обробляємо точність, починаючи з символу ПІСЛЯ крапки
		new_format = ft_parse_precision(str + 1, ap, new_format);
		
		str++; // Пропускаємо саму крапку
		
		// Просуваємось до специфікатора (пропускаємо цифри точності або *)
		while (ft_isdigit(*str) || *str == '*')
			str++;
	}
	
	if (new_format.width < 0)
	{
		new_format.minus = 1;
		new_format.width *= -1;
	}
	
	new_format.specifier = *str;
	new_format.neg_prec = new_format.precision < 0;

	if (new_format.neg_prec)
	{	
    	new_format.dot = 0;
    	// КРИТИЧНО: НЕ ВСТАНОВЛЮВАТИ new_format.precision = 0;
    	// Це призведе до неправильного виводу "" для числа 0 (як у Тесті 4194)
	}

	return (ft_print_format(new_format, ap));
}