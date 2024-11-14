/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freesplit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proton <proton@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 10:57:24 by bismail           #+#    #+#             */
/*   Updated: 2024/11/14 15:51:59 by proton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	freesplited(char **splited, int count_words)
{
	while (count_words--)
		free(splited[count_words]);
	free(splited);
}
