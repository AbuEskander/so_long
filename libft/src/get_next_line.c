/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proton <proton@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 08:59:38 by bismail           #+#    #+#             */
/*   Updated: 2024/11/14 18:02:41 by proton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (i < n && *(src + i) != '\0')
	{
		*(dest + i) = *(src + i);
		i++;
	}
	while (i < n)
	{
		*(dest + i) = '\0';
		i++;
	}
	return (dest);
}

static char	*newlinecheck(char **total)
{
	char	*newline_pos;
	char	*line;
	char	*temp;
	int		len;

	newline_pos = ft_strchr(*total, '\n');
	if (newline_pos)
	{
		len = newline_pos - *total + 1;
		line = malloc(len + 1);
		if (!line)
			return (handle_free(total, -1));
		ft_strncpy(line, *total, len);
		line[len] = '\0';
		temp = ft_strdup(newline_pos + 1);
		if (!temp)
			return (handle_free(total, -1));
		free(*total);
		*total = temp;
	}
	else
		return (handle_free(total, 0));
	return (line);
}

static char	*readjoin(char *buff, char **total, int fd)
{
	int		cas;
	char	*temp;

	if (!*total)
		return (NULL);
	while (!ft_strchr(*total, '\n'))
	{
		cas = read(fd, buff, BUFFER_SIZE);
		if (cas == -1)
			return (handle_free(total, -1));
		if (cas == 0)
		{
			if ((*total)[0] == '\0')
				return (handle_free(total, -1));
			break ;
		}
		buff[cas] = '\0';
		temp = ft_strjoin(*total, buff);
		if (!temp)
			return (handle_free(total, -1));
		free(*total);
		*total = temp;
	}
	return (*total);
}

char	*get_next_line(int fd)
{
	static char	*total = NULL;
	char		*buff;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buff = malloc(BUFFER_SIZE + 1);
	if (!buff)
		return (NULL);
	if (!total)
		total = ft_strdup("");
	if (!readjoin(buff, &total, fd))
	{
		if (buff)
			free(buff);
		return (NULL);
	}
	if (buff)
		free(buff);
	if (!total)
		return (NULL);
	return (newlinecheck(&total));
}
