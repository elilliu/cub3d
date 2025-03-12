#include "../../include/cub3d_bonus.h"

t_bool	empty_line(char *line)
{
	int	i;

	i = 0;
	if (!line)
		return (true);
	i = skip_whitespaces(line, 0);
	if (line[i] == '\0' || line[i] == '\n')
		return (true);
	return (false);
}
