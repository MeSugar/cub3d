/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finish_program.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdelta <gdelta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 20:11:08 by gdelta            #+#    #+#             */
/*   Updated: 2021/03/27 19:28:15 by gdelta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	finish_program(t_win *window_config, int mode)
{
	if (mode && window_config->win_ptr)
		mlx_destroy_window(window_config->mlx_ptr, window_config->win_ptr);
	free(window_config->map);
	free(window_config->player);
	free(window_config->image);
	free(window_config->sprite);
	free(window_config->no_tex);
	free(window_config->so_tex);
	free(window_config->ea_tex);
	free(window_config->we_tex);
	free(window_config->sprite_tex);
	free(window_config);
	exit(0);
	return (0);
}
