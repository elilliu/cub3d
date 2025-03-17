/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_textures.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neleon <neleon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 11:50:20 by neleon            #+#    #+#             */
/*   Updated: 2025/03/13 11:51:38 by neleon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

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
