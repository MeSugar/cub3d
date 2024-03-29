/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolution_treat.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdelta <gdelta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 20:10:47 by gdelta            #+#    #+#             */
/*   Updated: 2021/03/27 20:41:25 by gdelta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	resoluiton_fomat_check(char *line, int i)
{
	int			sides;

	sides = 0;
	if (line[i] && ft_isdigit(line[i]))
		sides++;
	else
		return (put_error_msg("Error: Invalid resolution string\n"));
	while (line[i] && ft_isdigit(line[i]))
		i++;
	whitespace_skip(&i, line);
	if (line[i] && ft_isdigit(line[i]))
		sides++;
	else
		return (put_error_msg("Error: Invalid resolution string\n"));
	while (line[i] && ft_isdigit(line[i]))
		i++;
	whitespace_skip(&i, line);
	if (line[i] || sides != 2)
		return (put_error_msg("Error: Invalid resolution string\n"));
	return (1);
}

static void	store_resolution(t_win *window_config, char *line, int i)
{
	i--;
	while (ft_isdigit(line[++i]))
	{
		window_config->win_w = (window_config->win_w * 10) + (line[i] - '0');
		if (window_config->win_w > window_config->screen_width)
		{
			window_config->win_w = window_config->screen_width;
			break ;
		}
	}
	while (ft_isdigit(line[i]))
		i++;
	whitespace_skip(&i, line);
	i--;
	while (ft_isdigit(line[++i]))
	{
		window_config->win_h = (window_config->win_h * 10) + (line[i] - '0');
		if (window_config->win_h > window_config->screen_height)
		{
			window_config->win_h = window_config->screen_height;
			break ;
		}
	}
	while (ft_isdigit(line[i]))
		i++;
}

int			resolution_treat(t_win *window_config, char *line, int i)
{
	if (window_config->win_w || window_config->win_h)
		return (put_error_msg("Error: Resolution specified twice\n"));
	mlx_get_screen_size(&window_config->screen_width,
	&window_config->screen_height);
	if (line[i] && line[i] == 'R')
		i++;
	whitespace_skip(&i, line);
	if (!resoluiton_fomat_check(line, i))
		return (0);
	store_resolution(window_config, line, i);
	free(line);
	return (1);
}
