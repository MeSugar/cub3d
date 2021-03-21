#include "cub3d.h"

void set_sprite(t_win *window_config, t_player *player, t_sprite *sprite, int i)
{
    sprite->spritex =  sprite->sprites_pos[i][1] - player->px;
    sprite->spritey =  sprite->sprites_pos[i][0] - player->py;

    sprite->invdet = 1.0 / (player->planex * player->pdy - player->pdx * player->planey);
    sprite->transformx = sprite->invdet * (player->pdy * sprite->spritex - player->pdx * sprite->spritey);
	sprite->transformy = sprite->invdet * (-player->planey * sprite->spritex + player->planex * sprite->spritey);
	sprite->sprite_screenx = (int)((window_config->window_width / 2) * (1 + sprite->transformx / sprite->transformy));
    
    sprite->height = abs((int)(window_config->window_height / sprite->transformy));
	sprite->draw_starty = -sprite->height / 2 + window_config->window_height / 2;
	if (sprite->draw_starty < 0)
		sprite->draw_starty = 0;
	sprite->draw_endy = sprite->height / 2 + window_config->window_height / 2;
	if (sprite->draw_endy >= window_config->window_height)
		sprite->draw_endy = window_config->window_height - 1;

	sprite->width = abs((int)(window_config->window_height / sprite->transformy));
	sprite->draw_startx = -sprite->width / 2 + sprite->sprite_screenx;
	if (sprite->draw_startx < 0)
		sprite->draw_startx = 0;
	sprite->draw_endx = sprite->width / 2 + sprite->sprite_screenx;
	if (sprite->draw_endx >= window_config->window_width)
		sprite->draw_endx = window_config->window_width - 1;
	sprite->ver_line = sprite->draw_startx;   
}