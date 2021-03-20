#include "cub3d.h"

int sprite_save(t_win *window_config, char **map)
{
    int y;
    int x;
    int i;
    int j;
    char **buf;

    if (!(buf = ft_calloc(window_config->sprite->sprites_number + 1, sizeof(double *))))
        return (put_error_msg("Error: Malloc error"));
    // y = -1;
    // while (++y < window_config->sprite->sprites_number)
    // {
    //     if (!(buf = ft_calloc(2, sizeof(double *))))
    //         return (put_error_msg("Error: Malloc error"));
    // }
    y = -1;
    j = 0;
    i = 0;
    while (map[++y])
    {
        x = -1;
        while (map[y][++x])
        {
            if (map[y][x] == '2')
            {
                buf[j][i] = y;
                buf[j][i + 1] = x;
                j++;
            }
        }
    }
    window_config->sprite->sprites_pos = buf;
    j = -1;
    while (buf[++j])
    {
        i = -1;
        while (buf[j][++i])
            printf("pos %d\n", buf[j][i]);
    }
    return (1);
}

int map_save(t_win *window_config, int size)
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
        map[++i] = ft_calloc(window_config->map->width, sizeof(char));
        ft_strlcpy(map[i], tmp->content, ft_strlen(tmp->content) + 1);
        tmp = tmp->next;
    }
    map[i + 1] = 0;
    window_config->map->map = map;
    return (1);
}

int map_treat(t_win *window_config, char *line, int i)
{
    window_config->map->map_exists = 1;
    window_config->map->height++;
    while (line[i])
    {
        if ((line[i] == '0' || line[i] == '1' || line[i] == ' '))
            i++;
        else if (line[i] == '2')
        {
            i++;
            window_config->sprite->sprites_number++;
        }
        else if ((line[i] == 'N' || line[i] == 'E' || line[i] == 'S' || line[i] == 'W'))
        {
            window_config->player->px = (double)(i + 0.5);
            window_config->player->py = (double)(window_config->map->height - 0.5);
            window_config->player->players_number++;
            window_config->player->direction = line[i];
            line[i] = '0';
            i++;
        }
        else
            return (put_error_msg("Error: Invalid map element\n"));
    }
    if (window_config->map->width < i)
        window_config->map->width = i;
    ft_lstadd_back(&window_config->mapp, ft_lstnew(line));
    return (1);
}

int map_format_check(char **map, t_win *window_config)
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