/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bismail <bismail@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 18:52:32 by bismail           #+#    #+#             */
/*   Updated: 2024/09/19 11:36:01 by bismail          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char	*mod;
	char	*source;
	size_t	i;

	i = 0;
	mod = (char *)dest;
	source = (char *)src;
	if (!dest && !src)
		return (NULL);
	while (i < n)
	{
		mod[i] = source[i];
		i++;
	}
	return (dest);
}
