#include "cub3d.h"

void set_ray(t_win *window_config, int rays)
{
    window_config->ray->camerax = (2 * rays) / (double)window_config->window_width - 1;
	window_config->ray->rdx = window_config->player->pdx + window_config->player->planex * window_config->ray->camerax;
	window_config->ray->rdy = window_config->player->pdy + window_config->player->planey * window_config->ray->camerax;
	window_config->ray->mapx = (int)window_config->player->px;
	window_config->ray->mapy = (int)window_config->player->py;
	window_config->ray->delta_distx = fabs(1 / window_config->ray->rdx);
	window_config->ray->delta_disty = fabs(1 / window_config->ray->rdy);
}

void set_side_dist(t_win *window_config)
{
	if (window_config->ray->rdx < 0)
	{
		window_config->ray->stepx = -1;
		window_config->ray->side_distx = (window_config->player->px - window_config->ray->mapx) * window_config->ray->delta_distx;
	}
	else
	{
		window_config->ray->stepx = 1;
		window_config->ray->side_distx = (window_config->ray->mapx + 1.0 - window_config->player->px) * window_config->ray->delta_distx;
	}
	if (window_config->ray->rdy < 0)
	{
		window_config->ray->stepy = -1;
		window_config->ray->side_disty = (window_config->player->py - window_config->ray->mapy) * window_config->ray->delta_disty;
	}
	else
	{
		window_config->ray->stepy = 1;
		window_config->ray->side_disty = (window_config->ray->mapy + 1.0 - window_config->player->py) * window_config->ray->delta_disty;
	}
}

void calculate_right_wall_dist(t_win *window_config)
{
	if (window_config->ray->side == 0)
		window_config->ray->right_wall_dist = (window_config->ray->mapx - window_config->player->px + (1 - window_config->ray->stepx) / 2) / window_config->ray->rdx;
	else
		window_config->ray->right_wall_dist = (window_config->ray->mapy - window_config->player->py + (1 - window_config->ray->stepy) / 2) / window_config->ray->rdy;
	// ray->line_height = (int)(win_infos->height / ray->perp_wall_dist);
	// ray->draw_start = (-ray->line_height / 2 + ((win_infos->height / 2)
	// 	* win_infos->player->cam_height));
	// if (ray->draw_start < 0)
	// 	ray->draw_start = 0;
	// ray->draw_end = (ray->line_height / 2 + ((win_infos->height / 2)
	// 	* win_infos->player->cam_height));
	// if (ray->draw_end >= win_infos->height)
	// 	ray->draw_end = win_infos->height - 1;
}