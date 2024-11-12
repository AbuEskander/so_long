/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bismail <bismail@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 18:37:05 by bismail           #+#    #+#             */
/*   Updated: 2024/09/19 11:18:43 by bismail          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(char *src)
{
	char	*news;
	int		i;

	news = (char *)malloc(sizeof(char) * (ft_strlen(src) + 1));
	if (!news)
		return (NULL);
	i = 0;
	while (*src)
		news[i++] = *src++;
	news[i] = '\0';
	return (news);
}
