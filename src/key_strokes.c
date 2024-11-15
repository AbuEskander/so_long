/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_strokes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proton <proton@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 18:07:14 by proton            #+#    #+#             */
/*   Updated: 2024/11/15 17:38:04 by proton           ###   ########.fr       */
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
}

int	close_program(t_mptrs *param)
{
	freesplited(param->map->map, param->map->y_hei);
	freesplited(param->map->tbc, param->map->y_hei);
	if (param->walls)
		mlx_destroy_image(param->mlx, param->walls);
	if (param->floor)
		mlx_destroy_image(param->mlx, param->floor);
	if (param->coll)
		mlx_destroy_image(param->mlx, param->coll);
	if (param->exit)
		mlx_destroy_image(param->mlx, param->exit);
	free_me(param);
	mlx_destroy_window(param->mlx, param->win_mlx);
	mlx_destroy_display(param->mlx);
	free(param->mlx);
	exit(0);
}

int	key_press(int keycode, t_mptrs *param)
{
	if (keycode == ESC)
		close_program(param);
	if (keycode == W)
		ft_printf("UP\n");
	if (keycode == S)
		ft_printf("DOWN\n");
	if (keycode == A)
		ft_printf("RIGHT\n");
	if (keycode == D)
		ft_printf("LEFT\n");
	return (0);
}
