/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdelta <gdelta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 20:11:21 by gdelta            #+#    #+#             */
/*   Updated: 2021/03/25 20:11:24 by gdelta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
int name_check(char *av, char *cub)
{
    int i;

    i = 0;
    if (*av == '.' && *(av + 1) == '/')
        av++;
    while(*av && *av != '.')
        av++;
    if (*av != '.' || !ft_strnstr(av, cub, 4))
        return (put_error_msg("Error: Invalid texture file name\n"));
    return (1);
}

static int save_flag_check(char *av, char *save)
{

    int i;
    int len;

    i = 0;
    len = ft_strlen(av);
    if (len == 6 && !ft_strncmp(av, save, len))
        return (1);
    else
        return (put_error_msg("Error: Invalid flag\n"));
}

static int loop(t_win *window_config)
{
    mlx_hook(window_config->win_ptr, 2, 1L << 0, pressed_buttons, window_config);
    mlx_hook(window_config->win_ptr, 3, 1L << 1, released_buttons, window_config);
    mlx_hook(window_config->win_ptr, 17, 1L << 17, finish_program, window_config);
    mlx_loop_hook(window_config->mlx_ptr, draw_screen, window_config);
    mlx_loop(window_config->mlx_ptr);
    return (1);
}

int main(int ac, char **av)
{
    t_win *window_config;

    if (ac == 2 && name_check(av[1], ".cub"))
    {
        if (!(window_config = window_config_init(av[1], 0))
        || !map_player_buttons_sprite_init(window_config)
        // || !texture_init(window_config)
        || !config_parser(window_config)
        || !window_init(window_config)
        || !image_init(window_config))
        {
            finish_program(window_config, 1);
            return (0);
        }
        loop(window_config);
    }
    else if (ac == 3 && name_check(av[1], ".cub") && save_flag_check(av[2], "--save"))
    {
        if (!(window_config = window_config_init(av[1], 1))
        || !map_player_buttons_sprite_init(window_config)
        // || !texture_init(window_config)
        || !config_parser(window_config)
        || !window_init(window_config)
        || !image_init(window_config)
        || !draw_screen(window_config))
        {
            finish_program(window_config, 1);
            return (0);
        }
    }
    else
        return (0);
}
