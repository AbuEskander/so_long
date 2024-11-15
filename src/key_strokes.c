/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_strokes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proton <proton@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 18:07:14 by proton            #+#    #+#             */
/*   Updated: 2024/11/15 21:48:34 by proton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_me(t_mptrs *param)
{
	if (param->me_up)
		mlx_destroy_image(param->mlx, param->me_up);
	if (param->me_dn)
		mlx_destroy_image(param->mlx, param->me_dn);
	if (param->me_lft)
		mlx_destroy_image(param->mlx, param->me_lft);
	if (param->me_rt)
		mlx_destroy_image(param->mlx, param->me_rt);
	if (param->walls)
		mlx_destroy_image(param->mlx, param->walls);
	if (param->floor)
		mlx_destroy_image(param->mlx, param->floor);
	if (param->coll)
		mlx_destroy_image(param->mlx, param->coll);
	if (param->exit)
		mlx_destroy_image(param->mlx, param->exit);
}

int	close_program(t_mptrs *param)
{
	freesplited(param->map->map, param->map->y_hei);
	freesplited(param->map->tbc, param->map->y_hei);
	free_me(param);
	mlx_destroy_window(param->mlx, param->win_mlx);
	mlx_destroy_display(param->mlx);
	free(param->mlx);
	exit(0);
}

int	key_press(int keycode, t_mptrs *param)
{
	if (keycode == ESC || param->map->won)
		close_program(param);
	if (keycode == W)
		check_movment(param, param->map->px.x_axis, param->map->px.y_axis - 1);
	if (keycode == S)
		check_movment(param, param->map->px.x_axis, param->map->px.y_axis + 1);
	if (keycode == A)
		check_movment(param, param->map->px.x_axis - 1, param->map->px.y_axis);
	if (keycode == D)
		check_movment(param, param->map->px.x_axis + 1, param->map->px.y_axis);
	free_me(param);
	map_render(param, param->map);
	return (0);
}
