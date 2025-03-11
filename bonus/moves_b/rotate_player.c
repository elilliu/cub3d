/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elilliu <elilliu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 17:37:15 by elilliu           #+#    #+#             */
/*   Updated: 2025/03/11 12:26:18 by elilliu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	rotate_player_left(t_data *data)
{
	data->player.angle -= 5;
	if (data->player.angle < 0)
		data->player.angle += 360;
	data->player.delta_x = cos(deg_to_rad(data->player.angle)) * PLAYER_SPEED;
	data->player.delta_y = sin(deg_to_rad(data->player.angle)) * PLAYER_SPEED;
	fill_window(data);
}

void	rotate_player_right(t_data *data)
{
	data->player.angle += 5;
	if (data->player.angle > 359)
		data->player.angle -= 360;
	data->player.delta_x = cos(deg_to_rad(data->player.angle)) * PLAYER_SPEED;
	data->player.delta_y = sin(deg_to_rad(data->player.angle)) * PLAYER_SPEED;
	fill_window(data);
}
