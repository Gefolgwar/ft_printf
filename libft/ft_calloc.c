/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcorrea- <wcorrea-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 18:35:59 by wcorrea-          #+#    #+#             */
/*   Updated: 2023/04/17 22:01:27 by wcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>
#include <stdint.h> // ДОДАЙТЕ ЦЕЙ РЯДОК

void *ft_calloc(size_t nmemb, size_t size)
{
    size_t  total_size;
    void    *p;

    // Перевірка на переповнення (SIZE_MAX/nmemb)
    if (nmemb != 0 && size > (SIZE_MAX / nmemb))
    {
        return (NULL);
    }
    
    total_size = nmemb * size;
    p = malloc(total_size);
    
    if (!p)
    {
        return (NULL);
    }
    
    ft_memset(p, 0, total_size);
    return (p);
}
