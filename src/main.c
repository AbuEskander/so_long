/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proton <proton@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 16:49:44 by proton            #+#    #+#             */
/*   Updated: 2024/11/13 22:45:25 by proton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Disclamer Proton is my Main Laptop :D Writen at 4:50pm 11/13/2024 */
#include "so_long.h"

// static intvalidate(char *path)

int main(int argc ,char **argv)
{
	(void)argv;
	(void)argc;
	t_mptrs	ptrs;
	
	// if (argc != 2 || validate(argv[1]))
	// {
	// 	perror("Invalid input");
	// 	exit(1);
	// }
	
	ptrs.mlx = mlx_init();
	ptrs.win_mlx = mlx_new_window(ptrs.mlx,1000,1000,"Just a test");
	mlx_key_hook(ptrs.win_mlx,key_press,&ptrs);
	mlx_loop(ptrs.mlx);
   	return (0);
}
