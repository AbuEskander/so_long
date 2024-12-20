/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proton <proton@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 00:14:34 by proton            #+#    #+#             */
/*   Updated: 2024/11/16 13:09:02 by proton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_path(char *path, int *fd)
{
	if (!path || !*path || ft_strncmp((ft_strchr(path, '.')), ".ber", 5))
	{
		*fd = -1;
		display_error("Invalid path");
	}
	else
	{
		*fd = open(path, O_RDONLY);
		if (*fd == -1)
			display_error("Invalid path");
	}
}

static int	check_walls(t_map mapx)
{
	int	rowwise;
	int	ywise;

	rowwise = mapx.x_wid;
	ywise = mapx.y_hei;
	while (rowwise--)
	{
		if (mapx.map[0][rowwise] != '1' || mapx.map[ywise - 1][rowwise] != '1')
		{
			display_error("You have a hole/s in your walls!!");
			return (FAIL);
		}
	}
	while (--ywise)
	{
		if (mapx.map[ywise][0] != '1' || mapx.map[ywise][mapx.x_wid - 1] != '1')
		{
			display_error("You have a hole/s in your walls!!");
			return (FAIL);
		}
	}
	return (SUCCESS);
}

static int	check_shape(t_map mapx)
{
	while (--mapx.y_hei)
	{
		if (ft_strlen(mapx.map[mapx.y_hei]) != (size_t)mapx.x_wid)
		{
			display_error("Not Rectangular");
			return (FAIL);
		}
	}
	return (SUCCESS);
}

int	check_map(t_map *mapx)
{
	if (check_shape(*mapx))
		return (FAIL);
	if (check_walls(*mapx) || check_components(mapx))
		return (FAIL);
	return (SUCCESS);
}
