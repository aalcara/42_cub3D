/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalcara- <aalcara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 17:42:38 by aalcara-          #+#    #+#             */
/*   Updated: 2021/05/25 17:14:39 by aalcara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	ft_init_sprite(t_cub *cub)
{
	int	i;
	int	j;

	i = -1;
	cub->s.nbspr = 0;
	ft_verify_errors(cub); // ! c************************************************
	while (++i < cub->nblines)
	{
		j = -1;
		while (++j < cub->sizeline)
		{
			if (cub->map[i][j] == '2')
				cub->s.nbspr += 1;
		}
	}
	cub->sxy = (t_sprxy *)malloc(sizeof(t_sprxy) * cub->s.nbspr);
	if (!cub->sxy)
		ft_error(cub, "Malloc sxy*"); // ! c*************************************
	cub->s.order = (int *)malloc(sizeof(int) * cub->s.nbspr);
	if (!cub->s.order)
		ft_error(cub, "Malloc s.order*");
	if (!(cub->s.dist = (double *)malloc(sizeof(double) * cub->s.nbspr)))
		ft_error(cub, "Malloc s.dist*");
	ft_init_sprite2(cub, 0, 0, 0);
	ft_mlx(cub);
}

void	ft_init_sprite2(t_cub *cub, int i, int j, int v)
{
	i = i - 1;
	while (++i < cub->nblines)
	{
		j = -1;
		while (++j < cub->sizeline)
		{
			if (cub->map[i][j] == '2')
			{
				cub->sxy[v].x = (double)i + 0.5;
				cub->sxy[v].y = (double)j + 0.5;
				v++;
			}
		}
	}
}
