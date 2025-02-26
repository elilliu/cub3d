/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neleon <neleon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 12:54:16 by elilliu@stu       #+#    #+#             */
/*   Updated: 2025/02/26 15:21:24 by neleon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d_bonus.h"

void	move_player_up(t_data *data)
{
	int	x;
	int	y;

	x = ((int)data->player.x + (int)data->player.delta_x) / data->img_size;
	y = ((int)data->player.y + (int)data->player.delta_y) / data->img_size;
	if (data->map.tab[y][x] != WALL)
	{
		data->player.x += data->player.delta_x;
		data->player.y += data->player.delta_y;
		fill_window(data);
	}
}

void	move_player_left(t_data *data)
{
	float	angle;
	float	delta_x;
	float	delta_y;
	int	x;
	int	y;

	angle = data->player.angle - 90;
	if (angle < 0)
		angle += 360;
	delta_x = cos(deg_to_rad(angle)) * 5;
	delta_y = sin(deg_to_rad(angle)) * 5;
	x = ((int)data->player.x + (int)delta_x) / data->img_size;
	y = ((int)data->player.y + (int)delta_y) / data->img_size;
	if (data->map.tab[y][x] != WALL)
	{
		data->player.x += delta_x;
		data->player.y += delta_y;
		fill_window(data);
	}
}

void	move_player_down(t_data *data)
{
	int	x;
	int	y;

	x = ((int)data->player.x - (int)data->player.delta_x) / data->img_size;
	y = ((int)data->player.y - (int)data->player.delta_y) / data->img_size;
	if (data->map.tab[y][x] != WALL)
	{
		data->player.x -= data->player.delta_x;
		data->player.y -= data->player.delta_y;
		fill_window(data);
	}
}

void	move_player_right(t_data *data)
{
	float	angle;
	float	delta_x;
	float	delta_y;
	int	x;
	int	y;

	angle = data->player.angle + 90;
	if (angle > 359)
		angle -= 360;
	delta_x = cos(deg_to_rad(angle)) * 5;
	delta_y = sin(deg_to_rad(angle)) * 5;
	x = ((int)data->player.x + (int)delta_x) / data->img_size;
	y = ((int)data->player.y + (int)delta_y) / data->img_size;
	if (data->map.tab[y][x] != WALL)
	{
		data->player.x += delta_x;
		data->player.y += delta_y;
		fill_window(data);
	}
}
