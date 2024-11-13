/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proton <proton@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 18:49:05 by proton            #+#    #+#             */
/*   Updated: 2024/11/13 23:34:24 by proton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include "../minilibx-linux/mlx.h"
#include "../libft/includes/libft.h" 
#include <stdio.h>
#define WIDTH 600
#define HEIGHT 600
#define KEY_CLK 2
#define ESC 65307
#define W 119
#define S 115
#define D 100
#define A 97
#define CLOSE 17

typedef struct  mlx_ptrs
{
    void    *mlx;
    void    *win_mlx;
}   t_mptrs;

typedef struct mlx_map
{
    char  **map;
    int x_wid;
    int y_hei;
}   t_map;
int key_press(int keycode,t_mptrs *param);
int close_program(t_mptrs *param);

#endif