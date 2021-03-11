#include "cub3d.h"

void move_forward(t_win *window_config)
{
    if (window_config->player->py -= window_config->player->py / 15 == '0')
        window_config->player->py -= window_config->player->py / 15; 
}

void move_backward(t_win *window_config)
{
    if (window_config->player->py += window_config->player->py / 15 == '0')
        window_config->player->py += window_config->player->py / 15;
}

void move_left(t_win *window_config)
{
    if (window_config->player->px -= window_config->player->px / 15 == '0')
        window_config->player->px -= window_config->player->px / 15;
}

void move_right(t_win *window_config)
{
    if (window_config->player->px += window_config->player->px / 15 == '0')
        window_config->player->px += window_config->player->px / 15;
}