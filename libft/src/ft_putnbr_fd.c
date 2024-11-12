/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bismail <bismail@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 16:33:16 by bismail           #+#    #+#             */
/*   Updated: 2024/09/19 11:18:02 by bismail          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	c;

	if (n < 0)
		write(fd, "-", 1);
	if (n < 0 && n > INT_MIN)
		n *= -1;
	if (n > INT_MAX)
		ft_putnbr_fd(INT_MAX, fd);
	else if (n <= INT_MIN)
		ft_putnbr_fd(INT_MAX / 10, fd);
	else if (n > 9)
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putnbr_fd(n % 10, fd);
	}
	else
	{
		c = n + '0';
		write(fd, &c, 1);
	}
	if (n <= INT_MIN)
	{
		c = '8';
		write(fd, &c, 1);
	}
}
