/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proton <proton@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 16:50:51 by proton            #+#    #+#             */
/*   Updated: 2024/11/15 19:03:40 by proton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_walls(t_mptrs *ptrs, t_map *mapx)
{
	int	i;
	int	j;

	j = 0;
	while (j < mapx->y_hei)
	{
		i = 0;
		while (i < mapx->x_wid)
		{
			if (mapx->map[j][i] == '1')
				mlx_put_image_to_window(ptrs->mlx, ptrs->win_mlx, ptrs->walls,
					IMGSIZE * i, IMGSIZE * j);
			i++;
		}
		j++;
	}
}

void	put_colli(t_mptrs *ptrs, t_map *mapx)
{
	int	i;
	int	j;

	j = 0;
	while (j < mapx->y_hei)
	{
		i = 0;
		while (i < mapx->x_wid)
		{
			if (mapx->map[j][i] == 'C')
				mlx_put_image_to_window(ptrs->mlx, ptrs->win_mlx, ptrs->coll,
					IMGSIZE * i, IMGSIZE * j);
			i++;
		}
		j++;
	}
}

void	put_floor(t_mptrs *ptrs, t_map *mapx)
{
	int	i;
	int	j;

	j = 0;
	while (j < mapx->y_hei)
	{
		i = 0;
		while (i < mapx->x_wid)
		{
			if (mapx->map[j][i] == '0' || mapx->map[j][i] == 'C'
				|| mapx->map[j][i] == 'P' || mapx->map[j][i] == 'E')
				mlx_put_image_to_window(ptrs->mlx, ptrs->win_mlx, ptrs->floor,
					IMGSIZE * i, IMGSIZE * j);
			i++;
		}
		j++;
	}
}

void	put_me(t_mptrs *ptrs, t_map *mapx)
{
	int	i;
	int	j;

	j = 0;
	while (j < mapx->y_hei)
	{
		i = 0;
		while (i < mapx->x_wid)
		{
			if (i == mapx->px.x_axis && j == mapx->px.y_axis)
				mlx_put_image_to_window(ptrs->mlx, ptrs->win_mlx, ptrs->me_up,
					IMGSIZE * i, IMGSIZE * j);
			if (mapx->map[j][i] == 'E')
				mlx_put_image_to_window(ptrs->mlx, ptrs->win_mlx, ptrs->exit,
					IMGSIZE * i, IMGSIZE * j);
			i++;
		}
		j++;
	}
}
