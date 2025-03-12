/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bineleon <neleon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 13:48:09 by neleon            #+#    #+#             */
/*   Updated: 2025/03/12 09:57:36 by bineleon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d_bonus.h"

t_bool	is_player_char(char c)
{
	if (c == PL_NO || c == PL_SO || c == PL_WE || c == PL_EA)
		return (true);
	return (false);
}

t_bool	is_valid_char_map(char c)
{
	if (c == FLOOR || c == WALL || is_player_char(c) || c == ' ' || is_door(c))
		return (true);
	return (false);
}

t_bool	is_wall_texture(char *line)
{
	int	i;

	i = 0;
	i = skip_whitespaces(line, 0);
	if (line[i] && line[i] == 'N' && line[i + 1]
		&& line[i + 1] == 'O' && line[i + 2] && is_whitespace(line[i + 2]))
		return (true);
	else if (line[i] && line[i] == 'S' && line[i + 1] && line[i + 1] == 'O'
		&& line[i + 2] && is_whitespace(line[i + 2]))
		return (true);
	else if (line[i] && line[i] == 'W' && line[i + 1] && line[i + 1] == 'E'
		&& line[i + 2] && is_whitespace(line[i + 2]))
		return (true);
	else if (line[i] && line[i] == 'E' && line[i + 1] && line[i + 1] == 'A'
		&& line[i + 2] && is_whitespace(line[i + 2]))
		return (true);
	return (false);
}

static t_bool	is_other_texture(char *line)
{
	int	i;

	i = 0;
	i = skip_whitespaces(line, 0);
	if (line[i] && line[i] == 'F' && line[i + 1] && is_whitespace(line[i + 1]))
		return (true);
	else if (line[i] && line[i] == 'C' && line[i + 1]
		&& is_whitespace(line[i + 1]))
		return (true);
	return (false);
}

t_bool	is_texture(char *line)
{
	if (is_wall_texture(line) || is_other_texture(line) || empty_line(line))
		return (true);
	return (false);
}
