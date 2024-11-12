/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bismail <bismail@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 16:33:14 by bismail           #+#    #+#             */
/*   Updated: 2024/09/19 11:17:57 by bismail          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_totallen(size_t num)
{
	int	count;

	count = 0;
	while (num != 0)
	{
		count++;
		num /= 16;
	}
	return (count);
}

void	ft_puthexf_fd(size_t hex, const char uos)
{
	if (hex >= 16)
	{
		ft_puthexf_fd(hex / 16, uos);
		ft_puthexf_fd(hex % 16, uos);
	}
	else
	{
		if (hex < 10)
			ft_putnbr_fd(hex, 1);
		else
		{
			if (uos == 'x')
				ft_putchar_fd(hex - 10 + 'a', 1);
			if (uos == 'X')
				ft_putchar_fd(hex - 10 + 'A', 1);
		}
	}
}

int	ft_puthex_fd(size_t hex, const char uos)
{
	if (hex == 0)
		return (ft_putchar_fd('0', 1));
	ft_puthexf_fd(hex, uos);
	return (ft_totallen(hex));
}
