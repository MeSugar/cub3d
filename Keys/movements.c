#include "cub3d.h"

void move_forward(t_win *window_config)
{
    if (window_config->player->py -= 5 == '0')
        window_config->player->py -= 5; 
}

void move_backward(t_win *window_config)
{
    if (window_config->player->py += 5 == '0')
        window_config->player->py += 5;
}

void move_left(t_win *window_config)
{
    if (window_config->player->px -= 5 == '0')
        window_config->player->px -= 5;
}

void move_right(t_win *window_config)
{
    if (window_config->player->px += 5 == '0')
        window_config->player->px += 5;
}