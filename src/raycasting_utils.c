/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalcara- <aalcara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 21:49:26 by aalcara-          #+#    #+#             */
/*   Updated: 2021/06/17 16:33:14 by aalcara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	ft_drawstartend(t_cub *cub)
{
	if (cub->ray.side == 0)
		cub->ray.perpwalldist = ((double)cub->ray.mapx - \
				cub->ray.posx + (1 - (double)cub->ray.\
				stepx) / 2) / cub->ray.raydirx;
	else
		cub->ray.perpwalldist = ((double)cub->ray.mapy - \
				cub->ray.posy + (1 - (double)cub->ray.\
				stepy) / 2) / cub->ray.raydiry;
	cub->ray.lineheight = (int)(cub->ry / cub->ray.perpwalldist);
	cub->ray.drawstart = -cub->ray.lineheight / 2 + cub->ry / 2;
	if (cub->ray.drawstart < 0)
		cub->ray.drawstart = 0;
	cub->ray.drawend = cub->ray.lineheight / 2 + cub->ry / 2;
	if (cub->ray.drawend >= cub->ry || cub->ray.drawend < 0)
		cub->ray.drawend = cub->ry - 1;
}

void	ft_incrementray(t_cub *cub)
{
	while (cub->ray.hit == 0)
	{
		if (cub->ray.sidedistx < cub->ray.sidedisty)
		{
			cub->ray.sidedistx += cub->ray.deltadistx;
			cub->ray.mapx += cub->ray.stepx;
			cub->ray.side = 0;
		}
		else
		{
			cub->ray.sidedisty += cub->ray.deltadisty;
			cub->ray.mapy += cub->ray.stepy;
			cub->ray.side = 1;
		}
		if (cub->map[cub->ray.mapx][cub->ray.mapy] == '1')
			cub->ray.hit = 1;
	}
	ft_drawstartend(cub);
}

void	ft_stepsidedist(t_cub *cub) 
{
	if (cub->ray.raydirx < 0)
	{
		cub->ray.stepx = -1;
		cub->ray.sidedistx = (cub->ray.posx - cub->ray.mapx) \
							* cub->ray.deltadistx;
	}
	else
	{
		cub->ray.stepx = 1;
		cub->ray.sidedistx = (cub->ray.mapx + 1.0 - cub->ray.posx) \
							* cub->ray.deltadistx;
	}
	if (cub->ray.raydiry < 0)
	{
		cub->ray.stepy = -1;
		cub->ray.sidedisty = (cub->ray.posy - cub->ray.mapy) \
							* cub->ray.deltadisty;
	}
	else
	{
		cub->ray.stepy = 1;
		cub->ray.sidedisty = (cub->ray.mapy + 1.0 - cub->ray.posy) \
							* cub->ray.deltadisty;
	}
	ft_incrementray(cub);
}

void	ft_swap(t_cub *cub)
{
	void	*tmp;

	tmp = cub->data.img;
	cub->data.img = cub->data.img2;
	cub->data.img2 = tmp;
	tmp = cub->data.addr;
	cub->data.addr = cub->data.addr2;
	cub->data.addr2 = tmp;
}
