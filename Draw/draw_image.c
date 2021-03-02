#include "cub3d.h"

static void pixel_put(t_image *image, int x, int y, int color)
{
    char *dst;

    dst = image->addr + (y * image->line_length + x * (image->bpp / 8));
    *(unsigned int*)dst = color;
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
    pixel_put(window_config->image, 250, 250, 0x00FF0000);
    mlx_put_image_to_window(window_config->mlx_ptr, window_config->win_ptr, window_config->image->img_ptr, 0, 0);
    mlx_loop(window_config->mlx_ptr);
    return (1);
}