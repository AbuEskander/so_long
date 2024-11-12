/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bismail <bismail@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 18:14:03 by bismail           #+#    #+#             */
/*   Updated: 2024/09/19 11:19:41 by bismail          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*se;

	se = (char *)s;
	i = ft_strlen(se);
	while (i >= 0)
	{
		if (se[i] == (char)c)
			return (se + i);
		i--;
	}
	if (c == 0)
		return (se + i);
	return (NULL);
}
