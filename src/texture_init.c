/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalcara- <aalcara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 17:42:38 by aalcara-          #+#    #+#             */
/*   Updated: 2021/05/26 10:52:55 by aalcara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	ft_init_texture(t_cub *cub)
{
	if (cub->ray.side == 0 && cub->ray.raydirx < 0)
		cub->t.texdir = 0;
	if (cub->ray.side == 0 && cub->ray.raydirx >= 0)
		cub->t.texdir = 1;
	if (cub->ray.side == 1 && cub->ray.raydiry < 0)
		cub->t.texdir = 2;
	if (cub->ray.side == 1 && cub->ray.raydiry >= 0)
		cub->t.texdir = 3;
	if (cub->ray.side == 0)
		cub->t.wallx = cub->ray.posy + cub->ray.perpwalldist * cub->ray.raydiry;
	else
		cub->t.wallx = cub->ray.posx + cub->ray.perpwalldist * cub->ray.raydirx;
	cub->t.wallx -= floor((cub->t.wallx));
}
