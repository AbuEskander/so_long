/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bismail <bismail@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 16:50:58 by bismail           #+#    #+#             */
/*   Updated: 2024/09/19 11:17:33 by bismail          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	char	*p;
	char	vale;
	size_t	i;

	p = s;
	i = 0;
	vale = (unsigned char)c;
	while (i < n)
	{
		p[i] = vale;
		i++;
	}
	return (p);
}
