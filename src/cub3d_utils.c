/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalcara- <aalcara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 11:06:16 by aalcara-          #+#    #+#             */
/*   Updated: 2021/06/02 19:34:00 by aalcara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	ft_strlen2(char *str)
{
	int	j;
	int	i;

	j = 0;
	i = 0;
	while (str[i] != '.')
		i++;
	while (str[i] != '\0')
	{
		i++;
		j++;
	}
	return (j);
}

/* Check if have specific char in str. */
int	ft_charinstr(char *str, char c)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

/* - Verify str inserted with C ou F parameter;
- Define floor and cealing color.*/
int	ft_atoi_color(const char *str, t_cub *cub)
{
	int	verify;

	verify = 0;
	if (str[1] != ' ')
		cub->error = 2;
	ft_atoi_color_check(str, cub);
	while (str[cub->i] == ' ' || str[cub->i] == '\t' || str[cub->i] == ',' || \
			str[cub->i] == '\n' || str[cub->i] == '\r' || str[cub->i] == '\v' \
			|| str[cub->i] == '\f')
	{
		cub->i++;
		verify = 0;
		if (str[cub->i] >= '0' && str[cub->i] <= '9')
			cub->indic2++;
		while (str[cub->i] >= '0' && str[cub->i] <= '9')
		{
			verify = (verify * 10) + str[cub->i] - 48;
			cub->sum = (cub->sum * 10) + (str[cub->i] - 48);
			cub->i++;
		}
		if (verify > 255 || verify < 0)
			cub->error = 2;
	}
	return (cub->sum);
}

/* - Verify str inserted with R parameter;
- Define the cub3d resolution. */
int	ft_atoi_resol(const char *str, t_cub *cub)
{
	int		sum;

	sum = 0;
	if (str[1] != ' ' || ft_charinstr((char *)str, ',') == 1)
		cub->error = 2;
	while (str[cub->i] == ' ' || str[cub->i] == '\t' || str[cub->i] == ',' || \
			str[cub->i] == '\n' || str[cub->i] == '\r' || str[cub->i] == '\v' \
			|| str[cub->i] == '\f')
		cub->i++;
	if (str[cub->i] == '-' || str[cub->i] == '+')
		cub->error = 2;
	while (str[cub->i] >= '0' && str[cub->i] <= '9')
	{
		if (sum > 21474636)
			break ;
		sum = (sum * 10) + (str[cub->i] - 48);
		cub->i++;
	}
	while (str[cub->i] >= '0' && str[cub->i] <= '9')
		cub->i++;
	return (sum);
}
