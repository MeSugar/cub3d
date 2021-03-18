#ifndef CUB3D_H
# define CUB3D_H

# define BUFFER_SIZE 4096
// # define PI 3.1415926535

# define ESC 53
# define W 13
# define S 1
# define A 0
# define D 2
# define TURN_LEFT 123
# define TURN_RIGHT 124
# define SPEED 0.2
# define TURN 0.1

# include <fcntl.h>
# include "mlx.h"
# include "libft.h"
# include <math.h>
# include <stdio.h>

typedef struct s_ray
{
    int     mapx;
    int     mapy;
    int		stepx;
	int		stepy;
	int		hit;
    int     side;
    int     wall_height;
    int     draw_start;
    int     draw_end;
    double  camerax;
    double  rdx;
    double  rdy;
    double  side_distx;
	double  side_disty;
	double	delta_distx;
	double	delta_disty;
    double  wall_dist;
}               t_ray;

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
    int         width;
    int         height;
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
    float              pa;
    double             planex;
    double             planey;
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
    t_ray *ray;
    t_image *no;
    t_image *so;
    t_image *we;
    t_image *ea;
    t_image *sprite;
    char **buff;
}               t_win;

// Inits
t_win   *window_config_init(const char *config_file);
int     map_player_buttons_init(t_win *window_config);
int     window_init(t_win *window_config);
int     image_init(t_win *window_config);
int     texture_init(t_win *window_config);

// Error management
int name_check(char *av, char *cub);
int put_error_msg(char *error_message);

// Parsing
int     config_parser(t_win *window_config);
int     get_next_line(int fd, char **line);
void    whitespace_skip(int *i, char *line);
int     map_treat(t_win *window_config, char *line, int i);
int     resolution_treat(t_win *window_config, char *line, int i);
int     color_treat(t_win *window_config, char *line, int i);
int     texture_treat(t_win *window_config, char *line, int i);

// Drawing
void pixel_put(t_image *image, int x, int y, int color);
int main_loop(t_win *window_config);
int draw_screen(t_win *window_config);
int draw_image(t_win *window_config, int rays);
void set_ray(t_win *window_config, int rays);
void set_side_dist(t_win *window_config);
void find_wall(t_win *window_config);
void calculate_wall_dist_n_height(t_win *window_config);
// void draw_map(t_win *window_config, int rays);
void draw_map(t_win *window_config, char **buff);

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