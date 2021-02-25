#include "cub3d.h"

static char **map_save(t_mapp *mapp, int size)
{
    char **map;
    t_mapp *tmp;
    int i;

    if (!(map = ft_calloc(size + 1, sizeof(char *))))
        return (put_error_msg("Error: Malloc error during saving map"));
    tmp = mapp;
    if (mapp->next)
        free(mapp);
    i = -1;
    while (tmp)
    {
        map[++i] = tmp->content;
        tmp = tmp->next; 
    }
    return (map);
}

int map_treat(t_win *window_config, char *line, int i)
{
    window_config->map->map_exists = 1;
    while (line[i])
    {
        if (line[i] != '0' || line[i] != '1' || line[i] != '2'
        || line[i] != 'N' || line[i] != 'E' || line[i] != 'S' 
        || line[i] != 'W' || line[i] != ' ')
            return (put_error_msg("Error: Invalid map element"));
        i++;
    }
    ft_lstadd_back(window_config->mapp, ft_lstnew(line));
    if (!(window_config->map->map = map_save(window_config->mapp, ft_lstsize(window_config->mapp))))
        return (0);
    return (1);
}