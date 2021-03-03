#include "cub3d.h"

static int  line_treat(t_win *window_config, char *line, int rtn)
{
    int i;
    int error;

    i = 0;
    error = 1;
    if (!window_config->map->map_exists && line[i] != '\0')
        whitespace_skip(&i, line);
    if (line[i] && (line[i] == '1' || window_config->map->map_exists))
        error = map_treat(window_config, line, i);
    else if (line[i] && line[i] == 'R' && line[i + 1] == ' ')
        error = resolution_treat(window_config, line, i);
    else if (line[i] && (line[i] == 'C' || line[i] == 'F') && line[i + 1] == ' ')
        error = color_treat(window_config, line, i);
    else if (line[i] == '\0' && rtn && !window_config->map->map_exists)
        return (error);
    else
        return (error = put_error_msg("Error: Invalid configuration file\n"));
    return (error);
}

int config_parser(t_win *window_config)
{
    char *line;
    int fd;
    int rtn;

    line = 0;
    if (!(fd = open(window_config->config_file, O_RDONLY)))
        return (put_error_msg("Error: Can't open config file\n"));
    while ((rtn = get_next_line(fd, &line)) != -1)
    {
        if (!line_treat(window_config, line, rtn))
            return (0);
        if (rtn == 0)
            break;
    }
    fd = -1;
    printf("%d\n", window_config->window_width);
    printf("%d\n", window_config->window_height);
    while (window_config->map->map[++fd])
        ft_putendl_fd(window_config->map->map[fd], 1);
    if (rtn == -1)
            return (put_error_msg("Error: Can't read config file\n"));
    return (1);
}