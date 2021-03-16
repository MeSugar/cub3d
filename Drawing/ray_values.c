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

void find_wall(t_win *window_config)
{
    while (!window_config->ray->hit)
    {
        if (window_config->ray->side_distx < window_config->ray->side_disty)
        {
            window_config->ray->side_distx += window_config->ray->delta_distx;
            window_config->ray->mapx += window_config->ray->stepx;
            window_config->ray->side = 0;
        }
        else
        {
            window_config->ray->side_disty += window_config->ray->delta_disty;
            window_config->ray->mapy += window_config->ray->stepy;
            window_config->ray->side = 1;
        }
        if (window_config->map->map[window_config->ray->mapy][window_config->ray->mapx] == '1') 
            window_config->ray->hit = 1;
    }
}

void calculate_wall_dist_n_height(t_win *window_config)
{
	if (window_config->ray->side == 0)
		window_config->ray->wall_dist = (window_config->ray->mapx - window_config->player->px + (1 - window_config->ray->stepx) / 2) / window_config->ray->rdx;
	else
		window_config->ray->wall_dist = (window_config->ray->mapy - window_config->player->py + (1 - window_config->ray->stepy) / 2) / window_config->ray->rdy;
	window_config->ray->wall_height = (int)(window_config->window_height / window_config->ray->wall_dist);
	window_config->ray->draw_start = (-window_config->ray->wall_height / 2 + window_config->window_height / 2);
	if (window_config->ray->draw_start < 0)
		window_config->ray->draw_start = 0;
	window_config->ray->draw_end = (window_config->ray->wall_height / 2 + window_config->window_height / 2);
	if (window_config->ray->draw_end >= window_config->window_height)
		window_config->ray->draw_end = window_config->window_height - 1;
}