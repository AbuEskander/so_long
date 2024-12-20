/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_components.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proton <proton@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 15:02:45 by proton            #+#    #+#             */
/*   Updated: 2024/11/16 13:08:10 by proton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	check_colli(t_map *mapx)
{
	int	i;
	int	y;

	y = 0;
	while (y < mapx->y_hei)
	{
		i = 0;
		while (i <= mapx->x_wid)
			if (mapx->map[y][i++] == 'C')
				mapx->colli++;
		y++;
	}
	if (mapx->colli == 0)
	{
		display_error("No collectibles");
		return (FAIL);
	}
	return (SUCCESS);
}

static int	check_start_end(t_map *mapx)
{
	int	i;
	int	y;

	y = 0;
	while (y < mapx->y_hei)
	{
		i = 0;
		while (i <= mapx->x_wid)
		{
			if (mapx->map[y][i] == 'E')
				mapx->exit++;
			if (mapx->map[y][i] == 'P')
				mapx->start++;
			i++;
		}
		y++;
	}
	if (mapx->exit != 1 || mapx->start != 1)
	{
		display_error("You don't have exactly one exit or start");
		return (FAIL);
	}
	return (SUCCESS);
}

static int	one_of_us(char c)
{
	if (c == '1' || c == 'P' || c == 'E' || c == '0' || c == 'C' || c == '\0')
		return (SUCCESS);
	return (FAIL);
}

static int	check_no_extra(t_map mapx)
{
	int	i;
	int	y;

	y = 0;
	while (y < mapx.y_hei)
	{
		i = 0;
		while (i <= mapx.x_wid)
		{
			if (one_of_us(mapx.map[y][i++]))
			{
				display_error("Things are not supposed to be here :P");
				return (FAIL);
			}
		}
		y++;
	}
	return (SUCCESS);
}

int	check_components(t_map *mapx)
{
	if (check_colli(mapx) || check_start_end(mapx))
		return (FAIL);
	if (check_no_extra(*mapx))
		return (FAIL);
	return (SUCCESS);
}
