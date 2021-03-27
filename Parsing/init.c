/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdelta <gdelta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 20:10:35 by gdelta            #+#    #+#             */
/*   Updated: 2021/03/27 14:42:06 by gdelta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_win *window_config_init(const char *config_file, int save_mode)
{
    t_win *new_config;

    if (!(new_config = ft_calloc(1, sizeof(t_win))))
    {
        put_error_msg("Error: Malloc error\n");
        return (0);
    }
    new_config->config_file = config_file;
    if (!(new_config->mlx_ptr = mlx_init()))
    {
        put_error_msg("Error: MLX init error\n");
        return (0);
    }
    if (save_mode)
        new_config->save_mode = 1;
    return (new_config);
}

int map_player_buttons_sprite_init(t_win *window_config)
{
    if (!(window_config->map = ft_calloc(1, sizeof(t_map))))
        return (put_error_msg("Error: Malloc error\n"));
    if (!(window_config->player = ft_calloc(1, sizeof(t_player))))
        return (put_error_msg("Error: Malloc error\n"));
    if (!(window_config->buttons = ft_calloc(1, sizeof(t_buttons))))
        return (put_error_msg("Error: Malloc error\n"));
    if (!(window_config->sprite = ft_calloc(1, sizeof(t_sprite))))
        return (put_error_msg("Error: Malloc error\n"));
    return (1);
}

int window_init(t_win *window_config)
{
    if (!(window_config->win_ptr = mlx_new_window(window_config->mlx_ptr,
    window_config->win_w, window_config->win_h, "cub3D")))
        return (put_error_msg("Error: Can't create new window\n"));
    return (1);
}

int image_init(t_win *window_config)
{
    if (!(window_config->image = ft_calloc(1, sizeof(t_image))))
        return (put_error_msg("Error: Malloc error\n"));
    if (!(window_config->image->img_ptr = mlx_new_image(window_config->mlx_ptr,
    window_config->win_w, window_config->win_h)))
        return (put_error_msg("Error: Can't create image\n"));
    if (!(window_config->image->addr = mlx_get_data_addr(window_config->image->img_ptr,
    &window_config->image->bpp, &window_config->image->line_l, &window_config->image->endian)))
        return (put_error_msg("Error: Can't get image data\n"));
    window_config->image->height = window_config->win_h;
    window_config->image->width = window_config->win_w;
    if (!(window_config->ray = ft_calloc(1, sizeof(t_ray))))
        return (put_error_msg("Error: Malloc error\n"));
    if (!(window_config->buff = ft_calloc(window_config->win_w, sizeof(double))))
		return (put_error_msg("Error: Malloc error\n"));
    return (1);
}

int     texture_init(t_win *window_config)
{
    // if (!(window_config->no_tex = ft_calloc(1, sizeof(t_image))))
    //     return (put_error_msg("Error: Malloc error\n"));
    // if (!(window_config->so_tex = ft_calloc(1, sizeof(t_image))))
    //     return (put_error_msg("Error: Malloc error\n"));
    // if (!(window_config->we_tex = ft_calloc(1, sizeof(t_image))))
    //     return (put_error_msg("Error: Malloc error\n"));
    // if (!(window_config->ea_tex = ft_calloc(1, sizeof(t_image))))
    //     return (put_error_msg("Error: Malloc error\n"));
    // if (!(window_config->sprite_tex = ft_calloc(1, sizeof(t_image))))
    //     return (put_error_msg("Error: Malloc error\n"));
    
    window_config->no_tex = 0;
    window_config->so_tex = 0;
    window_config->ea_tex = 0;
    window_config->we_tex = 0;
    window_config->sprite_tex = 0;
     if (!(window_config->tex = ft_calloc(1, sizeof(t_tex))))
        return (put_error_msg("Error: Malloc error\n"));
    // window_config->no_tex->img_ptr = 0;
    // window_config->so_tex->img_ptr = 0;
    // window_config->ea_tex->img_ptr = 0;
    // window_config->we_tex->img_ptr = 0;
    // window_config->sprite_tex->img_ptr = 0;
    return (1);
}