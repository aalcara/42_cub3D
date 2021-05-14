#include "../libraries/minilibx-linux/mlx.h"
#include "../../42_libft/libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "get_next_line.h"
#include <unistd.h>



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

typedef struct	s_img
{
	void	*img;
	char	*addr;
	int		width;
	int		height;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_img;

typedef struct	s_map
{
	int		colums;
	int		rows;
	char	**matrix;
}				t_map;

t_map	g_map;

#define WIDTH	800
#define HEIGHT	600

void	my_mlx_pixel_put(t_img *data, int x, int y, int color)
{
	char	*dst;
	int		offset;

	offset = (y * data->line_length + x * (data->bits_per_pixel / 8));
	dst = data->addr + offset;
	*(unsigned int *)dst = color;
}

int	key_hook(int keycode)
{
	printf("Hello from key_hook! Key: %d\n", keycode);
	return (0);
}

int	mouse_hook(int mouse)
{
	printf("Hello from mouse! mouse: %d\n", mouse);
	return (0);
}

int	close_win(void*mlx, void*window)
{
	mlx_destroy_window(mlx, window);
	return (1);
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
		printf("line = %s\n", line);
		if (len < (int)ft_strlen(line))
			len = ft_strlen(line);
		index++;
		printf("index = %d\n", index);
	}
	close(fd);
	printf("\ntotal rows = %d\n", index);
	printf("\nlen = %d\n", len);
	*rows = (index - 1);
	return (len);
}


int	get_map( char *file)
{
	int		fd;
	char	*line;
	int		aux;
	int		index;
	int		row;

	printf("\nentrou get_map\n");
	row = 0;
	g_map.colums = map_dimension(&row, file);
	g_map.rows = row;
	printf("colums = %d", g_map.colums);
	index = 0;
	aux = 1;
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
		ft_strlcpy(g_map.matrix[index], line, g_map.colums + 1);
		index++;
	}
	close(fd);
	return (0);
}

int	main(int argc, char *argv[])
{
	void	*mlx;
	void	*window;
	t_img	img;
	int		x;
	int		y;
	int		factorx;
	int		factory;
	int		xpos;
	int		ypos;


	printf("\nargc = %d\n", argc);
	img.width = WIDTH;
	img.height = HEIGHT;
	mlx = mlx_init();
	get_map(argv[1]);
	window = mlx_new_window(mlx, WIDTH, HEIGHT, "title test");
	img.img = mlx_new_image(mlx, img.width, img.height);
	factorx = 100*img.width/g_map.colums;
	factory = 100*img.height/g_map.rows;

	printf("\nfactorx = %d", factorx);
	printf("\nfactory = %d\n", factory);
	printf("\nmatrix[max][max]: %c\n", g_map.matrix[4][10]);

	x = 0;
	y = 0;
	while (x < img.width)
	{
		while (y < img.height)
		{
			xpos = (x/(factorx/100))-1;
			ypos = (y/(factory/100))-1;
			if (ypos >= 0 && ypos <= 4 && xpos >= 0 && xpos <= 10)
			{
				printf("\nmatrix[ypos][xpos]: %c\n", g_map.matrix[ypos][xpos]);
				if (g_map.matrix[ypos][xpos] == '1')
					my_mlx_pixel_put(&img, x, y, (0x00ffff00));
			}
			y++;
		}
		y = 0;
		x++;
	}

	mlx_put_image_to_window(mlx, window, img.img, 0, 0);

	mlx_key_hook(window, key_hook, &mlx);
	mlx_mouse_hook(window, mouse_hook, &mlx);
	mlx_hook(window, 33, 1L << 17, close_win, &mlx);
	mlx_loop(mlx);

	// free(mlx);
	// free(window);

	return (0);
}
