/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elilliu <elilliu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 12:54:16 by elilliu@stu       #+#    #+#             */
/*   Updated: 2025/01/30 15:17:31 by elilliu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	move_player_up(t_data *data)
{
	data->player.x += data->player.delta_x;
	data->player.y += data->player.delta_y;
}

void	move_player_left(t_data *data)
{
	data->player.angle -= 0.1;
	if (data->player.angle < 0)
		data->player.angle += 2 * PI;
	data->player.delta_x = cos(data->player.angle) * 5;
	data->player.delta_y = sin(data->player.angle) * 5;
}

void	move_player_down(t_data *data)
{
	data->player.x -= data->player.delta_x;
	data->player.y -= data->player.delta_y;
}

void	move_player_right(t_data *data)
{
	data->player.angle += 0.1;
	if (data->player.angle > 2 * PI)
		data->player.angle -= 2 * PI;
	data->player.delta_x = cos(data->player.angle) * 5;
	data->player.delta_y = sin(data->player.angle) * 5;
}
