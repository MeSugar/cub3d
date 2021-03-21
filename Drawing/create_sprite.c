#include "cub3d.h"

static void sort_sprites(t_win *window_config)
{
    int i;
    double first_dist;
    double second_dist;
    char *tmp;

    i = 0;
    while (i + 1 < window_config->sprite->sprites_number)
    {
        first_dist = ((window_config->player->px - window_config->sprite->sprites_pos[i][1]) * (window_config->player->px - window_config->sprite->sprites_pos[i][1]) +
        (window_config->player->py - window_config->sprite->sprites_pos[i][0]) * (window_config->player->py - window_config->sprite->sprites_pos[i][0]));
        second_dist = ((window_config->player->px - window_config->sprite->sprites_pos[i + 1][1]) * (window_config->player->px - window_config->sprite->sprites_pos[i + 1][1]) +
        (window_config->player->py - window_config->sprite->sprites_pos[i + 1][0]) * (window_config->player->py - window_config->sprite->sprites_pos[i + 1][0]));
        if (first_dist < second_dist)
		{
			tmp = window_config->sprite->sprites_pos[i];
			window_config->sprite->sprites_pos[i] = window_config->sprite->sprites_pos[i + 1];
			window_config->sprite->sprites_pos[i + 1] = tmp;
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
			while (++y < window_config->sprite->draw_endy)
			{
                d = y * window_config->sprite_tex->line_length - window_config->window_height * (window_config->sprite_tex->line_length / 2) +
                window_config->sprite->height * window_config->sprite_tex->line_length / 2;
                window_config->sprite->texy = ((d * window_config->sprite_tex->height) / window_config->sprite->height) / window_config->sprite_tex->line_length;
                color = *(unsigned int*)(window_config->sprite_tex->addr + (window_config->sprite->texy * window_config->sprite_tex->line_length +
                window_config->sprite->texx * (window_config->sprite_tex->bpp / 8)));
                if ((color & 0x0FFFFFF) != 0)
                    pixel_put(window_config->image, window_config->sprite->ver_line, y, color);
                // else
                //     pixel_put(window_config->image, window_config->sprite->ver_line, y, color);
                
                
			}
		}
	}
}

int create_sprite(t_win* window_config)
{
    int sprites;
    sort_sprites(window_config);
    sprites = -1;
    while (++sprites < window_config->sprite->sprites_number)
    {
       draw_sprite(window_config, sprites);
    }
    return (1);
}