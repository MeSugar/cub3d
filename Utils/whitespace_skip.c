#include "cub3d.h"

void whitespace_skip(int *i, char *line)
{
	while (line[*i] == '\t' || line[*i] == '\n' || line[*i] == '\r'
    || line[*i] == '\v' || line[*i] == '\f' || line[*i] == ' ')
		(*i)++;
}