#include "cub3d.h"

t_win *window_config_init(const char *config_file)
{
    t_win *new_config;

    if (!(new_config = ft_calloc(1, sizeof(t_win))))
        return (0);
    new_config->config_file = config_file;
    new_config->window_width = 0;
	new_config->window_height = 0;
    new_config->ceiling_color = 0;
    new_config->floor_color = 0;
    return (new_config);
}

int map_player_keys_init(t_win *window_config)
{
    if (!(window_config->map = calloc(1, sizeof(t_map))))
        return (0);
    window_config->map->map_exists = 0;
    window_config->map->width = 0;
    window_config->map->height = 0;
    window_config->mapp = 0;
    if (!(window_config->player = calloc(1, sizeof(t_player))))
        return (0);
    window_config->player->px = 0;
    window_config->player->py = 0;
    window_config->player->players_number = 0;
    if (!(window_config->keys = calloc(1, sizeof(t_keys))))
        return (0);
    window_config->keys->forward = 0;
    window_config->keys->backward = 0;
    window_config->keys->left = 0;
    window_config->keys->right = 0;
    window_config->keys->turn_left = 0;
    window_config->keys->turn_right = 0;
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