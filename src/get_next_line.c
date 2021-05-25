/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalcara- <aalcara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 23:30:56 by aalcara-          #+#    #+#             */
/*   Updated: 2021/05/25 08:26:12 by aalcara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	ft_check(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

int	ft_copy(char **line, char **buff)
{
	int		start;
	char	*temp;
	char	*line_temp;

	start = ft_check(*buff);
	if (start >= 0)
	{
		temp = ft_substr(*buff, 0, start);
		line_temp = *line;
		*line = ft_strjoin(*line, temp);
		free(temp);
		free(line_temp);
		*buff = ft_subbuff(*buff, start + 1, (ft_strlen(*buff) - start));
		return (0);
	}
	else
	{
		temp = NULL;
		if (*line)
			temp = *line;
		*line = ft_strjoin(*line, *buff);
		if (temp)
			free(temp);
		return (1);
	}
	return (-1);
}

int	ft_eof(int ret, char **buff, char **line)
{
	if (ret == -1)
		return (-1);
	free(*buff);
	*buff = NULL;
	if (*line == NULL)
	{
		*line = malloc(sizeof(char) * 1);
		*line[0] = 0;
	}
	return (0);
}

int	ft_free_buff(char **buff, t_cub *cub)
{
	if (cub->error == 2 && *buff)
	{
		free(*buff);
		return (1);
	}
	return (0);
}

int	get_next_line(int fd, char **line, t_cub *cub)
{
	static char	*buff = NULL;
	int			ret;

	if (ft_free_buff(&buff, cub) == 1)
		return (0);
	if (fd < 0 || BUFFER_SIZE <= 0 || !line)
		return (-1);
	*line = NULL;
	ret = 1;
	if (buff)
		ret = ft_copy(line, &buff);
	if (ret == 0)
		return (1);
	if (!buff)
		if (!(buff = malloc(sizeof(char) * BUFFER_SIZE + 1)))
			return (-1);
	while ((ret = read(fd, buff, BUFFER_SIZE)) > 0)
	{
		buff[ret] = '\0';
		if (!ft_copy(line, &buff))
			return (1);
	}
	if (ret <= 0)
		return (ft_eof(ret, &buff, line));
	return (1);
}
