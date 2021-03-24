#include "cub3d.h"

static int  line_treat(t_win *window_config, char *line, int rtn)
{
    int i;
    int error;

    i = 0;
    error = 1;
    whitespace_skip(&i, line);
    if (line[i] && (line[i] == '1' || window_config->map->map_exists))
        error = map_treat(window_config, line, i);
    else if (line[i] && line[i] == 'R' && line[i + 1] == ' ')
        error = resolution_treat(window_config, line, i);
    else if (line[i] && (line[i] == 'C' || line[i] == 'F') && line[i + 1] == ' ')
        error = color_treat(window_config, line, i);
    else if (line[i] && ((line[i] == 'N' && line[i + 1] == 'O' && line[i + 2] == ' ')
    || (line[i] == 'S' && line[i + 1] == 'O' && line[i + 2] == ' ')
    || (line[i] == 'W' && line[i + 1] == 'E' && line[i + 2] == ' ')
    || (line[i] == 'E' && line[i + 1] == 'A' && line[i + 2] == ' ')
    || (line[i] == 'S' && line[i + 1] == ' ')))
        error = texture_treat(window_config, line, i);
    else if (line[i] == '\0' && rtn && !window_config->map->map_exists)
        return (error);
    else
        return (error = put_error_msg("Error: Invalid configuration file\n"));
    return (error);
}

static void set_player_plane(t_win *window_config, double pdx, double pdy, double planex, double planey)
{
    window_config->player->pdx = pdx;
    window_config->player->pdy = pdy;
    window_config->player->planex = planex;
    window_config->player->planey = planey;
}

int set_player_direction(t_win *window_config)
{
    if (window_config->player->players_number != 1)
        return (put_error_msg("Error: Invalid number of players\n"));
    if (window_config->player->direction == 'N')
        set_player_plane(window_config, 0, -1.0, 0.66, 0);
    if (window_config->player->direction == 'S')
        set_player_plane(window_config, 0, 1.0, -0.66, 0);
    if (window_config->player->direction == 'W')
        set_player_plane(window_config, -1.0, 0, 0, -0.66);
    if (window_config->player->direction == 'E')
        set_player_plane(window_config, 1.0, 0, 0, 0.66);
    return (1);
}

int config_parser(t_win *window_config)
{
    char *line;
    int fd;
    int rtn;

    line = 0;
    if ((fd = open(window_config->config_file, O_RDONLY)) == -1)
        return (put_error_msg("Error: Can't open config file\n"));
    while ((rtn = get_next_line(fd, &line)) != -1)
    {
        if (!line_treat(window_config, line, rtn))
            return (0);
        if (rtn == 0)
            break;
    }
    close (fd);
    if (rtn == -1)
        return (put_error_msg("Error: Can't read config file\n"));
    if (!config_elements_check (window_config))
        return (put_error_msg("Error: Wrong config elements\n"));
    if (!map_save(window_config, ft_lstsize(window_config->mapp)))
        return (0);
    if (!sprite_save(window_config, window_config->map->map))
        return (0);
    fd = -1;
    free(line);
    printf("%d\n", window_config->window_width);
    printf("%d\n", window_config->window_height);
    while (window_config->map->map[++fd])
        ft_putendl_fd(window_config->map->map[fd], 1);
    return (1);
}