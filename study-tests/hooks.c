#include "../libraries/minilibx-linux/mlx.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>

#define WIDTH	800
#define HIGHT	600

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


int	main(void)
{
	void	*mlx;
	void	*window;
	mlx = mlx_init();
	window = mlx_new_window(mlx, WIDTH, HIGHT, "title test");
	mlx_key_hook(window, key_hook, &mlx);
	mlx_mouse_hook(window, mouse_hook, &mlx);
	mlx_hook(window, 33, 1L << 17, close_win, &mlx);
	mlx_loop(mlx);
	free(mlx);
	free(window);

	exit (0);
}
