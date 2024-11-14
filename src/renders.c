/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renders.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proton <proton@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 20:27:04 by proton            #+#    #+#             */
/*   Updated: 2024/11/14 22:07:07 by proton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	put_map(t_mptrs *ptrs, t_map *mapx)
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
			if (mapx->map[j][i] == '0' || mapx->map[j][i] == 'C')
				mlx_put_image_to_window(ptrs->mlx, ptrs->win_mlx, ptrs->bkg,
					IMGSIZE * i, IMGSIZE * j);
			if (mapx->map[j][i] == 'P')
				mlx_put_image_to_window(ptrs->mlx, ptrs->win_mlx, ptrs->me,
					IMGSIZE * i, IMGSIZE * j);
			if (mapx->map[j][i] == 'C')
				mlx_put_image_to_window(ptrs->mlx, ptrs->win_mlx, ptrs->coll,
					IMGSIZE * i, IMGSIZE * j);
			i++;
		}
		j++;
	}
}

void	map_render(t_mptrs *ptrs, t_map *mapx)
{
	int	size;
	int	char_size;

	size = 64;
	char_size = 128;
	ptrs->walls = mlx_xpm_file_to_image(ptrs->mlx, WALLS, &size, &size);
	ptrs->bkg = mlx_xpm_file_to_image(ptrs->mlx, BACKGROUND, &size, &size);
	ptrs->coll = mlx_xpm_file_to_image(ptrs->mlx, COLLECT, &size, &size);
	ptrs->me = mlx_xpm_file_to_image(ptrs->mlx, CHAR, &char_size, &char_size);
	put_map(ptrs, mapx);
}
