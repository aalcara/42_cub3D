/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalcara- <aalcara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 16:41:47 by aalcara-          #+#    #+#             */
/*   Updated: 2021/06/23 14:30:56 by aalcara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

/*
Return 1 for an string with valids map characters
*/
int	ft_is_map(char *str, t_cub *cub)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	if (ft_charinstr(str, '1') == 1 || ft_charinstr(str, '0') == 1)
	{
		while (str[i] != '\0')
		{
			if (str[i] != ' ' && str[i] != '0' && str[i] != '1' \
					&& str[i] != '2' && str[i] != 'N' && str[i] != 'S' \
					&& str[i] != 'E' && str[i] != 'W' && str[i] != '\n' \
					&& str[i] != '\t')
			{
				if (cub->insidemap == 1)
					cub->wrongcharmap = 2;
				return (0);
			}
			i++;
		}
		return (1);
	}
	return (0);
}

/*
based on ft_is_map return, take cub.nblines and cub.sizeline
*/
void	ft_mapsize(char *str, t_cub *cub)
{
	int			i;
	static int	snblines = 0;
	static int	ssizeline = 0;

	i = 0;
	if (ft_is_map(str, cub) == 1)
	{
		if (cub->f == -1 || cub->c == -1 || cub->no == NULL || cub->so == NULL \
				|| cub->we == NULL || cub->ea == NULL || cub->sp == NULL)
			cub->error = 2;
		i = ft_strlen(str);
		if (i > ssizeline)
			ssizeline = i;
		snblines = snblines + 1;
	}
	cub->nblines = snblines;
	cub->sizeline = ssizeline;
}

/*
Copy str to cub.map array
*/
int	ft_copy_map(char *str, t_cub *cub)
{
	static int	i = 0;
	int			j;

	j = 0;
	cub->map[i] = malloc(sizeof(char) * cub->sizeline + 1);
	if (!cub->map[i])
		return (0);
	while (str[j] != '\0')
	{
		if (ft_start(str[j], cub, i, j) == 1)
			cub->map[i][j] = '0';
		else if (str[j] == ' ')
			cub->map[i][j] = '1';
		else
			cub->map[i][j] = str[j];
		j++;
	}
	while (j <= (cub->sizeline - 1))
	{
		cub->map[i][j] = '1';
		j++;
	}
	cub->map[i][j] = '\0';
	i++;
	return (0);
}

/*
- Open .cub file again
- While get_next_line return some value, call ft_copy_map
*/
int	ft_parsing_map(char *filename, t_cub *cub)
{
	int		fd;
	int		ret;
	char	*str;

	ret = 1;
	fd = open(filename, O_RDONLY);
	cub->map = malloc(sizeof(char *) * cub->nblines);
	if (!cub->map)
		return (0);
	while (ret != 0)
	{
		ret = get_next_line(fd, &str, cub);
		if (cub->insidemap == 1 && ft_emptyline(str) == 0 && \
				cub->count < cub->nblines)
			cub->emptyline = 1;
		cub->insidemap = ft_is_map(str, cub);
		if (cub->insidemap == 1)
			cub->count++;
		if (cub->insidemap == 1)
			ft_copy_map(str, cub);
		free(str);
	}
	close(fd);
	ft_init_sprite(cub);
	return (0);
}
