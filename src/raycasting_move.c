/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_move.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalcara- <aalcara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 19:25:08 by aalcara-          #+#    #+#             */
/*   Updated: 2021/06/22 20:09:33 by aalcara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	ft_forward_back(t_cub *cub)
{
	if (cub->data.forward == 1)
	{
		if (cub->map[(int)(cub->ray.posx + (cub->ray.dirx * cub->ray.movespeed \
					* 2))][(int)cub->ray.posy] == '0')
			cub->ray.posx += cub->ray.dirx * cub->ray.movespeed;
		if (cub->map[(int)(cub->ray.posx)][(int)(cub->ray.posy + \
					(cub->ray.diry * cub->ray.movespeed * 2))] == '0')
			cub->ray.posy += cub->ray.diry * cub->ray.movespeed;
	}
	if (cub->data.back == 1)
	{
		if (cub->map[(int)(cub->ray.posx - (cub->ray.dirx * cub->ray.movespeed \
					* 2))][(int)cub->ray.posy] == '0')
			cub->ray.posx -= cub->ray.dirx * cub->ray.movespeed;
		if (cub->map[(int)(cub->ray.posx)][(int)(cub->ray.posy - \
					(cub->ray.diry * cub->ray.movespeed * 2))] == '0')
			cub->ray.posy -= cub->ray.diry * cub->ray.movespeed;
	}
}

void	ft_left_right(t_cub *cub)
{
	if (cub->data.right == 1)
	{
		if (cub->map[(int)(cub->ray.posx + cub->ray.diry * \
					(cub->ray.movespeed * 2))][(int)cub->ray.posy] == '0')
			cub->ray.posx += cub->ray.diry * cub->ray.movespeed;
		if (cub->map[(int)(cub->ray.posx)][(int)(cub->ray.posy - \
					cub->ray.dirx * (cub->ray.movespeed * 2))] == '0')
			cub->ray.posy -= cub->ray.dirx * cub->ray.movespeed;
	}
	if (cub->data.left == 1)
	{
		if (cub->map[(int)(cub->ray.posx - cub->ray.diry * \
					(cub->ray.movespeed * 2))][(int)cub->ray.posy] == '0')
			cub->ray.posx -= cub->ray.diry * cub->ray.movespeed;
		if (cub->map[(int)(cub->ray.posx)][(int)(cub->ray.posy + \
					cub->ray.dirx * (cub->ray.movespeed * 2))] == '0')
			cub->ray.posy += cub->ray.dirx * cub->ray.movespeed;
	}
}

void	ft_rotate_left(t_cub *cub, double olddirx)
{
	double	oldplanex;

	if (cub->data.rotate_left == 1)
	{
		olddirx = cub->ray.dirx;
		oldplanex = cub->ray.planx;
		cub->ray.dirx = cub->ray.dirx * cos(cub->ray.rotspeed / 2) - \
			cub->ray.diry * sin(cub->ray.rotspeed / 2);
		cub->ray.diry = olddirx * sin(cub->ray.rotspeed / 2) + \
			cub->ray.diry * cos(cub->ray.rotspeed / 2);
		cub->ray.planx = cub->ray.planx * cos(cub->ray.rotspeed / 2) - \
			cub->ray.plany * sin(cub->ray.rotspeed / 2);
		cub->ray.plany = oldplanex * sin(cub->ray.rotspeed / 2) + \
			cub->ray.plany * cos(cub->ray.rotspeed / 2);
	}
}

void	ft_rotate_right_left(t_cub *cub)
{
	double	oldplanx;
	double	olddirx;

	oldplanx = cub->ray.planx;
	olddirx = cub->ray.dirx;
	if (cub->data.rotate_right == 1)
	{
		cub->ray.dirx = cub->ray.dirx * cos(-cub->ray.rotspeed / 2) - \
			cub->ray.diry * sin(-cub->ray.rotspeed / 2);
		cub->ray.diry = olddirx * sin(-cub->ray.rotspeed / 2) + \
			cub->ray.diry * cos(-cub->ray.rotspeed / 2);
		cub->ray.planx = cub->ray.planx * cos(-cub->ray.rotspeed / 2) - \
			cub->ray.plany * sin(-cub->ray.rotspeed / 2);
		cub->ray.plany = oldplanx * sin(-cub->ray.rotspeed / 2) + \
			cub->ray.plany * cos(-cub->ray.rotspeed / 2);
	}
	ft_rotate_left(cub, olddirx);
}
