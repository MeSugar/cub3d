#include "cub3d.h"

static int  resoluiton_fomat_check(char *line, int i)
{
    int sides;

    sides = 0;
    if (line[i] && ft_isdigit(line[i]))
        sides++;
    else
        return (put_error_msg("Error: Invalid resolution string\n"));
    while (line[i] && ft_isdigit(line[i]))
        i++;
    // if (line[i] && line[i] != ' ')
    //     return (put_error_msg("Error: Invalid resolution string\n"));
    whitespace_skip(&i, line);
    if (line[i] && ft_isdigit(line[i]))
        sides++;
    else
        return (put_error_msg("Error: Invalid resolution string\n"));
    while (line[i] && ft_isdigit(line[i]))
        i++;
    // if (line[i] && line[i] != ' ')
    //     return (put_error_msg("Error: Invalid resolution string\n"));
    whitespace_skip(&i, line);
    if (line[i] || sides != 2)
        return (put_error_msg("Error: Invalid resolution string\n"));
    return (1);
}

static void store_resolution(t_win *window_config, char *line, int i)
{
    long long res;
    
    res = 0;
    i--;
    while (ft_isdigit(line[++i]))
    {
        res = (res * 10) + (line[i] - '0');
        if (res > 2560)
            window_config->window_width = 2560;
        else
            window_config->window_width = (int)res;
    }
    whitespace_skip(&i, line);
    i--;
    res = 0;
    while (ft_isdigit(line[++i]))
    {
        res = (res * 10) + (line[i] - '0');
        if (res > 1440)
            window_config->window_height = 1440;
        else
            window_config->window_height = (int)res;
    }
}

int     resolution_treat(t_win *window_config, char *line, int i)
{
    if (window_config->window_width || window_config->window_height)
        return (put_error_msg("Error: Resolution specified twice\n"));
    // whitespace_skip(&i, line);
    if (line[i] && line[i] == 'R')
        i++;
    whitespace_skip(&i, line);
    if (!resoluiton_fomat_check(line, i))
        return (0);
    store_resolution(window_config, line, i);
    free (line);
    return (1);
}