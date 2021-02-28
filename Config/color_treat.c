#include "cub3d.h"
static int pass(int *i, char *line)
{
    if (line[*i] && (line[*i] == ' ' || line[*i] == ','))
    {
        whitespace_skip(i, line);
        if (line[*i] == ',')
            (*i)++;
    }
    else
        return (0);
    whitespace_skip(i, line);
    return (1);
}

static int  color_format_check(char *line, int i)
{
    if (line[i] && !ft_isdigit(line[i]))
        return (put_error_msg("Error: Invalid color string\n"));
    while (line[i] && ft_isdigit(line[i]))
        i++;
    if (!pass(&i, line))
        return (put_error_msg("Error: Invalid color string\n"));
    if (line[i] && !ft_isdigit(line[i]))
        return (put_error_msg("Error: Invalid color string\n"));
    while (line[i] && ft_isdigit(line[i]))
        i++;
    if (!pass(&i, line))
        return (put_error_msg("Error: Invalid color string\n"));
    if (line[i] && !ft_isdigit(line[i]))
        return (put_error_msg("Error: Invalid color string\n"));
    while (line[i] && ft_isdigit(line[i]))
        i++;
     if (line[i] && line[i] != ' ')
        return (put_error_msg("Error: Invalid color string\n"));
    whitespace_skip(&i, line);
    if (line[i])
        return (put_error_msg("Error: Invalid color string\n"));
    return (1);
}

static int  color_atoi(char *line, int *i)
{
    int rtn;

    rtn = 0;
    pass(i, line);
    while (ft_isdigit(line[*i]))
    {
        rtn = (rtn * 10) + (line[*i] - '0');
        (*i)++;
    }
    printf("%d\n", rtn);
    if (rtn > 255 || rtn < 0)
    {
        put_error_msg("Error: Invalid color string\n");
        return (-1);
    }
    return (rtn);
}

static int convert_color(t_win *window_config, char c, int r, int g, int b)
{
    int color;

	color = r;
	color = (color << 8) + g;
	color = (color << 8) + b;
    if (c == 'C' && !window_config->ceiling_color)
		window_config->ceiling_color = color;
	else if (c == 'F' && !window_config->floor_color)
        window_config->floor_color = color;
    else
        return(put_error_msg("Error: Color specified twice\n"));
    return (1);
}

int color_treat(t_win *window_config, char *line, int i)
{
    char c;
    int r;
    int g;
    int b;

    c = line[i];
    if (window_config->ceiling_color && window_config->floor_color)
        return (put_error_msg("Error: Color specified twice\n"));
    if (line[i] && (line[i] == 'C' || line[i] == 'F'))
        i++;
    whitespace_skip(&i, line);
    if (!color_format_check(line, i))
        return (0);
    if ((r = color_atoi(line, &i)) == -1 || (g = color_atoi(line, &i)) == -1 || (b = color_atoi(line, &i)) == -1)
        return (0);
    return (convert_color(window_config, c, r, g, b));
}