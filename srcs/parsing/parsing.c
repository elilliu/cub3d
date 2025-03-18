/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elilliu <elilliu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 16:15:52 by neleon            #+#    #+#             */
/*   Updated: 2025/03/18 15:20:28 by elilliu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	extract_line(char *line, t_data *data)
{
	int	texture;

	texture = check_texture(line);
	if (texture == -1)
		return (print_error("Invalid line in .cub file"), 0);
	if (texture == T_FL || texture == T_CE)
		return (extract_rgb(line, data));
	if (texture == T_NO || texture == T_SO || texture == T_EA
		|| texture == T_WE)
		return (extract_t_path(line, data));
	return (0);
}

void	add_map_line(t_data *data, char *line)
{
	t_map2	*new_node;
	t_map2	*current;

	new_node = gc_mem(MALLOC, sizeof(t_map2), NULL);
	new_node->line = gc_dup_map(line);
	new_node->next = NULL;
	if (!data->map2)
		data->map2 = new_node;
	else
	{
		current = data->map2;
		while (current->next)
			current = current->next;
		current->next = new_node;
	}
}

int	fill_map(t_data *data)
{
	int		i;
	t_map2	*curr;

	i = 0;
	curr = data->map2;
	data->map.tab = gc_mem(MALLOC, sizeof(char *) * (data->row_count + 1),
			NULL);
	while (curr)
	{
		data->map.tab[i] = gc_dup_map(curr->line);
		i++;
		curr = curr->next;
	}
	data->map.tab[i] = NULL;
	return (1);
}

void	parse_map(t_data *data, char **line)
{
	skip_empty_line(line, data->fd_cub);
	while (*line && !empty_line(*line))
	{
		add_map_line(data, *line);
		data->row_count += 1;
		data->map.rows++;
		if ((int)ft_strlen(*line) > data->map.columns)
			data->map.columns = (int)ft_strlen(*line);
		free(*line);
		*line = get_next_line(data->fd_cub, 0);
	}
	skip_empty_line(line, data->fd_cub);
	if (*line)
		print_clean_reading(data, *line, "Empty line in map");
}

int	parse_file(t_data *data)
{
	char	*line;

	data->fd_cub = open(data->map_path, O_RDONLY);
	if (data->fd_cub < 0)
		return (print_clean(data, "Failed to open file"), 0);
	line = get_next_line(data->fd_cub, 0);
	skip_empty_line(&line, data->fd_cub);
	if (!line)
	{
		print_clean(data, "Empty .cub file");
		return (close(data->fd_cub), 0);
	}
	parse_textures(data, &line);
	parse_map(data, &line);
	clean_map_reading(line, data->fd_cub);
	fill_map(data);
	return (1);
}
