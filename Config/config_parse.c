#include "cub3d.h"

static int  line_treat(t_win *window_config, char *line)
{
    int i;
    int error;

    i = 0;
    error = 1;
    whitespace_skip(&i, line);
    if (line[i] && (line[i] == '1' || window_config->map->map_exists))
        error = map_treat(window_config, line, i);
    return (error);
}

int config_parser(t_win *window_config)
{
    char *line;
    int fd;
    int rtn;

    line = 0;
    if (!(fd = open(window_config->config_file, O_RDONLY)))
        return (put_error_msg("Error: Can't open config file\n"));
    while ((rtn = get_next_line(fd, &line)))
    {
        if (rtn == -1)
            return (put_error_msg("Error: Can't read config file\n"));
        if (!line_treat(window_config, line))
            return (0);

		// ft_lstadd_back(window_config->map, ft_lstnew(line));
    }
    return (1);
    // ft_lstadd_back(window_config->map, ft_lstnew(line));


	// make_map(&head, ft_lstsize(head));

}