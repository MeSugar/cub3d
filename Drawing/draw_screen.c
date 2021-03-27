/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_screen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdelta <gdelta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 19:41:08 by gdelta            #+#    #+#             */
/*   Updated: 2021/03/27 14:55:50 by gdelta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	raycast(t_win *window_config, int rays)
{
	set_ray(window_config, rays);
	set_side_dist(window_config);
	find_wall(window_config);
	calculate_wall_dist_n_height(window_config);
	window_config->buff[rays] = window_config->ray->wall_dist;
	create_image(window_config, window_config->tex, rays);
}

int			draw_screen(t_win *window_config)
{
	int	rays;

	treat_buttons(window_config);
	rays = -1;
	while (++rays < window_config->win_w)
		raycast(window_config, rays);
	create_sprite(window_config);
	if (window_config->save_mode)
		create_bitmap(window_config, window_config->image);
	mlx_put_image_to_window(window_config->mlx_ptr, window_config->win_ptr,
	window_config->image->img_ptr, 0, 0);
	return (1);
}
