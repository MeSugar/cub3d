#include "cub3d.h"

static int map_save(t_win *window_config, int size)
{
    char **map;
    t_list *tmp;
    int i;

    if (!(map = ft_calloc(size + 1, sizeof(char *))))
        return (put_error_msg("Error: Malloc error during saving the map"));
    tmp = window_config->mapp;
    if (window_config->map->map)
        free(window_config->map->map);
    i = -1;
    while (tmp)
    {
        map[++i] = tmp->content;
        tmp = tmp->next;
    }
    map[i + 1] = 0;
    window_config->map->map = map;
    return (1);
}

static int map_format_check(char **map, t_win *window_config)
{
    int h;
    int w;

    h = -1;
    while(map[++h])
    {
        w = 0;
        whitespace_skip(&w, map[h]);
        while (map[h][w])
        {
            if ((h == 0 && map[h][w] != '1') || (h == window_config->map->height - 1 && map[h][w] != '1'))
                return (put_error_msg("Error: The map isn't enclosed\n"));
            if ((map[h - 1][w] == ' ' && map[h][w] != '1') || (map[h + 1][w] == ' ' && map[h][w] != '1'))
                return (put_error_msg("Error: The map isn't enclosed\n"));
            if ((w == 0 && map[h][w] != '1') || (map[h][w + 1] == '\0' && map[h][w] != '1'))
                return (put_error_msg("Error: The map isn't enclosed\n"));
            w++;
        }
    }
    return (1);
}

int map_treat(t_win *window_config, char *line, int i)
{
    window_config->map->height++;
    window_config->map->map_exists = 1;
    while (line[i])
    {
        if ((line[i] == '0' || line[i] == '1' || line[i] == '2'))
            i++;
        else if ((line[i] == 'N' || line[i] == 'E' || line[i] == 'S' || line[i] == 'W'))
        {
            window_config->player->x = i;
            window_config->player->y = window_config->map->height;
            window_config->player->players_number++;
            i++;
        }
        else
            return (put_error_msg("Error: Invalid map element\n"));
    }
    // if (!window_config->map->width)
    //     window_config->map->width = i;
    // if (window_config->map->width && window_config->map->width < i)
    //     window_config->map->width = i;
    ft_lstadd_back(&window_config->mapp, ft_lstnew(line));
    if (!map_save(window_config, ft_lstsize(window_config->mapp)))
        return (0);
    if (!map_fomat_check(window_config->map->map, window_config))
        return (0);
    return (1);
}
