/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proton <proton@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 16:49:44 by proton            #+#    #+#             */
/*   Updated: 2024/11/14 00:21:58 by proton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Disclamer Proton is my Main Laptop :D Writen at 4:50pm 11/13/2024 */
#include "so_long.h"

static void gen_map(int fd , t_map *mapx)
{
	char *total;
	char *tot;
	
	tot = "";
	mapx->y_hei = 0;
	while (1)
	{
		total = get_next_line(fd);
		if(!total)
			break;
		tot = ft_strjoin(tot,total);
		free(total);
		mapx->y_hei++;
	}
	mapx->map = ft_split(tot,'\n');
	mapx->x_wid = ft_strlen(mapx->map[0]);

}

static int	validate(char *path, t_map *mapx)
{
	int	file;

	check_path(path, &file);
	if (file == -1)
		return (1);
	gen_map(file, mapx);
	if (check_map(mapx)) 
		return (1);
	return (0);
}

int main(int argc ,char **argv)
{
	t_mptrs	ptrs;
	t_map	mapx;
	if (argc != 2 || validate(argv[1], &mapx))
	{
		ft_putendl_fd("Invalid input",2);
		return (1);
	}
	while(mapx.y_hei--)
	{
		ft_putendl_fd(mapx.map[mapx.y_hei],1);
	}
	ptrs.mlx = mlx_init();
	ptrs.win_mlx = mlx_new_window(ptrs.mlx,1000,1000,"Just a test");
	mlx_hook(ptrs.win_mlx, CLOSE, 0, close_program, &ptrs);
	mlx_key_hook(ptrs.win_mlx, key_press, &ptrs);
	mlx_loop(ptrs.mlx);
   	return (0);
}
