#include "cub3d.h"

void pixel_put(t_image *image, int x, int y, int color)
{
    char *dst;

    dst = image->addr + (y * image->line_length + x * (image->bpp / 8));
    *(unsigned int*)dst = color;
}



static void draw_map(t_win *window_config, int rays, char **screen_buf)
{
    // int x;
    // int y;
    // int color = 0x00FF0000;
    // if (window_config->ray->side == 1)
    //     color /= 3;
    // x = rays;
    // y = window_config->ray->draw_start;
    // while (y < window_config->ray->draw_end)
    // {
    //     pixel_put(window_config->image, x, y, color);
    //     y++;
    // }
    int x = 0;
    int y = 0;
    
    while (screen_buf[x])
    {
        y = 0;
        while (screen_buf[y][x])
        {
            pixel_put(window_config->image, y, x, screen_buf[y][x]);
            y++;
        }
        x++;
    }
}

int draw_image(t_win *window_config, int rays)
{
    double wallx;
    int    texx;
    int    texy;
    char **screen_buf;
    int i;
    double step;
    double texpos;
    int y;
    int color;
    
    if (!(screen_buf = ft_calloc(window_config->window_height, sizeof(int *))))
        return (put_error_msg("Error: Malloc error\n"));
    i = 0;
    while (i < window_config->window_height)
    {
        if (!(screen_buf[i] = ft_calloc(window_config->window_width, sizeof(int))))
            return (put_error_msg("Error: Malloc error\n"));
        i++;
    }
    if (window_config->ray->side == 0)
		wallx = window_config->player->py + window_config->ray->wall_dist * window_config->ray->rdy;
	else
        wallx = window_config->player->px + window_config->ray->wall_dist * window_config->ray->rdx;
	wallx -= floor(wallx);
    texx = (int)(wallx * (double)window_config->no->width);
	if (window_config->ray->side == 0 && window_config->ray->rdx > 0)
		texx = window_config->no->width - texx - 1;
	if (window_config->ray->side == 1 && window_config->ray->rdy < 0)
		texx = window_config->no->width - texx - 1;
    step = 1.0 * window_config->no->height / window_config->ray->wall_height;
    texpos = (window_config->ray->draw_start - window_config->window_height / 2 + window_config->ray->wall_height / 2) * step;
    y = window_config->ray->draw_start;
    while (y < window_config->ray->draw_end)
    {
        texy = (int)texpos & (window_config->no->height - 1);
        texpos += step;
        color = window_config->no->addr[texy * window_config->no->line_length * texx * (window_config->no->bpp / 8)];
        screen_buf[y][rays] = color;
        y++;
    }
    draw_map(window_config, rays, screen_buf);
    return (1);
}