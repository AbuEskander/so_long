/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proton <proton@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 00:14:34 by proton            #+#    #+#             */
/*   Updated: 2024/11/14 00:24:50 by proton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void check_path(char *path, int *fd)
{
    if(!path || !*path || !ft_strnstr(path,".ber",ft_strlen(path)))
        *fd = -1;
    else
        *fd = open(path,O_RDONLY);
}

int check_map(t_map mapx)
{
    if(!mapx.x_wid || !map.y_hei)
        return (1);
}