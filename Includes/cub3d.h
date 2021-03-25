/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdelta <gdelta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 20:09:30 by gdelta            #+#    #+#             */
/*   Updated: 2021/03/26 02:23:23 by gdelta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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


typedef struct s_sprite
{
    char **spos;
    int sprites_number;
    double spritex;
    double spritey;
    double invdet;
    double transformx;
    double transformy;
    int screenx;
    int height;
    int width;
    int draw_starty;
    int draw_endy;
    int draw_startx;
    int draw_endx;
    int ver_line;
    int texx;
    int texy;
}              t_sprite;


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
    int         line_l;
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
    int     win_w;
    int     win_h;
    int     floor_color;
    int     ceiling_color;
    int save_mode;
    t_map   *map;
    t_player *player;
    t_list  *mapp;
    t_image *image;
    t_buttons  *buttons;
    t_ray *ray;
    t_image *no_tex;
    t_image *so_tex;
    t_image *we_tex;
    t_image *ea_tex;
    t_image *sprite_tex;
    t_sprite *sprite;
    double *buff;
}               t_win;

// Inits
t_win *window_config_init(const char *config_file, int save_mode);
int     map_player_buttons_sprite_init(t_win *window_config);
int     window_init(t_win *window_config);
int     image_init(t_win *window_config);
int     texture_init(t_win *window_config);

// Error management
int name_check(char *av, char *cub);
int put_error_msg(char *error_message);
int finish_program(t_win *window_config, int mode);
int kill_window(t_win *window_config);

// Parsing
int     config_parser(t_win *window_config);
int     get_next_line(int fd, char **line);
void    whitespace_skip(int *i, char *line);
int     map_treat(t_win *window_config, char *line, int i);
int     map_save(t_win *window_config, int size);
int     map_format_check(char **map, t_win *window_config);
int set_player_direction(t_win *window_config);
int     sprite_save(t_win *window_config, char **map);
int     resolution_treat(t_win *window_config, char *line, int i);
int     color_treat(t_win *window_config, char *line, int i);
int     texture_treat(t_win *window_config, char *line, int i);
int config_elements_check(t_win *window_config);

// Drawing
void pixel_put(t_image *image, int x, int y, int color);
int main_loop(t_win *window_config);
int draw_screen(t_win *window_config);
int create_image(t_win *window_config, int rays);
void set_ray(t_win *window_config, int rays);
void set_side_dist(t_win *window_config);
void find_wall(t_win *window_config);
void calculate_wall_dist_n_height(t_win *window_config);
// void draw_map(t_win *window_config, int rays);
// void draw_map(t_win *window_config, char **buff);
int create_bitmap(t_win *window_config, t_image *image);

// Sprites
int create_sprite(t_win* window_config);
void 	sprite_values(t_win *window_config, t_player *player, t_sprite *sprite, int i);
// void set_sprite(t_win *window_config, t_player *player, t_sprite *sprite, int i);


// Buttons
void close_window(t_win *window_config);
int pressed_buttons(int keycode, t_win *window_config);
int released_buttons(int keycode, t_win *window_config);
void treat_buttons(t_win *window_config);
void move_forward(t_map *map, t_player *player);
void move_backward(t_map *map, t_player *player);
void move_left(t_map *map, t_player *player);
void move_right(t_map *map, t_player *player);
void turn_left(t_player *player);
void turn_right(t_player *player);

#endif