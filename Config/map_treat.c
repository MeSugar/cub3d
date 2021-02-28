#include "cub3d.h"

int map_save(t_win *window_config, int size)
{
    char **map;
    t_list *tmp;
    int i;

    if (!(map = ft_calloc(size + 1, sizeof(char *))))
        return (put_error_msg("Error: Malloc error during saving map"));
    tmp = window_config->mapp;
    if (window_config->map->map)
        free(window_config->map->map);
    i = -1;
    while (tmp)
    {
        map[++i] = tmp->content;
        tmp = tmp->next; 
    }
    window_config->map->map = map;
    return (1);
}

int map_treat(t_win *window_config, char *line, int i)
{
    window_config->map->map_exists = 1;
    while (line[i])
    {
        if (line[i] == '0' || line[i] == '1' || line[i] == '2' || line[i] == 'N' || line[i] == 'E' || line[i] == 'S' || line[i] == 'W' || line[i] == ' ')
            i++;
        else
            return (put_error_msg("Error: Invalid map element\n"));
    }
    ft_lstadd_back(&window_config->mapp, ft_lstnew(line));
    if (!map_save(window_config, ft_lstsize(window_config->mapp)))
        return (0);
    ft_putendl_fd(*window_config->map->map, 1);
    return (1);
}
