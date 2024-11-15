/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_movement.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proton <proton@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 20:01:01 by proton            #+#    #+#             */
/*   Updated: 2024/11/15 21:51:17 by proton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	found_colli(t_mptrs *ptrs, int x, int y)
{
	ptrs->map->map[y][x] = '0';
	ptrs->map->colli--;
}

static void	found_exit(t_mptrs *ptrs)
{
	if (ptrs->map->colli == 0)
	{
		ft_printf("YOU WON!!\n");
		ptrs->map->won = 1;
	}
	else
		ft_printf("Bruh Find the last Collect\n");
}

void	check_movment(t_mptrs *ptrs, int x, int y)
{
	static int	counter = 0;

	if (ptrs->map->won)
		return ;
	if (x > (ptrs->map->x_wid - 2) || y > (ptrs->map->y_hei - 2))
		return ;
	if (x <= 0 || y <= 0)
		return ;
	if (ptrs->map->map[y][x] == '1')
		return ;
	ptrs->map->px.x_axis = x;
	ptrs->map->px.y_axis = y;
	ft_printf("Number of movment so far: %d \n", ++counter);
	if (ptrs->map->map[y][x] == 'C')
		found_colli(ptrs, x, y);
	if (ptrs->map->map[y][x] == 'E')
		found_exit(ptrs);
}
