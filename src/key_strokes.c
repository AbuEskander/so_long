/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_strokes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proton <proton@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 18:07:14 by proton            #+#    #+#             */
/*   Updated: 2024/11/15 14:21:27 by proton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	close_program(t_mptrs *param)
{
	freesplited(param->map->map, param->map->y_hei);
	freesplited(param->map->tbc, param->map->y_hei);
	mlx_destroy_image(param->mlx, param->walls);
	mlx_destroy_image(param->mlx, param->me);
	mlx_destroy_image(param->mlx, param->bkg);
	mlx_destroy_image(param->mlx, param->coll);
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
