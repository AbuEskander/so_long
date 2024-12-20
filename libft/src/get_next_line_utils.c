/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proton <proton@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 08:49:33 by bismail           #+#    #+#             */
/*   Updated: 2024/11/13 23:16:43 by proton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*handle_free(char **total, int cas)
{
	char	*ret;

	if (cas == -1)
	{
		if (*total && total)
		{
			free(*total);
			*total = NULL;
		}
		return (NULL);
	}
	if (cas == 0)
	{
		ret = ft_strdup(*total);
		if (!ret)
			return (NULL);
		if (*total)
		{
			free(*total);
			*total = NULL;
		}
		return (ret);
	}
	return (NULL);
}
