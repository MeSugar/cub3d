#include "cub3d.h"

int finish_program(t_win *window_config, int mode)
{
    if (mode && window_config->win_ptr)
        mlx_destroy_window(window_config->mlx_ptr, window_config->win_ptr);
    // free(window_config->map);
    // free(window_config->player);
    // free(window_config->image);
    // free(window_config->sprite);
    // free(window_config->no_tex);
    // free(window_config->so_tex);
    // free(window_config->ea_tex);
    // free(window_config->we_tex);
    // free(window_config->sprite_tex);
    // free(window_config);
    exit(0);
    return (1);
}

// int kill_window(t_win *window_config)
// {
//     finish_program(window_config, 1);
//     return (1);
// }
