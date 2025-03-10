/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neleon <neleon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 17:37:15 by elilliu           #+#    #+#             */
/*   Updated: 2025/02/28 16:19:39 by neleon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	rotate_player_left(t_data *data)
{
	data->player.angle -= 5;
	if (data->player.angle < 0)
		data->player.angle += 360;
	data->player.delta_x = cos(deg_to_rad(data->player.angle)) * 5;
	// printf("cos: %f\n", data->player.delta_x);
	data->player.delta_y = sin(deg_to_rad(data->player.angle)) * 5;
	// printf("sin: %f\n", data->player.delta_y);
	fill_window(data);
}

void	rotate_player_right(t_data *data)
{
	data->player.angle += 5;
	if (data->player.angle > 359)
		data->player.angle -= 360;
	data->player.delta_x = cos(deg_to_rad(data->player.angle)) * 5;
	// printf("cos: %f\n", data->player.delta_x);
	data->player.delta_y = sin(deg_to_rad(data->player.angle)) * 5;
	// printf("sin: %f\n", data->player.delta_y);
	fill_window(data);
}
