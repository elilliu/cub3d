/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elilliu <elilliu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 17:37:15 by elilliu           #+#    #+#             */
/*   Updated: 2025/01/31 17:37:51 by elilliu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	rotate_player_left(t_data *data)
{
	data->player.angle -= 0.1;
	if (data->player.angle < 0)
		data->player.angle += 2 * PI;
	data->player.delta_x = cos(data->player.angle) * 5;
	data->player.delta_y = sin(data->player.angle) * 5;
	fill_window(data);
}

void	rotate_player_right(t_data *data)
{
	data->player.angle += 0.1;
	if (data->player.angle > 2 * PI)
		data->player.angle -= 2 * PI;
	data->player.delta_x = cos(data->player.angle) * 5;
	data->player.delta_y = sin(data->player.angle) * 5;
	fill_window(data);
}
