/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bismail <bismail@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 14:07:26 by bismail           #+#    #+#             */
/*   Updated: 2024/09/19 11:15:11 by bismail          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_check(const char *f, va_list args)
{
	int	count;

	count = 0;
	while (*f)
	{
		if (*f != '%')
		{
			ft_putchar_fd(*f, 1);
			count++;
		}
		else
			count += ft_switch(*++f, args);
		f++;
	}
	return (count);
}
