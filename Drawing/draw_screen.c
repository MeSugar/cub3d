#include "cub3d.h"

static void find_wall(t_win *window_config)
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
        if (window_config->map->map[window_config->ray->mapx][window_config->ray->mapy] == '1') 
            window_config->ray->hit = 1;
    }
}

static void raycast(t_win *window_config, int rays)
{
    set_ray(window_config, rays);
    set_side_dist(window_config);
    find_wall(window_config);
}

int draw_screen(t_win *window_config)
{
    int rays;

    rays = -1;
    if (!(window_config->ray = calloc(1, sizeof(t_ray))))
        return (put_error_msg("Error: Malloc error\n"));
    while (++rays < window_config->window_width)
        raycast(window_config, rays);
    return (1);
}