/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bineleon <neleon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 12:20:55 by bineleon          #+#    #+#             */
/*   Updated: 2025/02/03 16:25:33 by bineleon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static t_bool empty_around(char **map, int i, int j)
{
  	int len;

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

void	map_validation(t_data *data, char **map)
{
	int i;
	int j;
	int player;

	i = 0;
  player = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
      if (!is_valid_char_map(map[i][j]))
        print_clean_map(data, "Unvalid char in map");
      if (is_player_char(map[i][j]))
        player++;
			if (empty_around(map, i, j))
        print_clean_map(data, "Unclosed map");
			j = j + 1;
		}
		i = i + 1;
	}
  if (player != 1)
    print_clean_map(data, "Map should have 1 player");
}

// t_bool	is_valid_p_count(char **map)
// {
// 	int i;
// 	int j;
//   int player;

// 	i = 0;
// 	while (map[i])
// 	{
// 		j = 0;
// 		while (map[i][j])
// 		{
// 			if (is_player_char(map[i][j]))
//         player++;
// 			j = j + 1;
// 		}
// 		i = i + 1;
// 	}
//   if (player != 1)
//     return (false);
// 	return (true);
// }
