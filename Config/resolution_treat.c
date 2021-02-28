#include "cub3d.h"

static int  resoluiton_fomat_check(char *line, int i)
{
    if (line[i] && !ft_isdigit(line[i]))
        return (put_error_msg("Error: Invalid resolution string\n"));
    while (line[i] && ft_isdigit(line[i]))
        i++;
    if (line [i] && line[i] != ' ')
        return (put_error_msg("Error: Invalid resolution string\n"));
    whitespace_skip(&i, line);
    if (line[i] && !ft_isdigit(line[i]))
        return (put_error_msg("Error: Invalid resolution string\n"));
    while (line[i] && ft_isdigit(line[i]))
        i++;
    if (line [i] && line[i] != ' ')
        return (put_error_msg("Error: Invalid resolution string\n"));
    whitespace_skip(&i, line);
    if (line[i])
        return (put_error_msg("Error: Invalid resolution string\n"));
    return (1);
}

static void resolution_store(t_win *window_config, char *line, int i)
{
    i--;
    while (ft_isdigit(line[++i]))
        window_config->window_width = (window_config->window_width * 10) + (line[i] - '0');
    if (window_config->window_width > 2560)
        window_config->window_width = 2560;
    whitespace_skip(&i, line);
    i--;
    while (ft_isdigit(line[++i]))
        window_config->window_height = (window_config->window_height * 10) + (line[i] - '0');
	if (window_config->window_height > 1400)
		window_config->window_height = 1400;
}

int     resolution_treat(t_win *window_config, char *line, int i)
{
    if (window_config->window_width || window_config->window_height)
        return (put_error_msg("Error: Resolution specified twice\n"));
    whitespace_skip(&i, line);
    if (line [i] && line[i] == 'R')
        i++;
    whitespace_skip(&i, line);
    if (!resoluiton_fomat_check(line, i))
        return (0);
    resolution_store(window_config, line, i);
    return (1);
}