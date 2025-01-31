/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elilliu <elilliu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 12:54:16 by elilliu@stu       #+#    #+#             */
/*   Updated: 2025/01/31 19:33:12 by elilliu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	move_player_up(t_data *data)
{
	data->player.x += data->player.delta_x;
	data->player.y += data->player.delta_y;
	printf("je suis la\n");
	fill_window(data);
}

void	move_player_left(t_data *data)
{
	float	angle;
	float	delta_x;
	float	delta_y;

	angle = data->player.angle - (PI / 2);
	if (angle < 0)
		angle += 2 * PI;
	delta_x = cos(angle) * 5;
	delta_y = sin(angle) * 5;
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

	angle = data->player.angle - (PI / 2);
	if (angle < 0)
		angle += 2 * PI;
	delta_x = cos(angle) * 5;
	delta_y = sin(angle) * 5;
	data->player.x -= delta_x;
	data->player.y -= delta_y;
	fill_window(data);
}
