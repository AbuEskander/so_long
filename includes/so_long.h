/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proton <proton@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 18:49:05 by proton            #+#    #+#             */
/*   Updated: 2024/11/15 17:36:57 by proton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/includes/libft.h"
# include "../minilibx-linux/mlx.h"
# include <stdio.h>
# define WIDTH 600
# define HEIGHT 600
# define KEY_CLK 2
# define ESC 65307
# define W 119
# define S 115
# define D 100
# define A 97
# define CLOSE 17
# define IMGSIZE 32
# define WALLS "Assets/Walls.xpm"
# define FLOOR "Assets/floor.xpm"
# define COLLI "Assets/Collectables.xpm"
# define LOOKUP "Assets/idle_up.xpm"
# define LOOKDN "Assets/idle_down.xpm"
# define LOOKLFT "Assets/idle_left.xpm"
# define LOOKRT "Assets/idle_right.xpm"
# define EXIT "Assets/exit.xpm"

typedef struct player
{
	int		x_axis;
	int		y_axis;
}			t_playx;

typedef struct mlx_map
{
	char	**map;
	char	**tbc;
	int		x_wid;
	int		y_hei;
	int		exit;
	int		start;
	int		colli;
	int		cch;
	int		exch;
	t_playx	px;
}			t_map;
typedef struct mlx_ptrs
{
	void	*mlx;
	void	*win_mlx;
	t_map	*map;
	void	*walls;
	void	*floor;
	void	*me_up;
	void	*me_dn;
	void	*me_lft;
	void	*me_rt;
	void	*exit;
	void	*coll;
}			t_mptrs;

int			key_press(int keycode, t_mptrs *param);
int			close_program(t_mptrs *param);
void		check_path(char *path, int *fd);
int			check_map(t_map *mapx);
int			check_components(t_map *mapx);
int			display_error(char *err);
int			check_solvable(t_map *mapx);
int			map_render(t_mptrs *ptrs, t_map *mapx);
void		put_walls(t_mptrs *ptrs, t_map *mapx);
void		put_floor(t_mptrs *ptrs, t_map *mapx);
void		put_colli(t_mptrs *ptrs, t_map *mapx);
void		put_me(t_mptrs *ptrs, t_map *mapx);

#endif