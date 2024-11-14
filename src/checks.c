/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proton <proton@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 00:14:34 by proton            #+#    #+#             */
/*   Updated: 2024/11/14 14:39:39 by proton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_path(char *path, int *fd)
{
	if (!path || !*path || !ft_strnstr(path, ".ber", ft_strlen(path)))
		*fd = -1;
	else
		*fd = open(path, O_RDONLY);
}

static int	check_walls(t_map mapx)
{
	int	rowwise;
	int	ywise;

	rowwise = mapx.x_wid;
	ywise = mapx.y_hei;
	while (rowwise--)
		if (mapx.map[0][rowwise] != '1' || mapx.map[ywise - 1][rowwise] != '1')
			return (1);
	while (--ywise)
		if (mapx.map[ywise][0] != '1' || mapx.map[ywise][mapx.x_wid - 1] != '1')
			return (1);
	return (0);
}
static int	check_shape(t_map mapx)
{
	while (--mapx.y_hei)
		if (ft_strlen(mapx.map[mapx.y_hei]) != (size_t)mapx.x_wid)
			return (1);
	return (0);
}

static int	check_components(t_map mapx)
{
	int	i;
	int	j;
	
	mapx.px.x_axis = 0;
	mapx.px.y_axis = 0;
	mapx.colli = 0;
	mapx.start = 0;
	mapx.end = 0;
	
}

int	check_map(t_map mapx)
{
	if (check_shape(mapx))
		return (1);
	if (check_walls(mapx) || check_components(mapx))
		return (1);
	return (0);
}
