#include "cub3d.h"

void pixel_put(t_image *image, int x, int y, int color)
{
    char *dst;

    // if (window_config->ray->side == 1)

    dst = image->addr + (y * image->line_length + x * (image->bpp / 8));
    *(unsigned int*)dst = color;
}

static void draw_map(t_win *window_config, int rays)
{
    int x;
    int y;
    int color = 0x00FF0000;
    if (window_config->ray->side == 1)
        color /= 3;
    // while (x < window_config->window_width)
    // {
        // y = window_config->ray->draw_start;
        x = rays;
        y = window_config->ray->draw_start;
        while (y < window_config->ray->draw_end)
        {
            pixel_put(window_config->image, x, y, color);
            y++;
        }
    // }
    // int x;
    // int y;
    // int w;
    // int h;
    // int h2;
    // int w2;
    // char **tab;

    // x = 0;
    // y = 0;
    // w = 200;
    // h = 200;
    // h2 = h;
    // w2 = w;
    // tab = window_config->map->map;
    // while (tab[x])
    // {
    //     while (tab[x][y])
    //     {
    //         if (tab[x][y] == '1')
    //         {
    //             while (w < w2 + 20)
    //             {
    //                 h = h2;
    //                 while (h < h2 + 20)
    //                 {
    //                     pixel_put(window_config->image, w, h, 0x00FF0000);
    //                     h++;
    //                 }
    //                 w++;
    //             }
    //         }
    //         else if (tab[x][y] == '2')
    //         {
    //             while (w < w2 + 20)
    //             {
    //                 h = h2;
    //                 while (h < h2 + 20)
    //                 {
    //                     pixel_put(window_config->image, w, h, 0x0000FF00);
    //                     h++;
    //                 }
    //                 w++;
    //             }
    //         }
    //         else
    //             w += 20;
    //         y++;
    //         w2 = w;
    //     }
    //     x++;
    //     y = 0;
    //     h2 += 20;
    //     w = 200;
    //     w2 = w;
    // }
}

// static void draw_player(t_win *window_config, t_player *player)
// {
//     int w;
//     int h;

//     w = 0;
//     h = 0;
//     while (h < 15)
//     {
//         w = 0;
//         while (w < 15)
//         {
//             pixel_put(window_config->image, player->px * 20 + 200 + w, player->py * 20 + 180 + h, 0x000000FF);
//                 w++;
//         }
//         h++;
//     }
//     h = 0;
//     while (h < 15)
//     {
//         w = 0;
//         while (w < 4)
//         {
//             pixel_put(window_config->image, player->px * 20 + player->pdx + 200 + w, player->py * 20 + player->pdy + 180 + h, 0x0000FF0F);
//                 w++;
//         }
//         h++;
//     }
// }

int draw_image(t_win *window_config, int rays)
{
    draw_map(window_config, rays);
    // draw_player(window_config, window_config->player);
    
    return (1);
}