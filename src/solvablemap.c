/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solvablemap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proton <proton@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 16:26:09 by proton            #+#    #+#             */
/*   Updated: 2024/11/14 19:04:48 by proton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	find_position(t_map *mapx)
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

int	check_solvable(t_map *mapx)
{
	find_position(mapx);
	return (0);
}
