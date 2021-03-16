#include "cub3d.h"



static void raycast(t_win *window_config, int rays)
{
    set_ray(window_config, rays);
    set_side_dist(window_config);
    find_wall(window_config);
    calculate_wall_dist_n_height(window_config);
    draw_image(window_config, rays);
}

int draw_screen(t_win *window_config)
{
    t_ray *ray;
    int rays;

    rays = -1;
    window_config->player->pdx = cos(window_config->player->pa);
    window_config->player->pdy = sin(window_config->player->pa);
    if (!(ray = calloc(1, sizeof(t_ray))))
        return (put_error_msg("Error: Malloc error\n"));
    while (++rays < 2)
        raycast(window_config, rays);
    mlx_put_image_to_window(window_config->mlx_ptr, window_config->win_ptr, window_config->image->img_ptr, 0, 0);
    return (1);
}