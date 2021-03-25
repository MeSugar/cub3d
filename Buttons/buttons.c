/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buttons.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdelta <gdelta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 19:41:22 by gdelta            #+#    #+#             */
/*   Updated: 2021/03/25 20:34:15 by gdelta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		pressed_buttons(int keycode, t_win *window_config)
{
	if (keycode == ESC)
		finish_program(window_config, 1);
	if (keycode == W && !window_config->buttons->forward)
		window_config->buttons->forward = 1;
	if (keycode == S && !window_config->buttons->backward)
		window_config->buttons->backward = 1;
	if (keycode == A && !window_config->buttons->left)
		window_config->buttons->left = 1;
	if (keycode == D && !window_config->buttons->right)
		window_config->buttons->right = 1;
	if (keycode == TURN_LEFT && !window_config->buttons->turn_left)
		window_config->buttons->turn_left = 1;
	if (keycode == TURN_RIGHT && !window_config->buttons->turn_right)
		window_config->buttons->turn_right = 1;
	return (1);
}

int		released_buttons(int keycode, t_win *window_config)
{
	if (keycode == W && window_config->buttons->forward)
		window_config->buttons->forward = 0;
	if (keycode == S && window_config->buttons->backward)
		window_config->buttons->backward = 0;
	if (keycode == A && window_config->buttons->left)
		window_config->buttons->left = 0;
	if (keycode == D && window_config->buttons->right)
		window_config->buttons->right = 0;
	if (keycode == TURN_LEFT && window_config->buttons->turn_left)
		window_config->buttons->turn_left = 0;
	if (keycode == TURN_RIGHT && window_config->buttons->turn_right)
		window_config->buttons->turn_right = 0;
	return (1);
}

void	treat_buttons(t_win *window_config)
{
	if (window_config->buttons->forward)
		move_forward(window_config->map, window_config->player);
	if (window_config->buttons->backward)
		move_backward(window_config->map, window_config->player);
	if (window_config->buttons->left)
		move_left(window_config->map, window_config->player);
	if (window_config->buttons->right)
		move_right(window_config->map, window_config->player);
	if (window_config->buttons->turn_left)
		turn_left(window_config->player);
	if (window_config->buttons->turn_right)
		turn_right(window_config->player);
}
