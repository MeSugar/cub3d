#include "cub3d.h"

int main_loop(t_win *window_config)
{
    draw_image(window_config);
    treat_keys(window_config);
    return(1);
}