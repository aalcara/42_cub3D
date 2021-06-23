/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_init.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalcara- <aalcara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 19:07:15 by aalcara-          #+#    #+#             */
/*   Updated: 2021/06/22 20:09:06 by aalcara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	ft_init_dir(t_cub *cub)
{
	if (cub->start == 'N')
		cub->ray.dirx = -1;
	if (cub->start == 'S')
		cub->ray.dirx = 1;
	if (cub->start == 'E')
		cub->ray.diry = 1;
	if (cub->start == 'W')
		cub->ray.diry = -1;
	if (cub->start == 'N')
		cub->ray.plany = 0.66;
	if (cub->start == 'S')
		cub->ray.plany = -0.66;
	if (cub->start == 'E')
		cub->ray.planx = 0.66;
	if (cub->start == 'W')
		cub->ray.planx = -0.66;
}

/*
init raycasting variables
*/
void	ft_init_mlx(t_cub *cub)
{
	cub->s.zbuffer = (double *)malloc(sizeof(double) * cub->rx);
	if (!cub->s.zbuffer)
		exit(0);
	cub->data.forward = 0;
	cub->data.back = 0;
	cub->data.left = 0;
	cub->data.right = 0;
	cub->data.rotate_left = 0;
	cub->data.rotate_right = 0;
	cub->ray.posx = (double)cub->dx + 0.5;
	cub->ray.posy = (double)cub->dy + 0.5;
	cub->ray.dirx = 0;
	cub->ray.diry = 0;
	cub->ray.planx = 0;
	cub->ray.plany = 0;
	ft_init_dir(cub);
}

void	ft_init_ray2(t_cub *cub)
{
	if (cub->ray.raydiry == 0)
		cub->ray.deltadistx = 0;
	else if (cub->ray.raydirx == 0)
		cub->ray.deltadistx = 1;
	else
		cub->ray.deltadistx = sqrt(1 + (cub->ray.raydiry * cub->ray.raydiry) \
				/ (cub->ray.raydirx * cub->ray.raydirx));
	if (cub->ray.raydirx == 0)
		cub->ray.deltadisty = 0;
	else if (cub->ray.raydiry == 0)
		cub->ray.deltadisty = 1;
	else
		cub->ray.deltadisty = sqrt(1 + (cub->ray.raydirx * cub->ray.raydirx) \
				/ (cub->ray.raydiry * cub->ray.raydiry));
}

void	ft_init_ray(t_cub *cub)
{
	cub->ray.hit = 0;
	cub->ray.perpwalldist = 0;
	cub->ray.camerax = 2 * cub->ray.x / (double)cub->rx - 1;
	cub->ray.raydirx = cub->ray.dirx + cub->ray.planx * cub->ray.camerax;
	cub->ray.raydiry = cub->ray.diry + cub->ray.plany * cub->ray.camerax;
	cub->ray.mapx = (int)cub->ray.posx;
	cub->ray.mapy = (int)cub->ray.posy;
	cub->ray.movespeed = 0.1;
	cub->ray.rotspeed = 0.033 * 1.8;
	ft_init_ray2(cub);
}
