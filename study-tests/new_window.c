#include "../libraries/minilibx-linux/mlx_int.h"
#include "../libraries/minilibx-linux/mlx.h"


// void *
// mlx_init();

int main(void)
{
void *test;
void *window;
test = mlx_init();
window = mlx_new_window(test, 1000, 600, "title test");
mlx_loop(test);

// return 0;
}
