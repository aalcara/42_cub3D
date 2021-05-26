/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalcara- <aalcara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 17:18:55 by aalcara-          #+#    #+#             */
/*   Updated: 2021/05/25 19:21:54 by aalcara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	ft_dist_order2(t_cub *cub)
{
	int	i;

	i = -1;
	while (++i < cub->s.nbspr)
	{
		cub->s.order[i] = i;
		cub->s.dist[i] = ((cub->ray.posx - cub->sxy[i].x) * \
				(cub->ray.posx - cub->sxy[i].x) + (cub->ray.posy - \
					cub->sxy[i].y) * (cub->ray.posy - cub->sxy[i].y));
	}
}

void	ft_dist_order(t_cub *cub)
{
	int		i;
	int		j;
	double	tmp;

	ft_dist_order2(cub);
	i = -1;
	while (++i < cub->s.nbspr)
	{
		j = -1;
		while(++j < cub->s.nbspr - 1)
		{
			if (cub->s.dist[j] < cub->s.dist[j + 1])
			{
				tmp = cub->s.dist[j];
				cub->s.dist[j] = cub->s.dist[j + 1];
				cub->s.dist[j + 1] = tmp;
				tmp = cub->s.order[j];
				cub->s.order[j] = cub->s.order[j + 1];
				cub->s.order[j + 1] = (int)tmp;
			}
		}
	}
}

void	ft_calculs(t_cub *cub, int i)
{
	cub->s.spritex = cub->sxy[cub->s.order[i]].x - cub->ray.posx;
	cub->s.spritey = cub->sxy[cub->s.order[i]].y - cub->ray.posy;
	cub->s.invdet = 1.0 / (cub->ray.planx * cub->ray.diry - cub->ray.dirx * \
			cub->ray.plany);
	cub->s.transformx = cub->s.invdet * (cub->ray.diry * \
			cub->s.spritex - cub->ray.dirx * cub->s.spritey);
	cub->s.transformy = cub->s.invdet * (-cub->ray.plany * \
			cub->s.spritex + cub->ray.planx * cub->s.spritey);
	cub->s.spritescreenx = (int)((cub->rx / 2) * (1+ cub->s.transformx / \
			cub->s.transformy));
	cub->s.spriteheight = abs((int)(cub->ry / (cub->s.transformy)));
	cub->s.drawstarty = -cub->s.spriteheight / 2 + cub->ry / 2;
	if (cub->s.drawstarty < 0)
		cub->s.drawstarty = 0;
	cub->s.drawendy = cub->s.spriteheight / 2 + cub->ry / 2;
	if (cub->s.drawendy >= cub->ry)
		cub->s.drawendy = cub->ry;
	cub->s.spritewidth = abs((int)(cub->ry / (cub->s.transformy)));
	cub->s.drawstartx = -cub->s.spritewidth / 2 + cub->s.spritescreenx;
	if (cub->s.drawstartx < 0)
		cub->s.drawstartx = 0;
	cub->s.drawendx = cub->s.spritewidth / 2 + cub->s.spritescreenx;
	if (cub->s.drawendx >= cub->rx)
		cub->s.drawendx = cub->rx;
}

void	ft_draw_spr(t_cub *cub, int y, int texx, int stripe)
{
	int	d;
	int	texy;

	while (y < cub->s.drawendy)
	{
		d = (y) * 256 - cub->ry * 128 + cub->s.spriteheight * 128;
		texy = ((d * cub->texture[4].height) / cub->s.spriteheight) / 256;
		if (cub->texture[4].addr[texy * cub->texture[4].line_length / 4 + \
				texx] != - 16777216)
		{
			cub->data.addr[y * cub->data.line_length / 4 + stripe] = \
				cub->texture[4].addr[texy * cub->texture[4].line_length / \
				4 + texx];
		}
		y++;
	}
}

void	ft_sprite(t_cub *cub)
{
	int	i;
	int	y;
	int	stripe;
	int	texx;

	i = -1;
	ft_dist_order(cub);
	while (++i < cub->s.nbspr)
	{
		ft_calculs(cub, i);
		stripe = cub->s.drawstartx;
		while (stripe < cub->s.drawendx)
		{
			texx = (int)(256 * (stripe - (-cub->s.spritewidth / 2 + \
					cub->s.spritescreenx)) * cub->texture[4].width \
					/ cub->s.spritewidth) / 256;
			if (cub->s.transformy > 0 && stripe >= 0 && stripe < cub->rx \
					&& cub->s.transformy < cub->s.zbuffer[stripe])
			{
				y = cub->s.drawstarty;
				ft_draw_spr(cub, y, texx, stripe);
			}
			stripe++;
		}
	}
}
