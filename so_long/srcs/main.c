#include "../so_long.h"

// void my_mlx_pixel_put(t_data * data, int x, int y, int color){
// 	char *dst;

// 	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
// 	*(unsigned int *)dst = color;
// }

int main(void)
{
	t_data img;

	int width = 64;
	int height = 64;

	t_sl sl;
	sl.mlx_ptr = mlx_init();
	sl.mlx_win = mlx_new_window(sl.mlx_ptr, 500, 500, "Hello world!");

	img.img = mlx_new_image(sl.mlx_ptr, 500, 500);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);


	char *background_path = "./img/grass_64.xpm";
	void *background = mlx_xpm_file_to_image(sl.mlx_ptr, background_path, &width, &height);
	mlx_put_image_to_window(sl.mlx_ptr, sl.mlx_win, background, 0, 0);
	char *obstacle_path = "./img/cliff_64.xpm";
	void *obstacle = mlx_xpm_file_to_image(sl.mlx_ptr, obstacle_path, &width, &height);
	mlx_put_image_to_window(sl.mlx_ptr, sl.mlx_win, obstacle, 0, 64);
	mlx_put_image_to_window(sl.mlx_ptr, sl.mlx_win, obstacle, 64, 0);
	mlx_put_image_to_window(sl.mlx_ptr, sl.mlx_win, obstacle, 64, 64);
	char *character_path = "./img/chadul_front_64.xpm";
	void *character = mlx_xpm_file_to_image(sl.mlx_ptr, character_path, &width, &height);
	mlx_put_image_to_window(sl.mlx_ptr, sl.mlx_win, character, 0, 0);

	mlx_hook(sl.mlx_win, 17, 0, close_window, &sl);

	mlx_loop(sl.mlx_win);
}
