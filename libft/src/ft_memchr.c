/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bismail <bismail@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 15:57:33 by bismail           #+#    #+#             */
/*   Updated: 2024/09/19 11:17:17 by bismail          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	char	*mod;
	size_t	i;

	i = 0;
	mod = (char *)s;
	while (i < n)
	{
		if (mod[i] == (char)c)
			return ((void *)&mod[i]);
		i++;
	}
	return (NULL);
}
