/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_sprite.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdelta <gdelta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 19:42:08 by gdelta            #+#    #+#             */
/*   Updated: 2021/03/25 21:07:32 by gdelta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	sort_sprites(t_sprite *sprite, t_player *player)
{
	int		i;
	double	first_dist;
	double	second_dist;
	char	*tmp;

	i = 0;
	while (i + 1 < sprite->sprites_number)
	{
		first_dist = ((player->px - sprite->spr_pos[i][1])
		* (player->px - sprite->spr_pos[i][1])
		+ (player->py - sprite->spr_pos[i][0])
		* (player->py - sprite->spr_pos[i][0]));
		second_dist = ((player->px - sprite->spr_pos[i + 1][1])
		* (player->px - sprite->spr_pos[i + 1][1])
		+ (player->py - sprite->spr_pos[i + 1][0])
		* (player->py - sprite->spr_pos[i + 1][0]));
		if (first_dist < second_dist)
		{
			tmp = sprite->spr_pos[i];
			sprite->spr_pos[i] = sprite->spr_pos[i + 1];
			sprite->spr_pos[i + 1] = tmp;
			i = 0;
		}
		else
			i++;
	}
}

static void draw_sprite(t_win *window_config, int sprites)
{
    int y;
    int d;
    unsigned int color;

    set_sprite(window_config, window_config->player, window_config->sprite, sprites);
    while (++window_config->sprite->ver_line < window_config->sprite->draw_endx)
	{   
		window_config->sprite->texx = (int)(window_config->sprite_tex->line_length * (window_config->sprite->ver_line - 
        (-window_config->sprite->width / 2 + window_config->sprite->sprite_screenx)) * window_config->sprite_tex->width / window_config->sprite->width) / 
        window_config->sprite_tex->line_length;

		if (window_config->sprite->transformy > 0 && window_config->sprite->ver_line > 0 && window_config->sprite->ver_line < window_config->window_width 
        && window_config->sprite->transformy < window_config->buff[window_config->sprite->ver_line])
		{
			y = window_config->sprite->draw_starty - 1;
			while (++y < window_config->sprite->draw_endy - 1)
			{
                d = y * window_config->sprite_tex->line_length - window_config->window_height * (window_config->sprite_tex->line_length / 2) +
                window_config->sprite->height * window_config->sprite_tex->line_length / 2;
                window_config->sprite->texy = ((d * window_config->sprite_tex->height) / window_config->sprite->height) / window_config->sprite_tex->line_length;
                color = *(unsigned int*)(window_config->sprite_tex->addr + (window_config->sprite->texy * window_config->sprite_tex->line_length +
                window_config->sprite->texx * (window_config->sprite_tex->bpp / 8)));
                if ((color & 0x00FFFFFF) != 0)
                    pixel_put(window_config->image, window_config->sprite->ver_line, y, color);
			}
		}
	}
}

int create_sprite(t_win* window_config)
{
    int sprites;
    sort_sprites(window_config->sprite, window_config->player);
    sprites = -1;
    while (++sprites < window_config->sprite->sprites_number)
    {
       draw_sprite(window_config, sprites);
    }
    return (1);
}