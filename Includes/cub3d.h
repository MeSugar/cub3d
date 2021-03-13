#ifndef CUB3D_H
# define CUB3D_H

# define BUFFER_SIZE 4096
# define PI 3.1415926535

# define ESC 53
# define W 13
# define S 1
# define A 0
# define D 2
# define TURN_LEFT 123
# define TURN_RIGHT 124

# include <fcntl.h>
# include "mlx.h"
# include "libft.h"
# include <math.h>
# include <stdio.h>

typedef struct s_buttons
{
    int forward;
    int backward;
    int left;
    int right;
    int turn_left;
    int turn_right;
}               t_buttons;


typedef struct s_image
{
    void        *img_ptr;
    char        *addr;
    int         bpp;
    int         line_length;
    int         endian;
}              t_image;

typedef struct      s_map
{
    char            **map;
    int             width;
    int             height;
    int             map_exists;
}                   t_map;

typedef struct      s_player
{
    double             px;
    double             py;
    double             pdx;
    double             pdy;
    double             pa;
    char               direction;

    int             players_number;
}                   t_player;

typedef struct  s_win
{
    void    *mlx_ptr;
    void    *win_ptr;
    const char    *config_file;
    int     window_width;
    int     window_height;
    int     floor_color;
    int     ceiling_color;
    t_map   *map;
    t_player *player;
    t_list  *mapp;
    t_image *image;
    t_buttons  *buttons;
}               t_win;

// Inits
t_win   *window_config_init(const char *config_file);
int     map_player_buttons_init(t_win *window_config);
int     window_init(t_win *window_config);

// Error management
int put_error_msg(char *error_message);

// Parsing
int     config_parser(t_win *window_config);
int     get_next_line(int fd, char **line);
void    whitespace_skip(int *i, char *line);
int     map_treat(t_win *window_config, char *line, int i);
int     resolution_treat(t_win *window_config, char *line, int i);
int     color_treat(t_win *window_config, char *line, int i);

// Drawing
int main_loop(t_win *window_config);
int draw_image(t_win *window_config);

// Buttons
void close_window(t_win *window_config);
int pressed_buttons(int keycode, t_win *window_config);
int released_buttons(int keycode, t_win *window_config);
void treat_buttons(t_win *window_config);
void move_forward(t_win *window_config);
void move_backward(t_win *window_config);
void move_left(t_win *window_config);
void move_right(t_win *window_config);
void turn_left(t_win *window_config);
void turn_right(t_win *window_config);

#endif