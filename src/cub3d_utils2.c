/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalcara- <aalcara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 16:26:48 by aalcara-          #+#    #+#             */
/*   Updated: 2021/06/23 16:12:04 by aalcara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

/*- If str is a empty line, return 1
- Else return 0*/
int	ft_emptyline(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != '\t' && str[i] != ' ' && str[i] != '\0' && \
				str [i] != '\n' && str[i] != '\r' && str[i] != '\v' \
				&& str[i] != '\f')
			return (1);
		i++;
	}
	return (0);
}

/*Verifry number of commas in a function. */
int	ft_nb_comma(const char *str)
{
	int	i;
	int	j;

	i = -1;
	j = 0;
	while (str[++i])
	{
		if (str[i] == ',')
			j++;
	}
	return (j);
}

/*Check if paramerter has correct pattern (two commas).*/
void	ft_atoi_color_check(const char *str, t_cub *cub)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i] != ',')
		i++;
	if (str[i] == ',')
		j = 1;
	i++;
	while (str[i] == ' ')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
		i++;
	while ((str[i] < '0' || str[i] > '9') && str[i])
	{
		if (str[i] == ',')
			j++;
		i++;
	}
	if (j != 2)
		cub->error = 2;
	if (ft_nb_comma(str) != 2)
		cub->error = 2;
}

void	ft_check_directory(char *filename, int fd, t_cub *cub)
{
	fd = open(filename, O_DIRECTORY);
	if (fd != -1)
		ft_error(cub, "filename is a directory\n");
}

void	ft_color_calc(int verify, t_cub *cub)
{
	if (cub->indic2 == 1 || cub->indic2 == 4)
		cub->sum = cub->sum + verify * 256 * 256;
	else if (cub->indic2 == 2 || cub->indic2 == 5)
		cub->sum = cub->sum + verify * 256;
	else if (cub->indic2 == 3 || cub->indic2 == 6)
		cub->sum = cub->sum + verify;
}
