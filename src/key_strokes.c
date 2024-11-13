/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_strokes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proton <proton@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 18:07:14 by proton            #+#    #+#             */
/*   Updated: 2024/11/13 18:22:47 by proton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
static int close_program(t_mptrs *param)
{
    mlx_destroy_window(param->mlx, param->win_mlx);
    exit(0);
    return(0);
}

int key_press(int keycode,t_mptrs *param)
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