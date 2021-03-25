/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_screen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdelta <gdelta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 19:41:08 by gdelta            #+#    #+#             */
/*   Updated: 2021/03/25 20:02:21 by gdelta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void raycast(t_win *window_config, int rays)
{
    set_ray(window_config, rays);
    set_side_dist(window_config);
    find_wall(window_config);
    calculate_wall_dist_n_height(window_config);
    window_config->buff[rays] = window_config->ray->wall_dist;
    create_image(window_config, rays);
}

// static void clear(t_win *window_config)
// {
//     int x = 0;
//     int y;
//     while (x < window_config->window_width)
//         {
//             y = 0;
//             while (y < window_config->window_height)
//             {
//                 pixel_put(window_config->image, x, y, 0x00000000);
//                 y++;
//             }
//             x++;
//         }
// }

int draw_screen(t_win *window_config)
{
    int rays;

    
    // clear(window_config);
    // if (!(window_config->ray = ft_calloc(1, sizeof(t_ray))))
    //     return (put_error_msg("Error: Malloc error\n"));
    // if (!(window_config->buff = ft_calloc(window_config->window_width, sizeof(double))))
	// 	return (put_error_msg("Error: Malloc error\n"));
    rays = -1;
    while (++rays < window_config->window_width)
        raycast(window_config, rays);
    create_sprite(window_config);
    if (window_config->save_mode)
        create_bitmap(window_config, window_config->image);
    // draw_image(window_config, rays);
    // draw_map(window_config, window_config->buff);
    mlx_put_image_to_window(window_config->mlx_ptr, window_config->win_ptr, window_config->image->img_ptr, 0, 0);
    treat_buttons(window_config);
    // free(window_config->ray);
    // free(window_config->buff);
    return (1);
}