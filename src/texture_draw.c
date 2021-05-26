/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_draw.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalcara- <aalcara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 10:31:59 by aalcara-          #+#    #+#             */
/*   Updated: 2021/05/25 16:40:42 by aalcara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	ft_draw_texture(t_cub *cub, int x, int y)
{
	y = cub->ray.drawstart - 1;
	ft_init_texture(cub);
	cub->t.step = 1.0 * cub->texture[0].height / cub->ray.lineheight;
	cub->t.texx = (int)(cub->t.wallx * (double)cub->texture\
			[cub->t.texdir].width);
	if (cub->ray.side == 0 && cub->ray.raydirx > 0)
		cub->t.texx = cub->texture[cub->t.texdir].width - cub->t.texx - 1;
	if (cub->ray.side == 1 && cub->ray.raydirx < 0)
		cub->t.texx = cub->texture[cub->t.texdir].width - cub->t.texx - 1;
	cub->t.texpos = (cub->ray.drawstart - cub->ry / 2 + \
			cub->ray.lineheight / 2) * cub->t.step;
	while (++y <= cub->ray.drawend)
	{
		cub->t.texy = (int)cub->t.texpos & \
			(cub->texture[cub->t.texdir].height - 1);
		cub->t.texpos += cub->t.step;
		if (y < cub->ry && x < cub->rx)
			cub->data.addr[y * cub->data.line_length / 4 + x] = \
				cub->texture[cub->t.texdir].addr[cub->t.texy * \
					cub->texture[cub->t.texdir].line_length / \
					4 + cub->t.texx];
	}
}

int	ft_color_column(t_cub *cub)
{
	int	j;
	int	i;

	j = -1;
	cub->ray.drawend = cub->ry - cub->ray.drawstart;
	i = cub->ray.drawend;
	while(++j < cub->ray.drawstart)
		cub->data.addr[j * cub->data.line_length / 4 + cub->ray.x] = cub->c;
	if (j <= cub->ray.drawend)
		ft_draw_texture(cub, cub->ray.x, j);
	j = i;
	while (++j < cub->ry)
		cub->data.addr[j * cub->data.line_length / 4 + cub->ray.x] = cub->f;
	return (0);
}
