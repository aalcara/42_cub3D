/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_get.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalcara- <aalcara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 17:42:38 by aalcara-          #+#    #+#             */
/*   Updated: 2021/06/16 16:02:10 by aalcara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

/*
Gets momory address of images
*/
void	ft_get_texture_adress(t_cub *cub)
{
	cub->texture[0].addr = (int *)mlx_get_data_addr(cub->texture[0].img,
			&cub->texture[0].bits_per_pixel, &cub->texture[0].line_length,
			&cub->texture[0].endian);
	cub->texture[1].addr = (int *)mlx_get_data_addr(cub->texture[1].img,
			&cub->texture[1].bits_per_pixel, &cub->texture[1].line_length,
			&cub->texture[1].endian);
	cub->texture[2].addr = (int *)mlx_get_data_addr(cub->texture[2].img,
			&cub->texture[2].bits_per_pixel, &cub->texture[2].line_length,
			&cub->texture[2].endian);
	cub->texture[3].addr = (int *)mlx_get_data_addr(cub->texture[3].img,
			&cub->texture[3].bits_per_pixel, &cub->texture[3].line_length,
			&cub->texture[3].endian);
	cub->texture[4].addr = (int *)mlx_get_data_addr(cub->texture[4].img,
			&cub->texture[4].bits_per_pixel, &cub->texture[4].line_length,
			&cub->texture[4].endian);
}

/*
Reads texture mlx files to cub.texture.img variable
*/
void	ft_get_texture(t_cub *cub)
{
	cub->texture[0].img = mlx_xpm_file_to_image(cub->data.mlx_ptr, \
				cub->no, &(cub->texture[0].width), &(cub->texture[0].height));
	if (!cub->texture[0].img)
		ft_error(cub, "Texture NO\n");
	cub->texture[1].img = mlx_xpm_file_to_image(cub->data.mlx_ptr, \
				cub->so, &(cub->texture[1].width), &(cub->texture[1].height));
	if (!cub->texture[1].img)
		ft_error(cub, "Texture SO\n");
	cub->texture[2].img = mlx_xpm_file_to_image(cub->data.mlx_ptr, \
				cub->we, &(cub->texture[2].width), &(cub->texture[2].height));
	if (!cub->texture[2].img)
		ft_error(cub, "Texture WE\n");
	cub->texture[3].img = mlx_xpm_file_to_image(cub->data.mlx_ptr, \
				cub->ea, &(cub->texture[3].width), &(cub->texture[3].height));
	if (!cub->texture[3].img)
		ft_error(cub, "Texture EA\n");
	cub->texture[4].img = mlx_xpm_file_to_image(cub->data.mlx_ptr, \
				cub->sp, &(cub->texture[4].width), &(cub->texture[4].height));
	if (!cub->texture[4].img)
		ft_error(cub, "Texture Sprite\n");
	ft_get_texture_adress(cub);
}
