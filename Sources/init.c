#include "cub3d.h"

t_win *window_config_init(const char *config_file)
{
    t_win *new_config;

    if (!(new_config = ft_calloc(1, sizeof(t_win))))
        return (0);
    new_config->config_file = config_file;
    new_config->window_width = 500;
	new_config->window_height = 500;
    if (!(new_config->mlx_ptr = mlx_init()))
        return (0);
    if (!(new_config->mlx_ptr = mlx_new_window(new_config->mlx_ptr, new_config->window_width, new_config->window_height, "cub3D")))
        return (0);
    return (new_config);
}

int map_init(t_win *window_config)
{
    if (!(window_config->map = calloc(1, sizeof(t_map))))
        return (0);
    window_config->map->map_exists = 0;
    window_config->mapp = 0;
    return (1);
}
