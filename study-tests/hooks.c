#include "../libraries/minilibx-linux/mlx.h"
#include <stdio.h>

int				key_hook(int keycode)
{
	printf("Hello from key_hook! Key: %d\n", keycode);
	return 0;
}

int				mouse_hook(int mouse)
{
	printf("Hello from mouse! mouse: %d\n", mouse);
	return 0;
}

int main(void)
{
void *mlx;
void *window;

mlx = mlx_init();
window = mlx_new_window(mlx, 640, 480, "title test");
mlx_key_hook(window, key_hook, &mlx);
mlx_mouse_hook(window, mouse_hook, &mlx);

mlx_loop(mlx);

// return 0;
}

