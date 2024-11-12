/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_switch.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bismail <bismail@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 15:20:22 by bismail           #+#    #+#             */
/*   Updated: 2024/10/01 10:41:22 by bismail          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_switch(char c, va_list args)
{
	if (c == 'c')
		ft_putchar_fd(va_arg(args, int), 1);
	else if (c == 's')
		return (ft_putstr_fd(va_arg(args, char *), 1));
	else if (c == 'p')
		return ((ft_putpointer_fd((ssize_t)va_arg(args, void *))));
	else if (c == 'd' || c == 'i')
		return (ft_putnum(va_arg(args, int)));
	else if (c == 'x' || c == 'X')
		return (ft_puthex_fd(va_arg(args, unsigned int), c));
	else if (c == '%')
		return (ft_putchar_fd('%', 1));
	else if (c == 'u')
		return (ft_putunsignednbr(va_arg(args, unsigned int)));
	return (1);
}
