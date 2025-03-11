/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elilliu <elilliu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 12:54:16 by elilliu@stu       #+#    #+#             */
/*   Updated: 2025/03/11 12:23:41 by elilliu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	is_wall_collision(t_data *data, float next_x, float next_y)
{
	int	x;
	int	y;

	x = (int)next_x / data->img_size;
	y = (int)next_y / data->img_size;
	return (data->map.tab[y][x] == WALL);
}

void	move_player_up(t_data *data)
{
	float	next_x;
	float	next_y;

	next_x = data->player.x + data->player.delta_x;
	next_y = data->player.y + data->player.delta_y;
	if (!is_wall_collision(data, next_x + WALL_DIST, next_y + WALL_DIST)
		&& !is_wall_collision(data, next_x - WALL_DIST, next_y - WALL_DIST))
	{
		data->player.x = next_x;
		data->player.y = next_y;
		fill_window(data);
	}
}

void	move_player_down(t_data *data)
{
	float	next_x;
	float	next_y;

	next_x = data->player.x - data->player.delta_x;
	next_y = data->player.y - data->player.delta_y;
	if (!is_wall_collision(data, next_x + WALL_DIST, next_y + WALL_DIST)
		&& !is_wall_collision(data, next_x - WALL_DIST, next_y - WALL_DIST))
	{
		data->player.x = next_x;
		data->player.y = next_y;
		fill_window(data);
	}
}

void	move_player_left(t_data *data)
{
	float	angle;
	float	delta_x;
	float	delta_y;
	float	next_x;
	float	next_y;

	angle = data->player.angle - 90;
	if (angle < 0)
	angle += 360;
	delta_x = cos(deg_to_rad(angle)) * PLAYER_SPEED;
	delta_y = sin(deg_to_rad(angle)) * PLAYER_SPEED;
	next_x = data->player.x + delta_x;
	next_y = data->player.y + delta_y;
	if (!is_wall_collision(data, next_x + WALL_DIST, next_y + WALL_DIST)
		&& !is_wall_collision(data, next_x - WALL_DIST, next_y - WALL_DIST))
	{
		data->player.x = next_x;
		data->player.y = next_y;
		fill_window(data);
	}
}

void	move_player_right(t_data *data)
{
	float	angle;
	float	delta_x;
	float	delta_y;
	float	next_x;
	float	next_y;

	angle = data->player.angle + 90;
	if (angle > 359)
	angle -= 360;
	delta_x = cos(deg_to_rad(angle)) * PLAYER_SPEED;
	delta_y = sin(deg_to_rad(angle)) * PLAYER_SPEED;
	next_x = data->player.x + delta_x;
	next_y = data->player.y + delta_y;
	if (!is_wall_collision(data, next_x + WALL_DIST, next_y + WALL_DIST)
		&& !is_wall_collision(data, next_x - WALL_DIST, next_y - WALL_DIST))
	{
		data->player.x = next_x;
		data->player.y = next_y;
		fill_window(data);
	}
}
