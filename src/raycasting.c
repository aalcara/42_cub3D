/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalcara- <aalcara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 18:59:51 by aalcara-          #+#    #+#             */
/*   Updated: 2021/06/21 17:03:28 by aalcara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	ft_raycasting(t_cub *cub)
{
	cub->ray.x = 0;
	while (cub->ray.x < cub->rx)
	{
		ft_init_ray(cub);
		ft_stepsidedist(cub);
		ft_color_column(cub);
		cub->s.zbuffer[cub->ray.x] = cub->ray.perpwalldist;
		cub->ray.x++;
	}
	ft_sprite(cub);
	if (cub->save == 1)
		ft_save(cub);
	mlx_put_image_to_window(cub->data.mlx_ptr, cub->data.mlx_win, \
			cub->data.img, 0, 0);
	ft_forward_back(cub);
	ft_left_right(cub);
	ft_rotate_right_left(cub);
	ft_swap(cub);
	return (0);
}

void	ft_get_resolution(t_cub *cub)
{
	mlx_get_screen_size(cub->data.mlx_ptr, &cub->screenx, &cub->screeny);
	if (cub->rx > cub->screenx)
		cub->rx = cub->screenx;
	if (cub->ry > cub->screeny)
		cub->ry = cub->screeny;
}

/*
- Initialize mlx, make hooks and loop
*/
int	ft_mlx(t_cub *cub)
{
	ft_init_mlx(cub);
	cub->data.mlx_ptr = mlx_init();
	if (!cub->data.mlx_ptr)
		ft_error(cub, "Mlx init impossible\n");
	ft_get_resolution(cub);
	ft_get_texture(cub);
	cub->data.img = mlx_new_image(cub->data.mlx_ptr, cub->rx, cub->ry);
	cub->data.addr = (int *)mlx_get_data_addr(cub->data.img, &cub->data.\
			bits_per_pixel, &cub->data.line_length, &cub->data.endian);
	if (cub->save == 1)
		ft_raycasting(cub);
	cub->data.mlx_win = mlx_new_window(cub->data.mlx_ptr, cub->rx, cub->ry,
			"CUB3D");
	cub->data.img2 = mlx_new_image(cub->data.mlx_ptr, cub->rx, cub->ry);
	cub->data.addr2 = (int *)mlx_get_data_addr(cub->data.img2, &cub->data.\
			bits_per_pixel, &cub->data.line_length, &cub->data.endian);
	mlx_hook(cub->data.mlx_win, 33, 1L << 17, ft_exit, cub);
	mlx_hook(cub->data.mlx_win, 2, 1L << 0, ft_key_press, cub);
	mlx_hook(cub->data.mlx_win, 3, 1L << 1, ft_key_release, cub);
	mlx_loop_hook(cub->data.mlx_ptr, ft_raycasting, cub);
	mlx_loop(cub->data.mlx_ptr);
	return (0);
}
