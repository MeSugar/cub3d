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

// static int map_format_check(char **map)
// {
//     int w;
//     int h;

//     w = 0;
//     h = 0;
    // while (map[h])
    // {
    //     w = 0;
    //     whitespace_skip(&w, map[h][w]);
    //     while (map[h][w])
    //     {
    //         if ((map[h][w] != '1' && map[h][w] != ' ' && h == 0) || (map[h][w] != '1' && map[h][w] != ' ' && map[h + 1] == 0))
    //             return (put_error_msg("Error: The map isn't enclosed\n"));
    //     }
        
    // }
    // while (1)
    // {
        
    // }

// }

int map_treat(t_win *window_config, char *line, int i)
{
    window_config->map->map_exists = 1;
    while (line[i])
    {
        if ((line[i] == '0' || line[i] == '1' || line[i] == '2' || line[i] == 'N' || line[i] == 'E' || line[i] == 'S' || line[i] == 'W' || line[i] == ' '))
            i++;
        else
            return (put_error_msg("Error: Invalid map element\n"));
    }
    ft_lstadd_back(&window_config->mapp, ft_lstnew(line));
    if (!map_save(window_config, ft_lstsize(window_config->mapp)))
        return (0);
    // if (!map_fomat_check(window_config->map->map))
    //     return (0);
    return (1);
}
