/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neleon <neleon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 16:15:52 by neleon            #+#    #+#             */
/*   Updated: 2025/02/28 17:54:11 by neleon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

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
	// printf("path : [%s], len : [%d]\n", path, len);
	return (len);
}

int	set_texture_path(char **texture, char *line, int start)
{
	int	len;

	if (*texture)
		return (0);
	len = path_len(&line[start]);
	*texture = gc_mem(MALLOC, len + 1, NULL);
	if (!*texture)
		return (print_error("Memory allocation failed"), 0);
	ft_strlcpy(*texture, &line[start], len + 1);
	return (1);
}

int	extract_t_path(char *line, t_data *data)
{
	int	texture;
	int	i;

	texture = check_texture(line);
	if (texture == -1)
		return (print_error("Invalid texture identifier"), 0);
	i = skip_tex_type(line, 0, 2);
	if (texture == T_NO)
		return (set_texture_path(&data->t_paths.t_no, line, i));
	if (texture == T_SO)
		return (set_texture_path(&data->t_paths.t_so, line, i));
	if (texture == T_WE)
		return (set_texture_path(&data->t_paths.t_we, line, i));
	if (texture == T_EA)
		return (set_texture_path(&data->t_paths.t_ea, line, i));
	return (0);
}

int	extract_rgb(char *line, t_data *data)
{
	int	texture;
	int	i;

	texture = check_texture(line);
	if (texture == -1)
		return (print_error("Invalid RGB identifier"), 0);
	i = skip_tex_type(line, 0, 1);
	if (texture == T_FL)
		return (set_texture_path(&data->t_paths.t_fl, line, i));
	if (texture == T_CE)
		return (set_texture_path(&data->t_paths.t_ce, line, i));
	return (0);
}

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

void	check_textures(t_data *data, char *line, int *texture_count)
{
	if (*texture_count >= 6)
		print_clean_reading(data, line, "Too many textures in .cub file");
	if (!is_texture(line) && !empty_line(line))
		print_clean_reading(data, line, "Wrong texture format in .cub file");
	if (is_texture(line) && !empty_line(line))
	{
		if (!extract_line(line, data))
			print_clean_reading(data, line,
				"Duplicate texture path or invalid texture");
		else
			*texture_count += 1;
	}
}

int	parse_textures(t_data *data, char **line)
{
	int	texture_count;

	texture_count = 0;
	while (*line && texture_count < 6)
	{
		check_textures(data, *line, &texture_count);
		free(*line);
		*line = get_next_line(data->fd_cub, 0);
	}
	return (1);
}

int	parse_file(t_data *data)
{
	char	*line;

	data->fd_cub = open(data->map_path, O_RDONLY);
	if (data->fd_cub < 0)
		return (print_error("Failed to open file"), 0);
	line = get_next_line(data->fd_cub, 0);
	skip_empty_line(&line, data->fd_cub);
	if (!line)
	{
		print_error("Empty .cub file");
		return (close(data->fd_cub), 0);
	}
	parse_textures(data, &line);
	parse_map(data, &line);
	clean_map_reading(line, data->fd_cub);
	fill_map(data);
	return (1);
}
