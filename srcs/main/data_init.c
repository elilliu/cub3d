/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neleon <neleon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: Invalid date        by                   #+#    #+#             */
/*   Updated: 2025/03/04 16:28:30 by neleon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

t_data	*get_data(void)
{
	static t_data	data;

	return (&data);
}

void    assign_player_angle(t_data *data)
{
    if (data->player_dir == PL_NO)
        data->player.angle = 270;
    else if (data->player_dir == PL_WE)
        data->player.angle = 180;
    else if (data->player_dir == PL_SO)
        data->player.angle = 90;
    else if (data->player_dir == PL_EA)
        data->player.angle = 360;
}

int	player_init(t_data *data)
{
	int	i;
	int	row;

	// data->player.angle = 270;
    assign_player_angle(data);
	// printf("cet coucouuuuu angle: %.16f\n", data->player.angle);
	// printf(" 3 * PI / 2: %.16f\n", 3 * PI / 2);
	data->player.delta_x = cos(deg_to_rad(data->player.angle)) * 5;
	// printf("cos: %f\n", data->player.delta_x);
	data->player.delta_y = sin(deg_to_rad(data->player.angle)) * 5;
	// printf("sin:e %f\n", data->player.delta_y);
	row = 0;
	while (data->map.tab[row])
	{
		i = 0;
		while (data->map.tab[row][i])
		{
			if (is_player_char(data->map.tab[row][i]))
			{
				data->player.x = i * data->img_size + data->img_size / 2;
				data->player.y = row * data->img_size + data->img_size / 2;
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
	data->map.columns = 0;
	data->img_size = IMG_SIZE;
	data->row_count = 0;
	data->map2 = NULL;
	data->t_paths.t_no = NULL;
	data->t_paths.t_so = NULL;
	data->t_paths.t_ea = NULL;
	data->t_paths.t_we = NULL;
	data->t_paths.t_ce = NULL;
	data->t_paths.t_fl = NULL;
	if (!parse_file(data))
		return (0);
	set_rgb(data);
	error_t_path(data);
	map_validation(data, data->map.tab);
	if (!player_init(data))
		return (0);
	data->mlx_ptr = mlx_init();
	if (!data->mlx_ptr)
		return (0);
	data->win_ptr = mlx_new_window(data->mlx_ptr, WIDTH, HEIGHT, "cub3d");
	if (!data->win_ptr)
		return (free(data->mlx_ptr), 0);
	return (1);
}
