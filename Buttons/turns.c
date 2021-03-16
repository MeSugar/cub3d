#include "cub3d.h"

void turn_left(t_win *window_config)
{
	double olddirx;
	double oldplanex;

	olddirx = window_config->player->pdx;
	oldplanex = window_config->player->planex;
	window_config->player->pdx = window_config->player->pdx * cos(-TURN) - window_config->player->pdy * sin(-TURN);
	window_config->player->pdy = olddirx * sin(-TURN) + window_config->player->pdy * cos(-TURN);
	window_config->player->planex = window_config->player->planex * cos(-TURN) - window_config->player->planey * sin(-TURN);
	window_config->player->planey = oldplanex * sin(-TURN) + window_config->player->planey * cos(-TURN);
}

void turn_right(t_win *window_config)
{
	double olddirx;
	double oldplanex;

	olddirx = window_config->player->pdx;
	oldplanex = window_config->player->planex;
	window_config->player->pdx = window_config->player->pdx * cos(TURN) - window_config->player->pdy * sin(TURN);
	window_config->player->pdy = olddirx * sin(TURN) + window_config->player->pdy * cos(TURN);
	window_config->player->planex = window_config->player->planex * cos(TURN) - window_config->player->planey * sin(TURN);
	window_config->player->planey = oldplanex * sin(TURN) + window_config->player->planey * cos(TURN);
}