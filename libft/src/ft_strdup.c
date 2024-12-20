/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proton <proton@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 18:37:05 by bismail           #+#    #+#             */
/*   Updated: 2024/11/14 18:00:24 by proton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(char *src)
{
	char	*news;
	int		i;

	news = malloc(sizeof(char) * (ft_strlen(src) + 1));
	if (!news)
		return (NULL);
	i = 0;
	while (*src)
		news[i++] = *src++;
	news[i] = '\0';
	return (news);
}
