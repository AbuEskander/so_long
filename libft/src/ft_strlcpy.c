/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bismail <bismail@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 12:38:13 by bismail           #+#    #+#             */
/*   Updated: 2024/09/19 11:19:07 by bismail          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	char	*d;
	char	*s;
	size_t	n;

	d = (char *)dst;
	s = (char *)src;
	n = size;
	if (n != 0)
	{
		while (--n != 0 && *s != '\0')
		{
			*d = *s;
			d++;
			s++;
		}
		*d = '\0';
	}
	if (n == 0)
	{
		if (size != 0)
			*d = '\0';
		while (*s)
			s++;
	}
	return (s - src);
}
