/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neleon <neleon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 12:20:55 by bineleon          #+#    #+#             */
/*   Updated: 2025/03/13 12:04:27 by neleon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static t_bool	empty_around(char **map, int i, int j)
{
	int	len;

	if (map[i][j] == '0' || is_player_char(map[i][j]))
	{
		if (i - 1 < 0)
			return (true);
		len = ft_strlen(map[i - 1]);
		if (j >= len || map[i - 1][j] == ' ')
			return (true);
		if (map[i + 1] == 0)
			return (true);
		len = ft_strlen(map[i + 1]);
		if (j >= len || map[i + 1][j] == ' ')
			return (true);
		if (j - 1 < 0)
			return (true);
		if (map[i][j - 1] == ' ')
			return (true);
		len = ft_strlen(map[i]);
		if (j + 1 >= len || map[i][j + 1] == ' ')
			return (true);
	}
	return (false);
}

void	sub_map_validation(t_data *data, char **map, t_point p, int *player)
{
	if (!is_valid_char_map(map[p.i][p.j]))
		print_clean(data, "Invalid char in map");
	if (is_player_char(map[p.i][p.j]))
	{
		data->player_dir = map[p.i][p.j];
		*player += 1;
	}
	if (empty_around(map, p.i, p.j))
		print_clean(data, "Unclosed map");
}

void	map_validation(t_data *data, char **map)
{
	t_point	p;
	int		player;

	p.i = 0;
	player = 0;
	while (map[p.i])
	{
		p.j = 0;
		while (map[p.i][p.j])
		{
			sub_map_validation(data, map, p, &player);
			p.j = p.j + 1;
		}
		p.i = p.i + 1;
	}
	if (player != 1)
		print_clean(data, "Map should have 1 player");
}
