/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anderson <anderson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 10:57:01 by aalcara-          #+#    #+#             */
/*   Updated: 2021/06/16 09:16:24 by anderson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

/*
write bmp file header
*/
void	ft_header(t_cub *cub, int fd)
{
	int	tmp;

	write(fd, "BM", 2);
	tmp = 14 + 40 + 4 * cub->rx * cub->ry;
	write(fd, &tmp, 4);
	tmp = 0;
	write(fd, &tmp, 2);
	write(fd, &tmp, 2);
	tmp = 54;
	write(fd, &tmp, 4);
	tmp = 40;
	write(fd, &tmp, 4);
	write(fd, &cub->rx, 4);
	write(fd, &cub->ry, 4);
	tmp = 1;
	write(fd, &tmp, 2);
	write(fd, &cub->data.bits_per_pixel, 2);
	tmp = 0;
	write(fd, &tmp, 4);
	write(fd, &tmp, 4);
	write(fd, &tmp, 4);
	write(fd, &tmp, 4);
	write(fd, &tmp, 4);
	write(fd, &tmp, 4);
}

/*
Creat and write header of bmp file.
*/
void	ft_save(t_cub *cub)
{
	int	fd;
	int	x;
	int	y;

	y = cub->ry;
	fd = open("./image.bmp", O_CREAT | O_RDWR);
	if (fd == -1)
		ft_error(cub, "Impossible create .bmp\n");
	ft_header(cub, fd);
	while (y >= 0)
	{
		x = 0;
		while (x < cub->rx)
		{
			write(fd, &cub->data.addr[y * cub->data.line_length / 4 + x], 4);
			x++;
		}
		y--;
	}
	system("chmod 777 image.bmp");
	ft_error(cub, "Finish --save ok\n");
}
