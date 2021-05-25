/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalcara- <aalcara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 17:14:29 by aalcara-          #+#    #+#             */
/*   Updated: 2021/05/25 08:19:18 by aalcara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	ft_start(char c, t_cub *cub, int i, int j)
{
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
	{
		if (cub->start != 'x')
			cub->multiplayer = 1;
		cub->start = c;
		cub->dx = i;
		cub->dy = j;
		return (1);
	}
	return (0);
}

// murs
