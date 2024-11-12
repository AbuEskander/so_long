/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bismail <bismail@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 19:49:45 by bismail           #+#    #+#             */
/*   Updated: 2024/09/19 11:17:27 by bismail          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*source;
	char	*dst;
	size_t	i;

	i = n;
	dst = (char *)dest;
	source = (char *)src;
	if (dst == source || n == 0)
		return (dest);
	if (dst < source || (dst >= (source + n)))
	{
		ft_memcpy(dest, source, n);
	}
	else
	{
		while (i > 0)
		{
			dst[i - 1] = source[i - 1];
			i--;
		}
	}
	return (dst);
}
