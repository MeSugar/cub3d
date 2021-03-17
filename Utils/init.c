#include "cub3d.h"

t_win *window_config_init(const char *config_file)
{
    t_win *new_config;

    if (!(new_config = ft_calloc(1, sizeof(t_win))))
        return (0);
    new_config->config_file = config_file;
    return (new_config);
}

int map_player_buttons_init(t_win *window_config)
{
    if (!(window_config->map = ft_calloc(1, sizeof(t_map))))
        return (put_error_msg("Error: Malloc error\n"));
    if (!(window_config->player = ft_calloc(1, sizeof(t_player))))
        return (put_error_msg("Error: Malloc error\n"));
    if (!(window_config->buttons = ft_calloc(1, sizeof(t_buttons))))
        return (put_error_msg("Error: Malloc error\n"));
    return (1);
}

int window_init(t_win *window_config)
{
    if (!(window_config->mlx_ptr = mlx_init()))
        return (put_error_msg("Error: MLX init error\n"));
    if (!(window_config->win_ptr = mlx_new_window(window_config->mlx_ptr,
    window_config->window_width, window_config->window_height, "cub3D")))
        return (put_error_msg("Error: Can't create new window\n"));
    return (1);
}

int image_init(t_win *window_config)
{
    if (!(window_config->image = ft_calloc(1, sizeof(t_image))))
        return (put_error_msg("Error: Malloc error\n"));
    if (!(window_config->image->img_ptr = mlx_new_image(window_config->mlx_ptr,
    window_config->window_width, window_config->window_height)))
        return (put_error_msg("Error: Can't create image\n"));
    if (!(window_config->image->addr = mlx_get_data_addr(window_config->image->img_ptr,
    &window_config->image->bpp, &window_config->image->line_length, &window_config->image->endian)))
        return (put_error_msg("Error: Can't get image data\n"));
    return (1);
}

int     texture_init(t_win *window_config)
{
    if (!(window_config->no = ft_calloc(1, sizeof(t_image))))
        return (put_error_msg("Error: Malloc error\n"));
    if (!(window_config->so = ft_calloc(1, sizeof(t_image))))
        return (put_error_msg("Error: Malloc error\n"));
    if (!(window_config->we = ft_calloc(1, sizeof(t_image))))
        return (put_error_msg("Error: Malloc error\n"));
    if (!(window_config->ea = ft_calloc(1, sizeof(t_image))))
        return (put_error_msg("Error: Malloc error\n"));
    if (!(window_config->sprite = ft_calloc(1, sizeof(t_image))))
        return (put_error_msg("Error: Malloc error\n"));
    return (1);
}