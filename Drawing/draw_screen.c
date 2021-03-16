#include "cub3d.h"



static void raycast(t_win *window_config, int rays)
{
    set_ray(window_config, rays);
    set_side_dist(window_config);
    find_wall(window_config);
    draw_image(window_config);
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