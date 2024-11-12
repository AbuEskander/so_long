/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_words.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bismail <bismail@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 10:50:48 by bismail           #+#    #+#             */
/*   Updated: 2024/10/17 10:43:35 by bismail          ###   ########.fr       */
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
