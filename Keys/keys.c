#include "cub3d.h"

// void move(t_win *window_config)
// {

// }

int close_window(int keycode, t_win *window_config)
{
    mlx_destroy_window(window_config->mlx_ptr, window_config->win_ptr);
    return (1);
}

int treat_keys(int keycode, t_win *window_config)
{
    if (keycode == ESC)
        close_window(keycode, window_config);
    return (1);
}
