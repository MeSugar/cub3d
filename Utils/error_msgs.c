#include "cub3d.h"

int put_error_msg(char *error_message)
{
	ft_putstr_fd(error_message, 1);
	return (0);
}

int config_elements_check(t_win *window_config)
{
	if (!window_config->window_width || !window_config->window_height || !window_config->no_tex->img_ptr
	|| !window_config->so_tex->img_ptr || !window_config->ea_tex->img_ptr || !window_config->we_tex->img_ptr
	|| !window_config->sprite_tex->img_ptr || !window_config->ceiling_color || !window_config->floor_color)
		return (0);
	return (1);
} 