#include "cub3d.h"

void move_forward(t_win *window_config)
{
    // if (window_config->player->py -= 1 == '0')
    window_config->player->px += window_config->player->pdx / 5;
    window_config->player->py += window_config->player->pdy / 5; 
}

void move_backward(t_win *window_config)
{
    // if (window_config->player->py += 1 == '0')
    window_config->player->px -= window_config->player->pdx / 5;
    window_config->player->py -= window_config->player->pdy / 5;
}

void move_left(t_win *window_config)
{
    // if (window_config->player->px -= 1 == '0')
    window_config->player->px -= 1;
}

void move_right(t_win *window_config)
{
    // if (window_config->player->px += 1 == '0')
    window_config->player->px += 1;
}