/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bismail <bismail@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 13:43:31 by bismail           #+#    #+#             */
/*   Updated: 2024/09/19 11:19:30 by bismail          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	char	*b;

	b = (char *)big;
	if (!ft_strlen(little))
		return (b);
	while (*b && len)
	{
		if (len < ft_strlen(little))
			return (NULL);
		if (ft_strncmp(b, little, ft_strlen(little)) == 0)
			return ((char *)(b));
		len--;
		b++;
	}
	return (NULL);
}
