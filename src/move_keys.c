/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_keys.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalcara- <aalcara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 20:40:42 by aalcara-          #+#    #+#             */
/*   Updated: 2021/05/25 08:50:39 by aalcara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	ft_key_press(int keycode, t_cub *cub)
{
	if (keycode == FORWARD_W)
		cub->data.forward = 1;
	else if (keycode == BACK_S)
		cub->data.back = 1;
	else if (keycode == LEFT_A)
		cub->data.left = 1;
	else if (keycode == RIGHT_D)
		cub->data.right = 1;
	else if (keycode == ROTATE_LEFT)
		cub->data.rotate_left = 1;
	else if (keycode == ROTATE_RIGHT)
		cub->data.rotate_right = 1;
	else if (keycode == 65307)
		ft_error(cub, "Finish!\n");
	return (1);
}

int	ft_key_release(int keycode, t_cub *cub)
{
	if (keycode == FORWARD_W)
		cub->data.forward = 0;
	else if (keycode == BACK_S)
		cub->data.back = 0;
	else if (keycode == LEFT_A)
		cub->data.left = 0;
	else if (keycode == RIGHT_D)
		cub->data.right = 0;
	else if (keycode == ROTATE_LEFT)
		cub->data.rotate_left = 0;
	else if (keycode == ROTATE_RIGHT)
		cub->data.rotate_right = 0;
	return (1);
}

