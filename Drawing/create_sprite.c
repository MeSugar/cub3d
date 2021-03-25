/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_sprite.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdelta <gdelta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 19:42:08 by gdelta            #+#    #+#             */
/*   Updated: 2021/03/26 02:22:52 by gdelta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	sort_sprites(t_sprite *sprite, t_player *player)
{
	int				i;
	double			first_dist;
	double			second_dist;
	char			*tmp;

	i = 0;
	while (i + 1 < sprite->sprites_number)
	{
		first_dist = ((player->px - sprite->spos[i][1])
		* (player->px - sprite->spos[i][1]) + (player->py - sprite->spos[i][0])
		* (player->py - sprite->spos[i][0]));
		second_dist = ((player->px - sprite->spos[i + 1][1])
		* (player->px - sprite->spos[i + 1][1])
		+ (player->py - sprite->spos[i + 1][0])
		* (player->py - sprite->spos[i + 1][0]));
		if (first_dist < second_dist)
		{
			tmp = sprite->spos[i];
			sprite->spos[i] = sprite->spos[i + 1];
			sprite->spos[i + 1] = tmp;
			i = 0;
		}
		else
			i++;
	}
}

static void	draw_sprite(t_win *w_conf, t_sprite *spr, t_image *s_tex)
{
	int				y;
	int				d;
	unsigned int	color;

	while (++spr->ver_line < spr->draw_endx)
	{
		spr->texx = (int)(s_tex->line_l * (spr->ver_line - (-spr->width
		/ 2 + spr->screenx)) * s_tex->width / spr->width) / s_tex->line_l;
		if (spr->transformy > 0 && spr->ver_line > 0 && spr->ver_line <
		w_conf->win_w && spr->transformy < w_conf->buff[spr->ver_line])
		{
			y = spr->draw_starty - 1;
			while (++y < spr->draw_endy - 1)
			{
				d = y * s_tex->line_l - w_conf->win_h
				* (s_tex->line_l / 2) + spr->height * s_tex->line_l / 2;
				spr->texy = ((d * s_tex->height) / spr->height) / s_tex->line_l;
				color = *(unsigned int*)(s_tex->addr
				+ (spr->texy * s_tex->line_l + spr->texx * (s_tex->bpp / 8)));
				if ((color & 0x00FFFFFF) != 0)
					pixel_put(w_conf->image, spr->ver_line, y, color);
			}
		}
	}
}

int			create_sprite(t_win *window_config)
{
	int			sprites;

	sort_sprites(window_config->sprite, window_config->player);
	sprites = -1;
	while (++sprites < window_config->sprite->sprites_number)
	{
		sprite_values(window_config, window_config->player,
		window_config->sprite, sprites);
		draw_sprite(window_config, window_config->sprite,
		window_config->sprite_tex);
	}
	return (1);
}
