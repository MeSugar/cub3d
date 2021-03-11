#include "cub3d.h"

void close_window(t_win *window_config)
{
    mlx_destroy_window(window_config->mlx_ptr, window_config->win_ptr);
    exit (0);
}

int pressed_keys(int keycode, t_win *window_config)
{
    if (keycode == ESC)
        close_window(window_config);
	if (keycode == W && window_config->keys->forward == 0)
		window_config->keys->forward = 1;
	if (keycode == S && window_config->keys->backward == 0)
		window_config->keys->backward = 1;
	if (keycode == A && window_config->keys->left == 0)
		window_config->keys->left = 1;
	if (keycode == D && window_config->keys->right == 0)
		window_config->keys->right = 1;
	if (keycode == TURN_LEFT && window_config->keys->turn_left == 0)
		window_config->keys->turn_left = 1;
	if (keycode == TURN_RIGHT && window_config->keys->turn_right == 0)
		window_config->keys->turn_right = 1;
	return (1);
}

int released_keys(int keycode, t_win *window_config)
{
	if (keycode == W && window_config->keys->forward == 1)
		window_config->keys->forward = 0;
	if (keycode == S && window_config->keys->backward == 1)
		window_config->keys->backward = 0;
	if (keycode == A && window_config->keys->left == 1)
		window_config->keys->left = 0;
	if (keycode == D && window_config->keys->right == 1)
		window_config->keys->right = 0;
	if (keycode == TURN_LEFT && window_config->keys->turn_left == 1)
		window_config->keys->turn_left = 0;
	if (keycode == TURN_RIGHT && window_config->keys->turn_right == 1)
		window_config->keys->turn_right = 0;
	return (1);
}

void    treat_keys(t_win *window_config)
{
	if (window_config->keys->forward == 1)
		move_forward(window_config);
	if (window_config->keys->backward == 1)
		move_backward(window_config);
	if (window_config->keys->left == 1)
		move_left(window_config);
	if (window_config->keys->right == 1)
		move_right(window_config);
	if (window_config->keys->turn_left == 1)
		turn_left(window_config);
	if (window_config->keys->turn_right == 1)
		turn_right(window_config);
}