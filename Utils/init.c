#include "cub3d.h"

t_win *window_config_init(const char *config_file)
{
    t_win *new_config;

    if (!(new_config = ft_calloc(1, sizeof(t_win))))
        return (0);
    new_config->config_file = config_file;
    // new_config->window_width = 0;
	// new_config->window_height = 0;
    // new_config->ceiling_color = 0;
    // new_config->floor_color = 0;
    return (new_config);
}

int map_player_buttons_init(t_win *window_config)
{
    if (!(window_config->map = calloc(1, sizeof(t_map))))
        return (0);
    // window_config->map->map_exists = 0;
    // window_config->map->width = 0;
    // window_config->map->height = 0;
    // window_config->mapp = 0;
    if (!(window_config->player = calloc(1, sizeof(t_player))))
        return (0);
    // window_config->player->px = 0;
    // window_config->player->py = 0;
    // window_config->player->pdx = 0;
    // window_config->player->pdy = 0;
    // window_config->player->planex = 0;
    // window_config->player->planey = 0;
    // window_config->player->pa = 0;
    // window_config->player->players_number = 0;
    if (!(window_config->buttons = calloc(1, sizeof(t_buttons))))
        return (0);
    // window_config->buttons->forward = 0;
    // window_config->buttons->backward = 0;
    // window_config->buttons->left = 0;
    // window_config->buttons->right = 0;
    // window_config->buttons->turn_left = 0;
    // window_config->buttons->turn_right = 0;
    return (1);
}

int window_init(t_win *window_config)
{
    if (!(window_config->mlx_ptr = mlx_init()))
        return (0);
    if (!(window_config->win_ptr = mlx_new_window(window_config->mlx_ptr,
    window_config->window_width, window_config->window_height, "cub3D")))
        return (0);
    return (1);
}

int image_init(t_win *window_config)
{
    if (!(window_config->image = calloc(1, sizeof(t_image))))
        return (put_error_msg("Error: Malloc error\n"));
    if (!(window_config->image->img_ptr = mlx_new_image(window_config->mlx_ptr,
    window_config->window_width, window_config->window_height)))
        return (put_error_msg("Error: Malloc error\n"));
    window_config->image->addr = mlx_get_data_addr(window_config->image->img_ptr,
    &window_config->image->bpp, &window_config->image->line_length, &window_config->image->endian);
    return (1);
}
