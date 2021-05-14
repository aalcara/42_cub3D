#include "../libraries/minilibx-linux/mlx.h"

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		width;
	int		height;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_img;

void	my_mlx_pixel_put(t_img *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	main(void)
{
	void	*test;
	void	*window;
	t_img	img;
	int		x;
	int		y;

	img.width = 800;
	img.height = 600;
	test = mlx_init();
	img.img = mlx_new_image(test, img.width, img.height);
	window = mlx_new_window(test, img.width, img.height, "title test");
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	x = 0;
	y = 0;
	while (x < img.width)
	{
		while (y < img.height)
		{
			my_mlx_pixel_put(&img, x, y, (0x00ffff00));
			y++;
		}
		y = 0;
		x++;
	}
	mlx_put_image_to_window(test, window, img.img, 0, 0);
	mlx_loop(test);
}
