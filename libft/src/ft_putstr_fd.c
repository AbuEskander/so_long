/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bismail <bismail@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 16:30:18 by bismail           #+#    #+#             */
/*   Updated: 2024/09/21 14:01:07 by bismail          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putstr_fd(char *s, int fd)
{
	int	count;

	if (s)
	{
		while (*s)
		{
			write(fd, s++, 1);
			count++;
		}
	}
	else
	{
		write(fd, "(null)", 6);
		count = 6;
	}
	return (count);
}
