#include "../libraries/minilibx-linux/mlx.h"
#include "../../42_libft/libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "get_next_line.h"
#include <unistd.h>


typedef struct	s_map
{
	int		colums;
	int		rows;
	char	**matrix;
}				t_map;

t_map	g_map;

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	unsigned int		i;
	char				temp;

	if (src == NULL)
		return (0);
	if (size > 0)
	{
		i = 0;
		temp = src[i];
		while (temp != '\0' && i < (size - 1))
		{
			dst[i] = temp;
			i++;
			temp = src[i];
		}
		dst[i] = '\0';
	}
	return (ft_strlen(src));
}

int map_dimension (int *rows, char *file)
{
	int		aux;
	int		fd;
	char	*line;
	int 	len;
	int		index;

	printf("\nentrou map_dimension\n");
	fd = open(file, O_RDONLY);
	printf("\nfd = %d\n", fd);
	aux = 1;
	printf("\naux = %d\n", aux);
	len = 0;
	printf("\nlen = %d\n", len);
	index = 0;
	printf("\nindex = %d\n", index);
	while (aux > 0)
	{
		aux = get_next_line(fd, &line);
		printf("\naux = %d\n", aux);
		printf("\nline = %s\n", line);
		if (len < (int)ft_strlen(line))
			len = ft_strlen(line);
		index++;
		printf("\nindex = %d\n", index);
	}
	close(fd);
	printf("\ntotal rows = %d\n", index);
	printf("\nlen ?= %d\n", len);
	*rows = (index - 1);
	return (len);

}

int main(void)
{
	int	row;
	char *file = "test.cub";
	int fd;
	int aux;
	char *line;
	int	index = 0;

	g_map.colums = map_dimension(&row, file);
	g_map.rows = row;
	printf("colums = %d\n", g_map.colums);
	printf("rows = %d\n\n", g_map.rows);

	fd = open(file, O_RDONLY);

	g_map.matrix = (char **)malloc((g_map.rows) * sizeof(char*));
	if (!(g_map.matrix))
		return(printf("erro ao alocar map->matrix"));

	while (index < g_map.rows)
	{
		aux = get_next_line(fd, &line);
		g_map.matrix[index] = (char *)malloc((g_map.colums + 1) * sizeof(char));
		if (!(g_map.matrix[index]))
			return(printf("erro ao alocar map->matrix[%d]", index));
		ft_strlcpy(g_map.matrix[index], line, g_map.colums+1);
		printf ("linha: %d: %s\n", index, g_map.matrix[index]);
		index++;
	}
	close (fd);
	printf("\nmatrix[2][5]: %c\n", g_map.matrix[2][5]);

	return (0);


}
