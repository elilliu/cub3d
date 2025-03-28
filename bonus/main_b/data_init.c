/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elilliu <elilliu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 18:31:01 by neleon            #+#    #+#             */
/*   Updated: 2025/03/17 17:54:08 by elilliu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d_bonus.h"

t_data	*get_data(void)
{
	static t_data	data;

	return (&data);
}

void	assign_player_angle(t_data *data)
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

	assign_player_angle(data);
	data->player.delta_x = cos(deg_to_rad(data->player.angle)) * PLAYER_SPEED;
	data->player.delta_y = sin(deg_to_rad(data->player.angle)) * PLAYER_SPEED;
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

static void	init_data_values(t_data *data, char *str)
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
	data->t_paths.t_do = "./textures/cub_door_400_20.xpm";
	data->t_paths.t_do1 = "./textures/cub_door_400_20_1.xpm";
	data->t_paths.t_do2 = "./textures/cub_door_400_20_2.xpm";
	data->t_paths.t_do3 = "./textures/cub_door_400_20_3.xpm";
	data->t_paths.t_do4 = "./textures/cub_door_400_20_4.xpm";
	init_mike_no(data);
	data->mouse_on = false;
	data->door = 1;
	data->mike_no = 1;
}

int	data_init(t_data *data, char *str)
{
	init_data_values(data, str);
	if (!parse_file(data))
		return (0);
	set_rgb(data);
	error_t_path(data);
	map_validation(data, data->map.tab);
	if (!player_init(data))
		return (0);
	data->mlx_ptr = mlx_init();
	if (!data->mlx_ptr)
	{
		print_clean(data, "Could not initialize mlx");
		return (0);
	}
	init_textures(data);
	data->win_ptr = mlx_new_window(data->mlx_ptr, WIDTH, HEIGHT, "cub3d");
	if (!data->win_ptr)
		return (free(data->mlx_ptr), 0);
	return (1);
}
