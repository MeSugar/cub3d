#include "cub3d.h"

void turn_left(t_win *window_config)
{
    window_config->player->pa -= 0.1;
    if (window_config->player->pa < 0)
        window_config->player->pa += 2 * PI;
    window_config->player->pdx = cos(window_config->player->pa) * 5;
    window_config->player->pdy = sin(window_config->player->pa) * 5;
}

void turn_right(t_win *window_config)
{
    window_config->player->pa += 0.1;
    if (window_config->player->pa > 2 * PI)
        window_config->player->pa -= 2 * PI;
    window_config->player->pdx = cos(window_config->player->pa) * 5;
    window_config->player->pdy = sin(window_config->player->pa) * 5;
}