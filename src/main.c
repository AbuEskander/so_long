/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proton <proton@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 16:49:44 by proton            #+#    #+#             */
/*   Updated: 2024/11/13 18:19:36 by proton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Disclamer Proton is my Main Laptop :D Writen at 4:50 11/13/2024 */
#include "so_long.h"


int main()
{
	t_mptrs	ptrs;
	
	ptrs.mlx = mlx_init();
	ptrs.win_mlx = mlx_new_window(ptrs.mlx,WIDTH,HEIGHT,"Just a test");
	mlx_key_hook(ptrs.win_mlx,&key_press,&ptrs);
	mlx_loop(ptrs.mlx);
   	return (0);
}
