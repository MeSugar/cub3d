#include "cub3d.h"

void move_forward(t_win *window_config)
{
    window_config->player->py += window_config->player->py / 15;  
}

void close_window(t_win *window_config)
{
    mlx_destroy_window(window_config->mlx_ptr, window_config->win_ptr);
    exit (0);
}

int treat_keys(int keycode, t_win *window_config)
{
    if (keycode == ESC)
        close_window(window_config);
    if (keycode == W)
        move_forward(window_config);

    return (1);
}
