/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elilliu@student.42.fr <elilliu>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 12:54:16 by elilliu@stu       #+#    #+#             */
/*   Updated: 2025/02/08 14:03:08 by elilliu@stu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	move_player_up(t_data *data)
{
	data->player.x += data->player.delta_x;
	data->player.y += data->player.delta_y;
	fill_window(data);
}

void	move_player_left(t_data *data)
{
	float	angle;
	float	delta_x;
	float	delta_y;

	angle = data->player.angle - 90;
	if (angle < 0)
		angle += 360;
	delta_x = cos(deg_to_rad(angle)) * 5;
	delta_y = sin(deg_to_rad(angle)) * 5;
	data->player.x += delta_x;
	data->player.y += delta_y;
	fill_window(data);
}

void	move_player_down(t_data *data)
{
	data->player.x -= data->player.delta_x;
	data->player.y -= data->player.delta_y;
	fill_window(data);
}

void	move_player_right(t_data *data)
{
	float	angle;
	float	delta_x;
	float	delta_y;

	angle = data->player.angle + 90;
	if (angle > 359)
		angle -= 360;
	delta_x = cos(deg_to_rad(angle)) * 5;
	delta_y = sin(deg_to_rad(angle)) * 5;
	data->player.x += delta_x;
	data->player.y += delta_y;
	fill_window(data);
}
