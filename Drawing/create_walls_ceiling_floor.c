/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_walls_ceiling_floor.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdelta <gdelta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 19:42:04 by gdelta            #+#    #+#             */
/*   Updated: 2021/03/27 14:51:34 by gdelta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		pixel_put(t_image *image, int x, int y, int color)
{
	char			*dst;

	dst = image->addr + (y * image->line_l + x * (image->bpp / 8));
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
	y = window_config->win_h;
	while (--y > window_config->ray->draw_end - 1)
		pixel_put(window_config->image, rays, y, window_config->floor_color);
}

static void	set_tex_values(t_win *window_config, t_image *texture,
t_tex *tex, double wallx)
{
	if (window_config->ray->side == 0 || window_config->ray->side == 1)
		wallx = window_config->player->py + window_config->ray->wall_dist
		* window_config->ray->rdy;
	else
		wallx = window_config->player->px + window_config->ray->wall_dist
		* window_config->ray->rdx;
	wallx -= floor(wallx);
	tex->texx = (int)(wallx * (double)texture->width);
	if ((window_config->ray->side == 0 || window_config->ray->side == 1)
	&& window_config->ray->rdx > 0)
		tex->texx = texture->width - tex->texx - 1;
	if ((window_config->ray->side == 2 || window_config->ray->side == 3)
	&& window_config->ray->rdy < 0)
		tex->texx = texture->width - tex->texx - 1;
	tex->step = 1.0 * texture->height / window_config->ray->wall_height;
	tex->texpos = (window_config->ray->draw_start - window_config->win_h / 2
	+ window_config->ray->wall_height / 2) * tex->step;
	tex->y = window_config->ray->draw_start;
}

int			create_image(t_win *window_config, t_tex *tex, int rays)
{
	unsigned int	color;
	t_image			*texture;

	if (window_config->ray->side == 0)
		texture = window_config->ea_tex;
	if (window_config->ray->side == 1)
		texture = window_config->we_tex;
	if (window_config->ray->side == 2)
		texture = window_config->so_tex;
	if (window_config->ray->side == 3)
		texture = window_config->no_tex;
	ceiling_and_floor(window_config, rays);
	set_tex_values(window_config, texture, window_config->tex, tex->wallx);
	while (tex->y < window_config->ray->draw_end)
	{
		tex->texy = (int)tex->texpos & (texture->height - 1);
		tex->texpos += tex->step;
		color = *(unsigned int*)(texture->addr + (tex->texy * texture->line_l
		+ tex->texx * (texture->bpp / 8)));
		if (color == 4278190080)
			color = 0x00000000;
		pixel_put(window_config->image, rays, tex->y, color);
		tex->y++;
	}
	return (1);
}
