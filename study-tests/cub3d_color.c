/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalcara- <aalcara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 15:33:32 by aalcara-          #+#    #+#             */
/*   Updated: 2021/06/23 15:48:07 by aalcara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "../inc/cub3d.h"

#include <stdio.h>

int	ft_rgb_to_hex(int r, int g, int b)
{
	int	hexa;

	hexa = (r << 16) + (g << 8) + b;
	
}


int main(void)
{
	int r = 255;
	int g = 20;
	int b = 30;
	int hexa;

	hexa = ft_rgb_to_hex(r,g,b);

	printf("\nRGB = (%d, %d, %d)\n", r, g, b);
	printf("HEXA = #%.6X\n", hexa);

	return (0);
	

}