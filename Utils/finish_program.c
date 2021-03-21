#include "cub3d.h"

int finish_program(t_win *window_config, int mode)
{
    if (mode)
        mlx_destroy_window(window_config->mlx_ptr, window_config->win_ptr);
    exit(0);
    return (1);
}

int kill_window(t_win *window_config)
{
    finish_program(window_config, 1);
    return (1);
}
