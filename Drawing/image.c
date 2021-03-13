#include "cub3d.h"

static void pixel_put(t_image *image, int x, int y, int color)
{
    char *dst;

    dst = image->addr + (y * image->line_length + x * (image->bpp / 8));
    *(unsigned int*)dst = color;
}

static void draw_map(t_win *window_config)
{
    int x;
    int y;
    int w;
    int h;
    int h2;
    int w2;
    char **tab;

    x = 0;
    y = 0;
    w = 200;
    h = 200;
    h2 = h;
    w2 = w;
    tab = window_config->map->map;
    while (tab[x])
    {
        while (tab[x][y])
        {
            if (tab[x][y] == '1')
            {
                while (w < w2 + 20)
                {
                    h = h2;
                    while (h < h2 + 20)
                    {
                        pixel_put(window_config->image, w, h, 0x00FF0000);
                        h++;
                    }
                    w++;
                }
            }
            else if (tab[x][y] == '2')
            {
                while (w < w2 + 20)
                {
                    h = h2;
                    while (h < h2 + 20)
                    {
                        pixel_put(window_config->image, w, h, 0x0000FF00);
                        h++;
                    }
                    w++;
                }
            }
            else
                w += 20;
            y++;
            w2 = w;
        }
        x++;
        y = 0;
        h2 += 20;
        w = 200;
        w2 = w;
    }
}

static void draw_player(t_win *window_config, t_player *player)
{
    int w;
    int h;

    w = 0;
    h = 0;
    while (h < 15)
    {
        w = 0;
        while (w < 15)
        {
            pixel_put(window_config->image, player->px * 20 + 200 + w, player->py * 20 + 180 + h, 0x000000FF);
                w++;
        }
        h++;
    }
}

int draw_image(t_win *window_config)
{
    if (!(window_config->image = calloc(1, sizeof(t_image))))
        return (0);
    if (!(window_config->image->img_ptr = mlx_new_image(window_config->mlx_ptr,
    window_config->window_width, window_config->window_height)))
        return (0);
    window_config->image->addr = mlx_get_data_addr(window_config->image->img_ptr,
    &window_config->image->bpp, &window_config->image->line_length, &window_config->image->endian);
    draw_map(window_config);
    draw_player(window_config, window_config->player);
    mlx_put_image_to_window(window_config->mlx_ptr, window_config->win_ptr, window_config->image->img_ptr, 0, 0);
    return (1);
}