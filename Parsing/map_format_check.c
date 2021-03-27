/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_format_check.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdelta <gdelta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 18:40:58 by gdelta            #+#    #+#             */
/*   Updated: 2021/03/27 18:41:00 by gdelta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	value_check(t_win *window_config, char **map, int h, int w)
{
	if ((h == 0 && map[h][w] != '1' && map[h][w] != ' ')
	|| (h == window_config->map->height - 1
	&& map[h][w] != '1' && map[h][w] != ' '))
		return (put_error_msg("Error: The map isn't enclosed\n"));
	if (h > 0 && ((map[h - 1][w] == ' ' && map[h][w] != ' '
	&& map[h][w] != '1') || (map[h - 1][w] == '\0'
	&& map[h][w] != '1' && map[h][w] != ' ')))
		return (put_error_msg("Error: The map isn't enclosed\n"));
	if ((map[h][w] == ' ' && map[h][w + 1] != ' ' && map[h][w + 1] != '1'
	&& map[h][w + 1] != '\0') || (map[h][w] == ' ' && map[h][w - 1] != ' '
	&& map[h][w - 1] != '1'))
		return (put_error_msg("Error: The map isn't enclosed\n"));
	if (h < window_config->map->height - 1 && ((map[h + 1][w] == ' '
	&& map[h][w] != ' ' && map[h][w] != '1') || (map[h + 1][w] == '\0'
	&& map[h][w] != ' ' && map[h][w] != '1')))
		return (put_error_msg("Error: The map isn't enclosed\n"));
	if (map[h][w + 1] == '\0' && map[h][w] != '1' && map[h][w] != ' ')
		return (put_error_msg("Error: The map isn't enclosed\n"));
	return (1);
}

int			map_format_check(char **map, t_win *window_config)
{
	int		h;
	int		w;
	int		begin;

	h = -1;
	while (map[++h])
	{
		w = 0;
		whitespace_skip(&w, map[h]);
		begin = w;
		while (map[h][w])
		{
			if (!value_check(window_config, map, h, w))
				return (0);
			if (begin - w == 0 && map[h][w] != '1')
				return (put_error_msg("Error: The map isn't enclosed\n"));
			w++;
		}
	}
	return (1);
}
