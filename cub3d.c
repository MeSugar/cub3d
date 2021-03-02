#include "cub3d.h"
static int config_name_check(char *av, char *cub)
{
    int i;

    i = 0;
    while(*av && *av != '.')
        av++;
    if (*av != '.' || !ft_strnstr(av, cub, 4))
        return (put_error_msg("Error: Invalid config file name\n"));
    return (1);
}

int main(int ac, char **av)
{
    t_win *window_config;

    if (ac == 2 && config_name_check(av[1], ".cub"))
        if (!(window_config = window_config_init(av[1]))
        || !map_init(window_config)
        || !config_parser(window_config)
        || !window_init(window_config)
        || !draw_image(window_config))
            return (0);

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