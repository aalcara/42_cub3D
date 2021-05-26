/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalcara- <aalcara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 19:09:10 by aalcara-          #+#    #+#             */
/*   Updated: 2021/05/26 11:16:37 by aalcara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	ft_verify_errors(t_cub *cub)
{
	if (ft_walls(cub) == 1)
		ft_error(cub, "Map not surrounded by 1\n");
	if (cub->start == 'x')
		ft_error(cub, "Not finded the player\n");
	if (cub->indic2 != 6)
		ft_error(cub, "F or C has bad data\n");
	if (cub->multiplayer == 1)
		ft_error(cub, "More than one player\n");
	if (cub->emptyline == 1)
		ft_error(cub, "Empty line inside map\n");
	if (cub->wrongcharmap == 2)
		ft_error(cub, "Incorrect char in map\n");
}

void	ft_error2(t_cub *cub)
{
	if (cub->map)
		free(cub->map);
	if (cub->s.order)
		free(cub->s.order);
	if (cub->s.dist)
		free(cub->s.dist);
	if (cub->sxy)
		free(cub->sxy);
	if (cub->s.zbuffer)
		free(cub->s.zbuffer);
	ft_exit(cub);
}

void	ft_error(t_cub *cub, char *str)
{
	int	i;

	i = -1;
	cub->indic3 = 1;
	write(1, "Error\n", 6);
	write(1, str, ft_strlen(str));
	if (cub->no)
		free(cub->no);
	if (cub->so)
		free(cub->so);
	if (cub->we)
		free(cub->we);
	if (cub->ea)
		free(cub->ea);
	if (cub->sp)
		free(cub->sp);
	if (cub->map)
	{
		while (++i < cub->nblines)
			free(cub->map[i]);
	}
	ft_error2(cub);
}
