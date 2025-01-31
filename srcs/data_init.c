/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bineleon <neleon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: Invalid date        by                   #+#    #+#             */
/*   Updated: 2025/01/31 11:35:29 by bineleon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

t_data	*get_data(void)
{
	static t_data	data;

	return (&data);
}

int	player_init(t_data *data)
{
	int	i;
	int	row;

	row = 0;
	while (data->map.tab[row])
	{
		i = 0;
		while (data->map.tab[row][i])
		{
			if (data->map.tab[row][i] == 'N')
			{
				data->player.square_x = i;
				data->player.square_y = row;
				data->player.x = 28;
				data->player.y = 28;
				return (1);
			}
			i++;
		}
		row++;
	}
	return (0);
}

int	data_init(t_data *data, char *str)
{
	data->map_path = gc_strdup(str);
	data->map.rows = 0;
  data->row_count = 0;
	data->sizex = 0;
	data->sizey = 0;
  data->map2 = NULL;
  data->t_no = NULL;
  data->t_so = NULL;
  data->t_ea = NULL;
  data->t_we = NULL;
  data->t_ce = NULL;
  data->t_fl = NULL;
	// if (!map_init(data))
	// 	return (0);
  parse_file(data);
	if (!player_init(data))
		return (0);
	data->mlx_ptr = mlx_init();
	if (!data->mlx_ptr)
		return (0);
	mlx_get_screen_size(data->mlx_ptr, &data->sizex, &data->sizey);
	data->win_ptr = mlx_new_window(data->mlx_ptr, data->sizex,
			data->sizey, "cub3d");
	if (!data->win_ptr)
		return (free(data->mlx_ptr), 0);
	return (1);
}
