#include "cub3d.h"

void move_forward(t_win *window_config)
{
    if (window_config->map->map[(int)window_config->player->py][(int)(window_config->player->px + window_config->player->pdx * SPEED)] == '0')
		window_config->player->px += window_config->player->pdx * SPEED;
	if (window_config->map->map[(int)(window_config->player->py + window_config->player->pdy * SPEED)][(int)window_config->player->px] == '0')
		window_config->player->py += window_config->player->pdy * SPEED;
}

void move_backward(t_win *window_config)
{
    if (window_config->map->map[(int)window_config->player->py][(int)(window_config->player->px - window_config->player->pdx * SPEED)] == '0')
		window_config->player->px -= window_config->player->pdx * SPEED;
	if (window_config->map->map[(int)(window_config->player->py - window_config->player->pdy * SPEED)][(int)window_config->player->px] == '0')
		window_config->player->py -= window_config->player->pdy * SPEED;
}

void move_left(t_win *window_config)
{
    if (window_config->map->map[(int)window_config->player->py][(int)(window_config->player->px - window_config->player->planex * SPEED)] == '0')
		window_config->player->px -= window_config->player->planex * SPEED;
	if (window_config->map->map[(int)(window_config->player->py - window_config->player->planey * SPEED)][(int)window_config->player->px] == '0')
		window_config->player->py -= window_config->player->planey * SPEED;
}

void move_right(t_win *window_config)
{
    if (window_config->map->map[(int)window_config->player->py][(int)(window_config->player->px + window_config->player->planex * SPEED)] == '0')
		window_config->player->px += window_config->player->planex * SPEED;
	if (window_config->map->map[(int)(window_config->player->py + window_config->player->planey * SPEED)][(int)window_config->player->px] == '0')
		window_config->player->py += window_config->player->planey * SPEED;
}