#include "cub3d.h"

static void pixel_data_to_bmp(t_image *img, int fd)
{
    int row;
    int x;
    int i;
    char	color;

    row = img->line_length * (img->height - 1);

	while (row >= 0)
	{
		x = 0;
		while (x < img->line_length)
		{
            i = 5;
			color = (char)(img->addr[row + img->bpp / 8]);
			while (--i)
            {
                write(fd, (&color), 1);
                color--;
            }
			x += img->bpp / 8;
		}
		row -= 2 * img->line_length;
	}
}

int create_bitmap(t_win *window_config, t_image *image)
{
    int fd;
    int empty_fields;
    int file_size;
    int first_pix;
    int header_size;
    int plane;
    int image_size;

    file_size = image->width * image->height * 4 + 54;
    first_pix = 54;
    header_size = 40;
    plane = 1;
    image_size = image->width * image->height * 4;
    fd = open("cub3D.bmp", O_CREAT | O_WRONLY | O_TRUNC, S_IRWXU);
    write(fd, "BM", 2);
    write(fd, &file_size, 4);
    write(fd, "\0\0\0\0", 4);
    write(fd, &first_pix, 4);
    write(fd, &header_size, 4);
    write(fd, &image->width, 4);
    write(fd, &image->height, 4);
    write(fd, &plane, 2);
    write(fd, &image->bpp, 2);
    // empty_fields = -1;
    // while (++empty_fields < 24)
    write(fd, "\0", 4);
    write(fd, image_size, 4);
    write(fd, "\0", 16);
    pixel_data_to_bmp(image, fd);
    close(fd);
    finish_program(window_config, 1);
    exit (0);
    return(1);
}