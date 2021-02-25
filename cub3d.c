#include "cub3d.h"

int main(int ac, char **av)
{
    t_win *window_config;

    if (!(window_config = window_config_init(av[1]))
    || !map_init(window_config)
    || !config_parser(window_config))
        return (0);



    // void *mlx_ptr;
    // void *win_ptr;
    // int x = 50;
    // int y = 50;

    // mlx_ptr = mlx_init();
    // win_ptr = mlx_new_window(mlx_ptr, 500, 500, "cub3D");
    // while (x++ < 400)
    // {
    //     y = 50;
    //     while (y++ < 400)
    //         mlx_pixel_put(mlx_ptr, win_ptr, x, y, 111444);
    // }

    // mlx_loop(mlx_ptr);

}