/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_image.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdelta <gdelta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 19:42:04 by gdelta            #+#    #+#             */
/*   Updated: 2021/03/25 21:00:11 by gdelta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		pixel_put(t_image *image, int x, int y, int color)
{
	char			*dst;

	dst = image->addr + (y * image->line_length + x * (image->bpp / 8));
	*(unsigned int*)dst = color;
}

static void	ceiling_and_floor(t_win *window_config, int rays)
{
	int				y;
	int				x;

	y = -1;
	x = rays;
	while (++y < window_config->ray->draw_start)
		pixel_put(window_config->image, rays, y, window_config->ceiling_color);
	y = window_config->window_height;
	while (--y > window_config->ray->draw_end - 1)
		pixel_put(window_config->image, rays, y, window_config->floor_color);
}

int			create_image(t_win *window_config, int rays)
{
	double			wallx;
	int				texx;
	int				texy;
	double			step;
	double			texpos;
	int				y;
	unsigned int	color;
	t_image			*texture;

	if (window_config->ray->side == 0 || window_config->ray->side == 1)
		wallx = window_config->player->py + window_config->ray->wall_dist * window_config->ray->rdy;
	else
		wallx = window_config->player->px + window_config->ray->wall_dist * window_config->ray->rdx;
	wallx -= floor(wallx);
	if (window_config->ray->side == 0)
		texture = window_config->ea_tex;
	if (window_config->ray->side == 1)
		texture = window_config->we_tex;
	if (window_config->ray->side == 2)
		texture = window_config->so_tex;
	if (window_config->ray->side == 3)
		texture = window_config->no_tex;
	texx = (int)(wallx * (double)texture->width);
	if ((window_config->ray->side == 0 || window_config->ray->side == 1) && window_config->ray->rdx > 0)
		texx = texture->width - texx - 1;
	if ((window_config->ray->side == 2 || window_config->ray->side == 3) && window_config->ray->rdy < 0)
		texx = texture->width - texx - 1;


	step = 1.0 * texture->height / window_config->ray->wall_height;
	texpos = (window_config->ray->draw_start - window_config->window_height / 2 + window_config->ray->wall_height / 2) * step;

	ceiling_and_floor(window_config, rays);
	y = window_config->ray->draw_start;
	while (y < window_config->ray->draw_end)
	{
		texy = (int)texpos & (texture->height - 1);
		texpos += step;
		color = *(unsigned int*)(texture->addr + (texy * texture->line_length + texx * (texture->bpp / 8)));
		if (color == 4278190080)
			color = 0x00000000;
		pixel_put(window_config->image, rays, y, color);
		y++;
	}
	return (1);
}
