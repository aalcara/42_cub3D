/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalcara- <aalcara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 21:12:44 by aalcara-          #+#    #+#             */
/*   Updated: 2021/05/24 21:18:00 by aalcara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	ft_exit(t_cub *cub)
{
	if (cub->indic3 == 0)
		ft_error(cub, "Finish!\n");
	if (cub->data.img)
		mlx_destroy_image(cub->data.mlx_ptr, cub->data.img);
	if (cub->texture[0].img)
		mlx_destroy_image(cub->data.mlx_ptr, cub->texture[0].img);
	if (cub->texture[1].img)
		mlx_destroy_image(cub->data.mlx_ptr, cub->texture[1].img);
	if (cub->texture[2].img)
		mlx_destroy_image(cub->data.mlx_ptr, cub->texture[2].img);
	if (cub->texture[3].img)
		mlx_destroy_image(cub->data.mlx_ptr, cub->texture[3].img);
	if (cub->texture[4].img)
		mlx_destroy_image(cub->data.mlx_ptr, cub->texture[4].img);
	if (cub->data.mlx_win)
		mlx_destroy_window(cub->data.mlx_ptr, cub->data.mlx_win);
	exit(0);
}
