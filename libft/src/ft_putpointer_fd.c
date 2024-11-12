/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putpointer_fd.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bismail <bismail@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 17:29:20 by bismail           #+#    #+#             */
/*   Updated: 2024/09/19 11:18:11 by bismail          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putpointer_fd(size_t hex)
{
	if (hex)
	{
		ft_putstr_fd("0x", 1);
		return (ft_puthex_fd(hex, 'x') + 2);
	}
	else
		return (ft_putstr_fd("(nil)", 1));
}
