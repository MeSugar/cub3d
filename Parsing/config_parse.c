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
    else if (line[i] == '\0' && rtn && !window_config->map->map_exists)
        return (error);
    else
        return (error = put_error_msg("Error: Invalid configuration file\n"));
    return (error);
}

static int map_format_check(char **map, t_win *window_config)
{
    int h;
    int w;
    int begin;

    h = -1;
    while(map[++h])
    {
        w = 0;
        whitespace_skip(&w, map[h]);
        begin = w;
        while (map[h][w])
        {
            if ((h == 0 && map[h][w] != '1' && map[h][w] != ' ') || (h == window_config->map->height - 1 && map[h][w] != '1' && map[h][w] != ' '))
                return (put_error_msg("Error: The map isn't enclosed\n"));
            if (h > 0 && ((map[h - 1][w] == ' ' && map[h][w] != ' ' && map[h][w] != '1') || (map[h - 1][w] == '\0' && map[h][w] != '1' && map[h][w] != ' ')))
                return (put_error_msg("Error: The map isn't enclosed\n"));
            if ((map[h][w] == ' ' && map[h][w + 1] != ' ' && map[h][w + 1] != '1' && map[h][w + 1] != '\0') 
            || (map[h][w] == ' ' && map[h][w - 1] != ' ' && map[h][w - 1] != '1'))
                return (put_error_msg("Error: The map isn't enclosed\n"));
            if (h < window_config->map->height - 1 && ((map[h + 1][w] == ' ' && map[h][w] != ' ' && map[h][w] != '1')
            || (map[h + 1][w] == '\0' && map[h][w] != ' ' && map[h][w] != '1')))
                return (put_error_msg("Error: The map isn't enclosed\n"));
            if (begin - w  == 0 && map[h][w] != '1')
                return (put_error_msg("Error: The map isn't enclosed\n"));
            if (map[h][w + 1] == '\0' && map[h][w] != '1' && map[h][w] != ' ')
                return (put_error_msg("Error: The map isn't enclosed\n"));
            w++;
        }
    }
    return (1);
}

static void set_player_plane(t_win *window_config, double pdx, double pdy, double planex, double planey)
{
    window_config->player->pdx;
    window_config->player->pdy;
    window_config->player->planex = planex;
    window_config->player->planey = planey;
}

static int set_player_direction(t_win *window_config)
{
    if (window_config->player->players_number != 1)
        return (put_error_msg("Error: Invalid number of players\n"));
    if (window_config->player->direction == 'N')
        set_player_plane(window_config, 0, 1, 0.66, 0);
    if (window_config->player->direction == 'S')
        set_player_plane(window_config, 0, -1, -0.66, 0);
    if (window_config->player->direction == 'W')
        set_player_plane(window_config, -1, 0, 0, -0.66);
    if (window_config->player->direction == 'E')
        set_player_plane(window_config, 1, 0, 0, 0.66);
    return (1);
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
    if (!map_format_check(window_config->map->map, window_config))
        return (0);
    if (!set_player_direction(window_config))
        return (0);
    fd = -1;
    printf("%d\n", window_config->window_width);
    printf("%d\n", window_config->window_height);
    while (window_config->map->map[++fd])
        ft_putendl_fd(window_config->map->map[fd], 1);
    if (rtn == -1)
            return (put_error_msg("Error: Can't read config file\n"));
    return (1);
}