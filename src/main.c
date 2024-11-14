/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proton <proton@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 16:49:44 by proton            #+#    #+#             */
/*   Updated: 2024/11/14 17:46:27 by proton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Disclamer Proton is my Main Laptop :D Writen at 4:50pm 11/13/2024 */
#include "so_long.h"

static void	gen_map(int fd, t_map *mapx)
{
	char	*total;
	char	*tot;
        char    *tmp;

	tot = ft_strdup("");
	mapx->y_hei = 0;
	while (1)
	{
		total = get_next_line(fd);
		if (!total)
			break ;
		tmp = ft_strjoin(tot, total);
                free(tot);
                free(total);
                tot = tmp;
		mapx->y_hei++;
	}
	mapx->map = ft_split(tot, '\n');
	mapx->x_wid = ft_strlen(mapx->map[0]);
	free(tot);
}

static int	validate(char *path, t_map *mapx)
{
	int	file;

	check_path(path, &file);
	if (file == -1)
		return (1);
	gen_map(file, mapx);
	close(file);
	if (check_map(*mapx) || check_solvable(mapx))
	{
		freesplited(mapx->map, mapx->y_hei);
		return (1);
	}
	return (0);
}

static void	init(t_map *mapx)
{
	mapx->y_hei = 0;
	mapx->x_wid = 0;
	mapx->start = 0;
	mapx->exit = 0;
	mapx->px.x_axis = 0;
	mapx->px.y_axis = 0;
	mapx->colli = 0;
}
int	main(int argc, char **argv)
{
	t_mptrs	ptrs;
	t_map	mapx;

	if (argc != 2)
		return (display_error("arguments are not exactly 2"));
	init(&mapx);
	if (validate(argv[1], &mapx))
		return (1);
	ft_printf("Player's x and y (%d,%d)", mapx.px.x_axis, mapx.px.y_axis);
	ptrs.mlx = mlx_init();
	ptrs.map = &mapx;
	ptrs.win_mlx = mlx_new_window(ptrs.mlx, 1000, 1000, "Just a test");
	mlx_hook(ptrs.win_mlx, CLOSE, 0, close_program, &ptrs);
	mlx_key_hook(ptrs.win_mlx, key_press, &ptrs);
	mlx_loop(ptrs.mlx);
	return (0);
}
