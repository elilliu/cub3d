/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elilliu <elilliu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 13:35:15 by elilliu           #+#    #+#             */
/*   Updated: 2025/01/28 14:08:49 by elilliu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	fill_tab(t_data *data)
{
	t_fill_tab	ft;

	ft.i = 0;
	ft.row = 0;
	ft.fd = open(data->map_path, O_RDONLY);
	ft.line = NULL;
	while (ft.row < data->map.rows)
	{
		data->map.tab[ft.row] = gc_mem(MALLOC, sizeof(char)
				* (data->map.length + 1), NULL);
		ft.line = get_next_line(ft.fd);
		ft.i = -1;
		while (ft.line[++ft.i] && ft.line[ft.i] != '\n')
			data->map.tab[ft.row][ft.i] = ft.line[ft.i];
		free(ft.line);
		data->map.tab[ft.row][ft.i] = '\0';
		ft.row++;
	}
	data->map.tab[ft.row] = NULL;
	close(ft.fd);
	return (1);
}

int	map_init(t_data *data)
{
	char	*line;
	int		fd;

	fd = open(data->map_path, O_RDONLY);
	if (fd < 0)
		return (print_error("Failed to open file"), 0);
	line = get_next_line(fd);
	if (!line)
		return (close(fd), 0);
	while (line[data->map.length] && data->map.length != '\n')
		data->map.length++;
	while (line)
	{
		free(line);
		line = get_next_line(fd);
		data->map.rows++;
	}
	close(fd);
	free(line);
	data->map.tab = gc_mem(MALLOC, sizeof(char *) * (data->map.rows + 1), NULL);
	if (fill_tab(data) == 0)
		return (free(data->map.tab), 0);
	return (1);
}
