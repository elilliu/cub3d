/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elilliu <elilliu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 12:20:55 by bineleon          #+#    #+#             */
/*   Updated: 2025/03/17 11:02:24 by elilliu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d_bonus.h"

static t_bool	empty_around(char **map, int i, int j)
{
	int	len;

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
	return (false);
}

static void	check_open_map(t_data *data, char **map, int i, int j)
{
	if (empty_around(map, i, j))
	{
		if (map[i][j] == '0' || is_player_char(map[i][j]))
			print_clean(data, "Unclosed map");
		else if (is_door(map[i][j]))
			print_clean(data, "Door should not be on outside wall");
		else if (is_door(map[i][j]))
			print_clean(data, "Door should not be on outside wall");
	}
}

void	map_validation(t_data *data, char **map)
{
	int	i;
	int	j;
	int	player;

	i = 0;
	player = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (!is_valid_char_map(map[i][j]))
				print_clean(data, "Invalid char in map");
			if (is_player_char(map[i][j]))
			{
				data->player_dir = map[i][j];
				player++;
			}
			check_open_map(data, map, i, j);
			j = j + 1;
		}
		i = i + 1;
	}
	if (player != 1)
		print_clean(data, "Map should have 1 player");
}
