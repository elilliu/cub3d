/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bineleon <neleon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 12:20:55 by bineleon          #+#    #+#             */
/*   Updated: 2025/02/03 12:32:16 by bineleon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

t_bool	is_closed_map(char **map)
{
	int i;
	int j;
	int len;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == '0' || is_player_char(map[i][j]))
			{
				if (i - 1 < 0)
					return (false);
				len = ft_strlen(map[i - 1]);
				if (j >= len || map[i - 1][j] == ' ')
					return (false);
				if (map[i + 1] == 0)
					return (false);
				len = ft_strlen(map[i + 1]);
				if (j >= len || map[i + 1][j] == ' ')
					return (false);
				if (j - 1 < 0)
					return (false);
				if (map[i][j - 1] == ' ')
					return (false);
				len = ft_strlen(map[i]);
				if (j + 1 >= len || map[i][j + 1] == ' ')
					return (false);
			}
			j = j + 1;
		}
		i = i + 1;
	}
	return (true);
}

t_bool	is_valid_p_count(char **map)
{
	int i;
	int j;
  int player;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (is_player_char(map[i][j]))
        player++;
			j = j + 1;
		}
		i = i + 1;
	}
  if (player != 1)
    return (false);
	return (true);
}
