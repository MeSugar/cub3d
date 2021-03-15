#include "cub3d.h"

static void start_ray(t_win *window_config, int rays)
{
    window_config->ray->camerax = (2 * rays) / (double)window_config->window_width - 1;
	window_config->ray->rdx = window_config->player->pdx + window_config->player->planex * window_config->ray->camerax;
	window_config->ray->rdy = window_config->player->pdy + window_config->player->planey * window_config->ray->camerax;
	window_config->ray->mapx = (int)window_config->player->px;
	window_config->ray->mapy = (int)window_config->player->py;
	window_config->ray->delta_distx = fabs(1 / window_config->ray->rdx);
	window_config->ray->delta_disty = fabs(1 / window_config->ray->rdy);
}

static void raycast(t_win *window_config)
{

}


int draw_screen(t_win *window_config)
{
    int rays;

    rays = -1;
    while (++rays < window_config->window_width)
        draw_ray(window_config, rays);
    return (1);
}