#include "cub3d.h"

int sprite_save(t_win *window_config, char **map)
{
    int y;
    int x;
    int j;
    char **buf;
    int sprites;
    
    sprites = window_config->sprite->sprites_number;
    if (!window_config->sprite->sprites_number)
        return (1);
    
    if (!(buf = ft_calloc(window_config->sprite->sprites_number, sizeof(double *))))
        return (put_error_msg("Error: Malloc error"));
    y = -1;
    while (++y < sprites)
    {
        if (!(buf[y] = ft_calloc(2, sizeof(double *))))
            return (put_error_msg("Error: Malloc error"));
    }
    y = -1;
    j = 0;
    while (map[++y])
    {
        x = -1;
        while (map[y][++x] && sprites)
        {
            if (map[y][x] == '2')
            {
                buf[j][0] = (double)y;
                buf[j][1] = (double)x;
                j++;
                sprites--;
            }
        }
    }
    window_config->sprite->sprites_pos = buf;
    return (1);
}

int map_save(t_win *window_config, int size)
{
    char **map;
    int i;

    if (!(map = ft_calloc(size + 1, sizeof(char *))))
        return (put_error_msg("Error: Malloc error during saving the map"));
    i = -1;
    while (window_config->mapp)
    {
        map[++i] = ft_calloc(window_config->map->width, sizeof(char));
        ft_strlcpy(map[i], window_config->mapp->content, ft_strlen(window_config->mapp->content) + 1);
        free(window_config->mapp->content);
        free(window_config->mapp);
        window_config->mapp = window_config->mapp->next;
    }
    free(window_config->mapp);
    map[i + 1] = 0;
    window_config->map->map = map;
    if (!map_format_check(window_config->map->map, window_config))
        return (0);
    if (!set_player_direction(window_config))
        return (0);
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