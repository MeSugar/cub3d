#ifndef CUB3D_H
# define CUB3D_H

# define BUFFER_SIZE 4096
# include <fcntl.h>
# include "mlx.h"
# include "libft.h"

typedef struct      s_map
{
    char            **map;
    int             map_exists;
}                   t_map;

// typedef struct      s_list
// {
//     void            *content;
//     struct s_mapp   *next;
// }                   t_mapp;

typedef struct  s_win
{
    void    *mlx_ptr;
    void    *win_ptr;
    const char    *config_file;
    int     error_type;
    int     window_width;
    int     window_height;
    t_map   *map;
    t_list   *mapp;
}               t_win;

// Inits
t_win   *window_config_init(const char *config_file);
int     map_init(t_win *window_config);

// Error management
int put_error_msg(char *error_message);

// Parsing
int     config_parser(t_win *window_config);
int     get_next_line(int fd, char **line);
void    whitespace_skip(int *i, char *line);
int     map_treat(t_win *window_config, char *line, int i);

#endif