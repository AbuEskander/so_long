/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bismail <bismail@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 13:33:47 by bismail           #+#    #+#             */
/*   Updated: 2024/09/19 11:17:41 by bismail          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printf(const char *f, ...)
{
	va_list	args;
	int		count;

	va_start(args, f);
	count = ft_check(f, args);
	va_end(args);
	return (count);
}
