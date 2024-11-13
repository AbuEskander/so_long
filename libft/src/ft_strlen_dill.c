/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen_dill.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proton <proton@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 23:56:37 by proton            #+#    #+#             */
/*   Updated: 2024/11/13 23:59:04 by proton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen_dill(const char *c, char dill)
{
	size_t	len;

	len = 0;
	while (c[len] && c[len] != dill)
		len++;
	return (len);
}