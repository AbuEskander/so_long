/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bismail <bismail@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 12:09:53 by bismail           #+#    #+#             */
/*   Updated: 2024/09/19 11:14:53 by bismail          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>

static char	*init(int *min, int *len, int n, int *sign)
{
	*min = 0;
	*len = total_len(n);
	*sign = 0;
	return (ft_calloc((*len + 1), sizeof(char)));
}

char	*ft_itoa(int n)
{
	int		sign;
	char	*final;
	int		i;
	int		min;

	if (n == INT_MIN)
		return (ft_strdup("-2147483648"));
	final = init(&min, &i, n, &sign);
	if (!final)
		return (NULL);
	final[0] = '0';
	if (n < 0)
	{
		sign = -1;
		n *= -1;
	}
	while (i > 0)
	{
		final[i - 1] = (n % 10) + '0';
		i--;
		n /= 10;
	}
	if (sign == -1)
		final[i] = '-';
	return (final);
}
