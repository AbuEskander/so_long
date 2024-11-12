/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsignednbr.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bismail <bismail@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 18:24:57 by bismail           #+#    #+#             */
/*   Updated: 2024/09/19 11:18:22 by bismail          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	put_u_nbr_fd(unsigned int n, int fd)
{
	char	c;

	if (n > UINT_MAX)
		put_u_nbr_fd(UINT_MAX, fd);
	else if (n > 9)
	{
		put_u_nbr_fd(n / 10, fd);
		put_u_nbr_fd(n % 10, fd);
	}
	else
	{
		c = n + '0';
		write(fd, &c, 1);
	}
}

int	ft_putunsignednbr(unsigned int num)
{
	put_u_nbr_fd(num, 1);
	return (total_len(num));
}
