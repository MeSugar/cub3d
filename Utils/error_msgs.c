/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_msgs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdelta <gdelta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 20:11:00 by gdelta            #+#    #+#             */
/*   Updated: 2021/03/26 02:03:52 by gdelta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int put_error_msg(char *error_message)
{
	ft_putstr_fd(error_message, 1);
	return (0);
}

int config_elements_check(t_win *window_config)
{
	if (!window_config->win_w || !window_config->win_h || !window_config->no_tex
	|| !window_config->so_tex || !window_config->ea_tex || !window_config->we_tex
	|| !window_config->sprite_tex || !window_config->ceiling_color || !window_config->floor_color)
		return (0);
	return (1);
} 