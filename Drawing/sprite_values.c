/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_values.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdelta <gdelta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 20:09:20 by gdelta            #+#    #+#             */
/*   Updated: 2021/03/26 02:28:21 by gdelta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	set_sprite(t_win *window_config, t_sprite *sprite)
{
	if (sprite->draw_starty < 0)
		sprite->draw_starty = 0;
	sprite->draw_endy = sprite->height / 2 + window_config->win_h / 2;
	if (sprite->draw_endy >= window_config->win_h)
		sprite->draw_endy = window_config->win_h - 1;
	sprite->width = abs((int)(window_config->win_h / sprite->transformy));
	sprite->draw_startx = -sprite->width / 2 + sprite->screenx;
	if (sprite->draw_startx < 0)
		sprite->draw_startx = 0;
	sprite->draw_endx = sprite->width / 2 + sprite->screenx;
	if (sprite->draw_endx >= window_config->win_w)
		sprite->draw_endx = window_config->win_w - 1;
	sprite->ver_line = sprite->draw_startx - 1;
}

void		sprite_values(t_win *window_config, t_player *player,
t_sprite *sprite, int i)
{
	sprite->spritex = sprite->spos[i][1] - player->px + 0.5;
	sprite->spritey = sprite->spos[i][0] - player->py + 0.5;
	sprite->invdet = 1.0 / (player->planex * player->pdy
	- player->pdx * player->planey);
	sprite->transformx = sprite->invdet * (player->pdy
	* sprite->spritex - player->pdx * sprite->spritey);
	sprite->transformy = sprite->invdet * (-player->planey
	* sprite->spritex + player->planex * sprite->spritey);
	sprite->screenx = (int)((window_config->win_w / 2)
	* (1 + sprite->transformx / sprite->transformy));
	sprite->height = abs((int)(window_config->win_h / sprite->transformy));
	sprite->draw_starty = -sprite->height / 2 + window_config->win_h / 2;
	set_sprite(window_config, sprite);
}
