#include "cub3d.h"

static void raycast(t_win *window_config, int rays)
{
    set_ray(window_config, rays);
    set_side_dist(window_config);
    find_wall(window_config);
    calculate_wall_dist_n_height(window_config);
    draw_image(window_config, rays);
}

static void clear(t_win *window_config)
{
    int x = 0;
    int y;
    while (x < window_config->window_width)
        {
            y = 0;
            while (y < window_config->window_height)
            {
                pixel_put(window_config->image, x, y, 0x00000000);
                y++;
            }
            x++;
        }
}

int draw_screen(t_win *window_config)
{
    int rays;

    rays = -1;
    clear(window_config);
    if (!(window_config->ray = calloc(1, sizeof(t_ray))))
        return (put_error_msg("Error: Malloc error\n"));
    while (++rays < window_config->window_width)
        raycast(window_config, rays);
    mlx_put_image_to_window(window_config->mlx_ptr, window_config->win_ptr, window_config->image->img_ptr, 0, 0);
    free(window_config->ray);
    return (1);
}