/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalcara- <aalcara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 17:14:29 by aalcara-          #+#    #+#             */
/*   Updated: 2021/05/26 11:15:58 by aalcara-         ###   ########.fr       */
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

int ft_walls_util(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] != '1')
			return (1);
		i++;
	}
	return (0);
}

int	ft_walls(t_cub *cub)
{
	int	i;

	i = 0;
	while (i < cub->nblines)
	{
		if (cub->map[i][0] != '1')
			return (1);
		i++;
	}
	i = 0;
	while (i < cub->nblines)
	{
		if (cub->map[i][cub->sizeline - 1] != '1')
			return (1);
		i++;
	}
	if (ft_walls_util(cub->map[0]) == 1)
		return (1);
	if (ft_walls_util(cub->map[cub->nblines - 1]) == 1)
		return (1);
	return (0);
}
