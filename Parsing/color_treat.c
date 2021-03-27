/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_treat.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdelta <gdelta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 20:10:28 by gdelta            #+#    #+#             */
/*   Updated: 2021/03/27 16:06:51 by gdelta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	pass(int *i, char *line, int *colors)
{
	whitespace_skip(i, line);
	if (line[*i] && line[*i] != ',')
		return (0);
	else
		(*i)++;
	whitespace_skip(i, line);
	if (line[*i] && ft_isdigit(line[*i]))
		(*colors)++;
	else
		return (0);
	return (1);
}

static int	color_format_check(char *line, int i)
{
	int		colors;

	colors = 0;
	if (line[i] && ft_isdigit(line[i]))
		colors++;
	else
		return (put_error_msg("Error: Invalid color string\n"));
	while (line[i] && ft_isdigit(line[i]))
		i++;
	if (!pass(&i, line, &colors))
		return (put_error_msg("Error: Invalid color string\n"));
	while (line[i] && ft_isdigit(line[i]))
		i++;
	if (!pass(&i, line, &colors))
		return (put_error_msg("Error: Invalid color string\n"));
	while (line[i] && ft_isdigit(line[i]))
		i++;
	whitespace_skip(&i, line);
	if (line[i] || colors != 3)
		return (put_error_msg("Error: Invalid color string\n"));
	return (1);
}

static int	color_atoi(char *line, int *i)
{
	int		rtn;

	rtn = 0;
	whitespace_skip(i, line);
	if (line[*i] && line[*i] == ',')
		(*i)++;
	whitespace_skip(i, line);
	while (ft_isdigit(line[*i]))
	{
		rtn = (rtn * 10) + (line[*i] - '0');
		(*i)++;
	}
	if (rtn > 255 || rtn < 0)
	{
		put_error_msg("Error: Invalid color string\n");
		return (-1);
	}
	return (rtn);
}

static int	convert_color(t_win *window_config, int r, int g, int b)
{
	int		color;

	color = r;
	color = (color << 8) + g;
	color = (color << 8) + b;
	if (window_config->color == 'C' && !window_config->ceiling_color)
		window_config->ceiling_color = color;
	else if (window_config->color == 'F' && !window_config->floor_color)
		window_config->floor_color = color;
	else
		return (put_error_msg("Error: Color specified twice\n"));
	return (1);
}

int			color_treat(t_win *window_config, char *line, int i)
{
	int		r;
	int		g;
	int		b;

	window_config->color = line[i];
	if (window_config->ceiling_color && window_config->floor_color)
		return (put_error_msg("Error: Color specified twice\n"));
	if (line[i] && (line[i] == 'C' || line[i] == 'F'))
		i++;
	whitespace_skip(&i, line);
	if (!color_format_check(line, i))
		return (0);
	if ((r = color_atoi(line, &i)) == -1)
		return (0);
	if ((g = color_atoi(line, &i)) == -1)
		return (0);
	if ((b = color_atoi(line, &i)) == -1)
		return (0);
	free(line);
	return (convert_color(window_config, r, g, b));
}
