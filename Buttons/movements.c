#include "cub3d.h"

void move_forward(t_win *window_config)
{
    if (window_config->map->map[(int)window_config->player->py][(int)(window_config->player->px + window_config->player->pdx / 5)] == '0')
        window_config->player->px += window_config->player->pdx / 5;
    if (window_config->map->map[(int)(window_config->player->py + window_config->player->pdy / 5)][(int)window_config->player->px] == '0')
    window_config->player->py += window_config->player->pdy / 5; 
}

void move_backward(t_win *window_config)
{
    if (window_config->map->map[(int)window_config->player->py][(int)(window_config->player->px - window_config->player->pdx / 5)] == '0')
        window_config->player->px -= window_config->player->pdx / 5;
    if (window_config->map->map[(int)(window_config->player->py - window_config->player->pdy / 5)][(int)window_config->player->px] == '0')
    window_config->player->py -= window_config->player->pdy / 5; 
}

void move_left(t_win *window_config)
{
    if (window_config->map->map[(int)window_config->player->py][(int)(window_config->player->px + window_config->player->pdy / 5)] == '0')
        window_config->player->px += window_config->player->pdy / 5;
    if (window_config->map->map[(int)(window_config->player->py - window_config->player->pdx / 5)][(int)window_config->player->px] == '0')
    window_config->player->py -= window_config->player->pdx / 5;
}

void move_right(t_win *window_config)
{
    if (window_config->map->map[(int)window_config->player->py][(int)(window_config->player->px - window_config->player->pdy / 5)] == '0')
        window_config->player->px -= window_config->player->pdy / 5;
    if (window_config->map->map[(int)(window_config->player->py + window_config->player->pdx / 5)][(int)window_config->player->px] == '0')
        window_config->player->py += window_config->player->pdx / 5;
}