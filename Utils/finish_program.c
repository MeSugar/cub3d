#include "cub3d.h"

void finish_program(t_win *window_config, int mode)
{
    if (mode)
        mlx_destroy_window(window_config->mlx_ptr, window_config->win_ptr);
    exit(0);
}