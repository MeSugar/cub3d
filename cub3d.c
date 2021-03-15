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

static int loop(t_win *window_config)
{
    mlx_hook(window_config->win_ptr, 2, 1L<<0, pressed_buttons, window_config);
    mlx_hook(window_config->win_ptr, 3, 1L<<1, released_buttons, window_config);
    mlx_loop_hook(window_config->mlx_ptr, main_loop, window_config);
    mlx_loop(window_config->mlx_ptr);
    return (1);
}

int main(int ac, char **av)
{
    t_win *window_config;

    if (ac == 2 && config_name_check(av[1], ".cub"))
    {
        if (!(window_config = window_config_init(av[1]))
        || !map_player_buttons_init(window_config)
        || !ray_init(t_win *window_config)
        || !config_parser(window_config)
        || !window_init(window_config)
        || !draw_image(window_config))
            return (0);
    loop(window_config);
    }
    
}