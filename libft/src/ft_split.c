/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bismail <bismail@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 16:00:00 by bismail           #+#    #+#             */
/*   Updated: 2024/10/16 10:50:43 by bismail          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	count_words(const char *str, char dil)
{
	int	count;
	int	f;

	f = 0;
	count = 0;
	while (*str)
	{
		if (*str != dil && !f)
		{
			count++;
			f = 1;
		}
		else if (*str == dil)
			f = 0;
		str++;
	}
	return (count);
}

static size_t	ft_strnlen(char const *s, size_t index, char c)
{
	size_t	i;

	i = 0;
	while (s[index + i] && s[index + i] != c)
		i++;
	return (i);
}

static void	*nulloc(char **word, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		free(word[i]);
		i++;
	}
	free(word);
	return (NULL);
}

static char	*wordy(char const *str, size_t start, size_t end)
{
	char	*word;
	int		i;

	i = 0;
	word = malloc((end - start + 1) * sizeof(char));
	if (!word)
		return (NULL);
	while (start < end)
	{
		word[i] = str[start];
		i++;
		start++;
	}
	word[i] = 0;
	return (word);
}

char	**ft_split(char const *s, char c)
{
	char	**str_ar;
	size_t	index;
	size_t	i;

	str_ar = ft_calloc((count_words(s, c) + 1), sizeof(char *));
	if (!str_ar || !s)
		return (NULL);
	i = 0;
	index = 0;
	while (s[index])
	{
		if (s[index] == c)
		{
			index++;
			continue ;
		}
		str_ar[i] = wordy(s, index, index + ft_strnlen(s, index, c));
		if (!str_ar[i])
			return (nulloc(str_ar, count_words(s, c) + 1));
		index += ft_strnlen(s, index, c) + 1;
		if (ft_strlen(s) < (index))
			break ;
		i++;
	}
	return (str_ar);
}
