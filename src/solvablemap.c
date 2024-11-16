/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solvablemap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proton <proton@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 16:26:09 by proton            #+#    #+#             */
/*   Updated: 2024/11/16 13:55:21 by proton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	find_position(t_map *mapx)
{
	int	i;
	int	y;

	y = 0;
	while (y < mapx->y_hei)
	{
		i = 0;
		while (i <= mapx->x_wid)
		{
			if (mapx->map[y][i] == 'P')
			{
				mapx->px.x_axis = i;
				mapx->px.y_axis = y;
			}
			i++;
		}
		y++;
	}
}

static void	flood_fill(int x, int y, t_map *mapx)
{
	if (mapx->tbc[y][x] == 'C')
		mapx->cch--;
	else if (mapx->tbc[y][x] == 'E')
		mapx->exch--;
	else if (mapx->tbc[y][x] == '1')
		return ;
	mapx->tbc[y][x] = '1';
	flood_fill(x + 1, y, mapx);
	flood_fill(x - 1, y, mapx);
	flood_fill(x, y + 1, mapx);
	flood_fill(x, y - 1, mapx);
}

int	check_solvable(t_map *mapx)
{
	mapx->cch = mapx->colli;
	mapx->exch = mapx->exit;
	find_position(mapx);
	flood_fill(mapx->px.x_axis, mapx->px.y_axis, mapx);
	if (mapx->cch != 0 || mapx->exch != 0)
	{
		display_error("No valid path to Collect/Finish");
		return (FAIL);
	}
	return (SUCCESS);
}
