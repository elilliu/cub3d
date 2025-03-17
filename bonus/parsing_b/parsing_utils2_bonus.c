/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils2_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neleon <neleon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 15:34:29 by neleon            #+#    #+#             */
/*   Updated: 2025/03/13 15:34:32 by neleon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

int	skip_empty_line(char **line, int fd)
{
	if (!*line)
		return (0);
	while (*line && empty_line(*line))
	{
		if (*line)
			free(*line);
		*line = get_next_line(fd, 0);
	}
	return (1);
}

int	check_texture(char *line)
{
	int	i;

	i = 0;
	i = skip_whitespaces(line, i);
	if (line[i] == 'N')
		return (T_NO);
	else if (line[i] == 'S')
		return (T_SO);
	else if (line[i] == 'W')
		return (T_WE);
	else if (line[i] == 'E')
		return (T_EA);
	else if (line[i] == 'F')
		return (T_FL);
	else if (line[i] == 'C')
		return (T_CE);
	return (-1);
}

int	skip_tex_type(char *line, int i, int size)
{
	i = skip_whitespaces(line, i);
	i += size;
	i = skip_whitespaces(line, i);
	return (i);
}

int	path_len(char *path)
{
	int	len;

	len = 0;
	while (path[len] && !is_whitespace(path[len]) && path[len] != '\n')
		len++;
	return (len);
}
