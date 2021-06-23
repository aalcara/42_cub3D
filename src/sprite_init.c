/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalcara- <aalcara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 17:42:38 by aalcara-          #+#    #+#             */
/*   Updated: 2021/06/23 14:10:30 by aalcara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

/*
- Call ft_verify_errors;
- alocate memory for sprites data (cub.sxy, cub,s.order, cub.s.dist).
*/
void	ft_init_sprite(t_cub *cub)
{
	int	i;
	int	j;

	i = -1;
	cub->s.nbspr = 0;
	ft_verify_errors(cub);
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
		ft_error(cub, "Malloc sxy*");
	cub->s.order = (int *)malloc(sizeof(int) * cub->s.nbspr);
	if (!cub->s.order)
		ft_error(cub, "Malloc s.order*");
	ft_init_sprite2(cub, 0, 0, 0);
	ft_mlx(cub);
}

/*
Set the position of sprites.
*/
void	ft_init_sprite2(t_cub *cub, int i, int j, int v)
{
	cub->s.dist = (double *)malloc(sizeof(double) * cub->s.nbspr);
	if (!cub->s.dist)
		ft_error(cub, "Malloc s.dist*");
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
