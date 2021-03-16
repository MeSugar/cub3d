#include "cub3d.h"

int main_loop(t_win *window_config)
{
   
    if (!draw_screen(window_config))
        return (0);
    treat_buttons(window_config);
    return(1);
}