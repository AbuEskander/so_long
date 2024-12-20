/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proton <proton@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 08:50:42 by bismail           #+#    #+#             */
/*   Updated: 2024/11/14 19:05:29 by proton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 40
# endif

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include "../includes/libft.h"

char	*get_next_line(int fd);
char	*ft_strchr(const char *s, int c);
char	*handle_free(char **total, int cas);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strdup(char *src);
char	*ft_strncat(char *dest, char *src, unsigned int nb);
size_t	ft_strlen(const char *c);

#endif
