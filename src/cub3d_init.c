/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalcara- <aalcara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 10:20:50 by aalcara-          #+#    #+#             */
/*   Updated: 2021/05/26 13:20:37 by aalcara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	ft_init_geral2(t_cub *cub)
{
	cub->start = 'x';
	cub->indic2 = 0;
	cub->indic3 = 0;
	cub->data.img = NULL;
	cub->texture[0].img = NULL;
	cub->texture[1].img = NULL;
	cub->texture[2].img = NULL;
	cub->texture[3].img = NULL;
	cub->texture[4].img = NULL;
	cub->data.mlx_win = NULL;
	cub->map = NULL;
	cub->s.order = NULL;
	cub->s.dist = NULL;
	cub->s.zbuffer = NULL;
	cub->sxy = NULL;
}

void	ft_init_geral(t_cub *cub)
{
	cub->no = NULL;
	cub->so = NULL;
	cub->we = NULL;
	cub->ea = NULL;
	cub->sp = NULL;
	cub->f = -1;
	cub->c = -1;
	cub->rx = 0;
	cub->ry = 0;
	cub->nblines = 0;
	cub->sizeline = 0;
	cub->map = NULL;
	cub->dx = 0;
	cub->dy = 0;
	cub->multiplayer = 0;
	cub->emptyline = 0;
	cub->insidemap = 0;
	cub->count = 0;
	cub->sum = 0;
	cub->wrongcharmap = 0;
	ft_init_geral2(cub);
}
