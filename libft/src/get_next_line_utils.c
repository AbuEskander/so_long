/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bismail <bismail@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 08:49:33 by bismail           #+#    #+#             */
/*   Updated: 2024/09/09 16:50:19 by bismail          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	while (1)
	{
		if (*s == (char)c)
			return ((char *)s);
		if (*s == '\0')
			return (NULL);
		s++;
	}
	return (NULL);
}

char	*handle_free(char **total, int cas)
{
	char	*ret;

	if (cas == -1)
	{
		if (*total && total)
		{
			free(*total);
			*total = NULL;
		}
		return (NULL);
	}
	if (cas == 0)
	{
		ret = ft_strdup(*total);
		if (!ret)
			return (NULL);
		if (*total)
		{
			free(*total);
			*total = NULL;
		}
		return (ret);
	}
	return (NULL);
}

size_t	ft_strlen(const char *c)
{
	size_t	len;

	len = 0;
	while (c[len])
		len++;
	return (len);
}

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

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int	j;
	unsigned int	i;

	i = 0;
	while (*(dest + i) != '\0')
		i++;
	j = 0;
	while ((j < nb) && (*(src + j) != '\0'))
	{
		*(dest + i + j) = *(src + j);
		j++;
	}
	*(dest + i + j) = '\0';
	return (dest);
}
