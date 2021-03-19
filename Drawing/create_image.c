#include "cub3d.h"

void pixel_put(t_image *image, int x, int y, int color)
{
    char *dst;

    dst = image->addr + (y * image->line_length + x * (image->bpp / 8));
    *(unsigned int*)dst = color;
}



// void draw_map(t_win *window_config, int rays)
// {
//     int x;
//     int y;
//     int color = 0x00FF0000;
//     if (window_config->ray->side == 1)
//         color /= 3;
//     x = rays;
//     y = window_config->ray->draw_start;
//     while (y < window_config->ray->draw_end)
//     {
//         pixel_put(window_config->image, x, y, color);
//         y++;
//     }
// }

void draw_map(t_win *window_config, char **buff)
{
    int x = 0;
    int y = 0;
    int i = 0;
    int j = 0;
    while (buff[y])
    {
        x = 0;
        i = 0;
        while (x < window_config->window_width)
        {
            if (buff[y][x] == 0)
            {
                x++;
                i++;
            }
            else
            {
                pixel_put(window_config->image, i, j, buff[y][x]);
                x++;
                i++;
            }
        }
        y++;
        j++;
    }
    i = 0;
}

int draw_image(t_win *window_config, int rays)
{
    double wallx;
    int    texx;
    int    texy;
    double step;
    double texpos;
    int y;
    int color;
    

    if (window_config->ray->side == 0)
		wallx = window_config->player->py + window_config->ray->wall_dist * window_config->ray->rdy;
	else
        wallx = window_config->player->px + window_config->ray->wall_dist * window_config->ray->rdx;
	wallx -= floor(wallx);


    texx = (int)(wallx * (double)window_config->so->width);
	if (window_config->ray->side == 0 && window_config->ray->rdx > 0)
		texx = window_config->so->width - texx - 1;
	if (window_config->ray->side == 1 && window_config->ray->rdy < 0)
		texx = window_config->so->width - texx - 1;


    step = 1.0 * window_config->so->height / window_config->ray->wall_height;
    texpos = (window_config->ray->draw_start - window_config->window_height / 2 + window_config->ray->wall_height / 2) * step;
    
    
    y = window_config->ray->draw_start;
    while (y < window_config->ray->draw_end)
    {
        texy = (int)texpos & (window_config->so->height - 1);
        texpos += step;
        color = (unsigned int)(*(window_config->so->addr + (texy * window_config->so->line_length + texx * (window_config->so->bpp / 8))));
        window_config->buff[y][rays] = color;
        y++;
    }
//     // draw_map(window_config, rays);
    return (1);
}