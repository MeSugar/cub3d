#include "cub3d.h"

static int  texture_fomat_check(t_win *window_config, char *line, int i)
{
    if ((line[i] == 'N' && line[i + 1] == 'O' && window_config->no_tex->img_ptr)
    || (line[i] == 'S' && line[i + 1] == 'O' && window_config->so_tex->img_ptr)
    || (line[i] == 'W' && line[i + 1] == 'E' && window_config->we_tex->img_ptr)
    || (line[i] == 'E' && line[i + 1] == 'A' && window_config->ea_tex->img_ptr)
    || (line[i] == 'S' && line[i + 1] == ' ' && window_config->sprite_tex->img_ptr))
        return (put_error_msg("Error: Texture specified twice\n"));
    i += 2;
    whitespace_skip(&i, line);
    while (line[i] && ft_isprint(line[i]) && line[i] != ' ')
		i++;
    whitespace_skip(&i, line);
    if (line[i])
        return (put_error_msg("Error: Invalid texture string\n"));
    return (1);
}

static char *save_file_name(char *line, int i)
{
    char *file;
    int start;

    i += 2;
    whitespace_skip(&i, line);
    start = i;
    while (line[i] && ft_isprint(line[i]) && line[i] != ' ')
		i++;
    if (!(file = ft_calloc((i - start + 1), sizeof(char))))
    {
        put_error_msg("Error: Malloc error\n");
        return (0);
    }
    i = start;
    start = 0;
    while (line[i] && line[i] != ' ')
		file[start++] = line[i++];
    return (file);
}

static int xpm_to_img(t_win *window_config, char *file, t_image *img)
{
    int fd;

    if (!(fd = open(file, O_RDONLY)))
        return (put_error_msg("Error: Can't open texture file\n"));
    close (fd);
    if (name_check(file, ".xpm"))
    {
        if (!(img->img_ptr = mlx_xpm_file_to_image(window_config->mlx_ptr, file, &img->width, &img->height)))
            return (put_error_msg("Error: Can't open texture file\n"));
    }
        // if (name_check(file, ".png"))
    // {
    //     if (!(img->img_ptr = mlx_png_file_to_image(window_config->mlx_ptr, file, &img->width, &img->height)))
    //         return (put_error_msg("Error: Can't open texture file\n"));
    // }
    else
        return (0);
    if (img->width != 64 || img->height != 64)
        return (put_error_msg("Error: Wrong resolution of texture file\n"));
    if (!(img->addr = mlx_get_data_addr(img->img_ptr, &img->bpp, &img->line_length, &img->endian)))
        return (put_error_msg("Error: Can't open texture file\n"));
    printf("texture %s\n", file);
    return (1);
}

int texture_treat(t_win *window_config, char *line, int i)
{
    char *file_name;
    t_image *img;

    img = 0;
    if (!texture_fomat_check(window_config, line, i))
        return (0);
    if (!(file_name = save_file_name(line, i)))
        return (0);
    if (!(img = ft_calloc(1, sizeof(t_image))))
        return (put_error_msg("Error: Malloc error\n"));
    if (!(xpm_to_img(window_config, file_name, img)))
        return (0);
    if (line[i] == 'N' && line[i + 1] == 'O')
        window_config->no_tex = img;
    if (line[i] == 'S' && line[i + 1] == 'O')
        window_config->so_tex = img;
    if (line[i] == 'W' && line[i + 1] == 'E')
        window_config->we_tex = img;
    if (line[i] == 'E' && line[i + 1] == 'A')
        window_config->ea_tex = img;
    if (line[i] == 'S' && line[i + 1] == ' ')
        window_config->sprite_tex = img;
    free(file_name);
    // free(img);
    return (1);
}