/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renders.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proton <proton@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 20:27:04 by proton            #+#    #+#             */
/*   Updated: 2024/11/18 14:06:24 by proton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	put_map(t_mptrs *ptrs, t_map *mapx, int side)
{
	put_walls(ptrs, mapx);
	put_floor(ptrs, mapx);
	put_colli(ptrs, mapx);
	put_me(ptrs, mapx, side);
}

int	render_me(t_mptrs *ptrs, int size)
{
	ptrs->me_up = mlx_xpm_file_to_image(ptrs->mlx, LOOKUP, &size, &size);
	if (!ptrs->me_up)
		return (1);
	ptrs->me_dn = mlx_xpm_file_to_image(ptrs->mlx, LOOKDN, &size, &size);
	if (!ptrs->me_dn)
		return (1);
	ptrs->me_lft = mlx_xpm_file_to_image(ptrs->mlx, LOOKLFT, &size, &size);
	if (!ptrs->me_lft)
		return (1);
	ptrs->me_rt = mlx_xpm_file_to_image(ptrs->mlx, LOOKRT, &size, &size);
	if (!ptrs->me_rt)
		return (1);
	return (0);
}

int	map_render(t_mptrs *ptrs, t_map *mapx, int side)
{
	int	size;

	size = 32;
	if (!ptrs->mlx || !ptrs->win_mlx)
		return (FAIL);
	ptrs->walls = mlx_xpm_file_to_image(ptrs->mlx, WALLS, &size, &size);
	if (!ptrs->walls)
		return (FAIL);
	ptrs->floor = mlx_xpm_file_to_image(ptrs->mlx, FLOOR, &size, &size);
	if (!ptrs->floor)
		return (FAIL);
	ptrs->coll = mlx_xpm_file_to_image(ptrs->mlx, COLLI, &size, &size);
	if (!ptrs->coll)
		return (FAIL);
	ptrs->exit = mlx_xpm_file_to_image(ptrs->mlx, EXIT, &size, &size);
	if (!ptrs->exit)
		return (FAIL);
	if (render_me(ptrs, size))
		return (FAIL);
	put_map(ptrs, mapx, side);
	return (SUCCESS);
}
