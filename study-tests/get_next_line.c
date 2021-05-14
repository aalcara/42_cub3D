/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalcara- <aalcara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 23:30:56 by aalcara-          #+#    #+#             */
/*   Updated: 2021/03/07 14:40:46 by aalcara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char			*first_line(char *buffer)
{
	int			i;
	char		*line;

	i = 0;
	if (!buffer)
		return (0);
	while (buffer[i] != '\n' && buffer[i] != '\0')
		i++;
	if (!(line = ft_substr(buffer, 0, i)))
		return (0);
	return (line);
}

char			*new_buffer(char *buffer)
{
	int			i;
	char		*new_buff;

	i = 0;
	if (!buffer)
		return (0);
	while (buffer[i] != '\n' && buffer[i] != '\0')
		i++;
	if (!buffer[i])
	{
		free(buffer);
		return (0);
	}
	if (!(new_buff = ft_substr(buffer, i + 1, ft_strlen(buffer))))
	{
		free(buffer);
		return (0);
	}
	free(buffer);
	return (new_buff);
}

int				has_new_line(char *marker)
{
	int			i;

	i = 0;
	if (!marker)
		return (0);
	while (marker[i])
	{
		if (marker[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

int				get_next_line(int fd, char **line)
{
	static char		*buffer;
	char			*marker;
	int				read_return;

	read_return = 1;
	if (!line || fd < 0 || BUFFER_SIZE <= 0)
		return (-1);
	if (!(marker = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (-1);
	while (read_return != 0 && !has_new_line(buffer))
	{
		if ((read_return = read(fd, marker, BUFFER_SIZE)) == -1)
		{
			free(marker);
			return (-1);
		}
		marker[read_return] = '\0';
		buffer = ft_strjoin_gnl(buffer, marker);
	}
	free(marker);
	*line = first_line(buffer);
	buffer = new_buffer(buffer);
	if (read_return == 0 && ft_strlen(buffer) == 0)
		return (0);
	return (1);
}
