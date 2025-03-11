/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neleon <neleon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 13:35:15 by elilliu           #+#    #+#             */
/*   Updated: 2025/03/11 18:34:36 by neleon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d_bonus.h"

int	fill_tab(t_data *data)
{
	int		i;
	int		fd;
	char	*line;

	fd = open(data->map_path, O_RDONLY);
	if (fd < 0)
		return (0);
	line = NULL;
	i = 0;
	while (i < data->map.rows)
	{
		line = get_next_line(fd, 0);
		data->map.tab[i] = gc_strdup(line);
		free(line);
		i++;
	}
	data->map.tab[i] = NULL;
	clean_map_reading(line, fd);
	return (1);
}

int	map_init(t_data *data)
{
	char	*line;
	int		fd;

	fd = open(data->map_path, O_RDONLY);
	if (fd < 0)
		return (print_error("Failed to open file"), 0);
	line = get_next_line(fd, 0);
	if (!line)
		return (close(fd), 0);
	while (line)
	{
		free(line);
		line = get_next_line(fd, 0);
		data->map.rows++;
	}
	clean_map_reading(line, fd);
	data->map.tab = gc_mem(MALLOC, sizeof(char *) * (data->map.rows + 1), NULL);
	if (fill_tab(data) == 0)
		return (gc_mem(FREE, 0, data->map.tab), 0);
	return (1);
}
