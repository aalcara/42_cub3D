/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalcara- <aalcara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 09:56:42 by aalcara-          #+#    #+#             */
/*   Updated: 2021/05/26 11:43:12 by aalcara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	ft_path_texture(char *str, char **texture, t_cub *cub, int j)
{
	cub->count2 = 0;
	if (*texture != NULL)
	{
		cub->error = 2;
		return (0);
	}
	if (ft_charinstr(str, '.') == 0 || ft_charinstr(str, '/') == 0 || \
			ft_strlen2(str) <= 2)
		cub->error = 2;
	while (str[j] != '.')
	{
		if (str[j] != ' ' && str[j] != '.')
			cub -> error = 2;
		j++;
	}
	*texture = (char *)(malloc(sizeof(char) * (ft_strlen2(str) + 1)));
	if (!(*texture))
		cub->error = 2;
	while (str[j] != '\0')
	{
		(*texture)[cub->count2] = str[j];
		cub->count2++;
		j++;
	}
	(*texture)[cub->count2] = str[j];
	return (0);
}

void	ft_texture(char *str, t_cub *cub)
{
	int			i;
	static int	j = 0;

	i = 0;
	if (str[i] == 'S' && str[i + 1] == 'O')
		ft_path_texture(str, &cub->no, cub, 2);
	else if (str[i] == 'N' && str[i + 1] == 'O')
		ft_path_texture(str, &cub->so, cub, 2);
	else if (str[i] == 'E' && str[i + 1] == 'A')
		ft_path_texture(str, &cub->we, cub, 2);
	else if (str[i] == 'W' && str[i + 1] == 'E')
		ft_path_texture(str, &cub->ea, cub, 2);
	else if (str[i] == 'S' && str[i + 1] != 'O')
		ft_path_texture(str, &cub->sp, cub, 1);
	else if (str[0] != 'N' && str[0] != 'S' && str[0] != 'W' && str[0] != 'E'\
			&& str[0] != 'R' && str[0] != 'F' && str[0] != 'C'\
			&& str[0] > 65 && str[0] < 122)
		cub->error = 2;
	j++;
}

void	ft_color_resolution(char **str, t_cub *cub)
{
	int	i;

	i = 0;
	cub->i = 1;
	if (cub->sizeline > 0 && (cub->no == NULL || cub->so == NULL ||\
			cub->we == NULL || cub->ea == NULL ||cub->sp == NULL))
		cub->error = 2;
	if ((cub->no != NULL || cub->so != NULL || cub->we != NULL ||\
			cub->ea != NULL || cub->sp != NULL) &&\
			(cub->rx == 0 || cub->ry == 0))
		cub->error = 2;
	if (*str[i] == 'R')
	{
		if (cub->rx != 0 && cub->ry != 0)
			cub->error = 2;
		cub->rx = ft_atoi_resol(*str, cub);
		cub->ry = ft_atoi_resol(*str, cub);
		if (ft_atoi_resol(*str, cub) > 0 || cub->rx == 0 || cub->ry == 0)
			cub->error = 2;
	}
	else if (*str[i] == 'F')
		cub->f = ft_atoi_color(*str, cub);
	else if (*str[i] == 'C')
		cub->c = ft_atoi_color(*str, cub);
}

void	ft_parsing(char *filename, t_cub *cub)
{
	int		fd;
	int		ret;
	char	*str;

	ret = 1;
	str = NULL;
	fd = open(filename, O_DIRECTORY);
	if (fd != -1)
		ft_error(cub, "filename is a directory\n");
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		ft_error(cub, "invalid .cub file\n");
	cub->error = 0;
	while (ret != 0)
	{
		ret = get_next_line(fd, &str, cub);
		if (cub->error == 2)
			ft_error(cub, "Find an error on parsing\n");
		ft_color_resolution(&str, cub);
		ft_texture(str, cub);
		ft_mapsize(str, cub);
		free(str);
	}
	close(fd);
	if (cub->sizeline == 0 || cub->nblines == 0)
		ft_error(cub, "missing map\n");
	ft_parsing_map(filename, cub);
}

