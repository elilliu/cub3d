/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neleon <neleon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 18:59:22 by neleon            #+#    #+#             */
/*   Updated: 2025/02/26 19:45:59 by neleon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d_bonus.h"

void	mouse_rotate_left(t_data *data)
{
	data->player.angle -= 5;
	if (data->player.angle < 0)
		data->player.angle += 360;
	data->player.delta_x = cos(deg_to_rad(data->player.angle)) * 5;
	data->player.delta_y = sin(deg_to_rad(data->player.angle)) * 5;
	fill_window(data);
}

void	mouse_rotate_right(t_data *data)
{
	data->player.angle += 5;
	if (data->player.angle > 359)
		data->player.angle -= 360;
	data->player.delta_x = cos(deg_to_rad(data->player.angle)) * 5;
	data->player.delta_y = sin(deg_to_rad(data->player.angle)) * 5;
	fill_window(data);
}

int     handle_mouse(int x, int y, t_data *data)
{
	// if (y != -1)
	// 	data->player.angle += (x - data->mouse_x) / 3;
	// g->mouse_x = x;
	// return (0);
    if (x < WIDTH / 2)
        mouse_rotate_left;
    else
        mouse_rotate_right;
}