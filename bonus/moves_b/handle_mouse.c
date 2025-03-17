/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_mouse.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elilliu <elilliu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 15:51:46 by elilliu           #+#    #+#             */
/*   Updated: 2025/03/17 16:15:38 by elilliu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d_bonus.h"

void	toggle_mouse(t_data *data)
{
	if (data->mouse_on)
		data->mouse_on = false;
	else
		data->mouse_on = true;
}

int	handle_mouse(t_data *data)
{
	if (data->timer == DOOR_SPEED * 4 + 1)
		data->timer = 0;
	if (data->timer == DOOR_SPEED || data->timer == 2 * DOOR_SPEED
		|| data->timer == 3 * DOOR_SPEED || data->timer == 4 * DOOR_SPEED)
	{
		data->door++;
		if (data->door == 5)
			data->door = 1;
		fill_window(data);
	}
	data->timer++;
	if (data->mouse_on)
	{
		mlx_mouse_get_pos(data->mlx_ptr, data->win_ptr, &data->mouse.x,
			&data->mouse.y);
		if (data->mouse.x >= (WIDTH / 2 + 10))
			rotate_player_right(data);
		if (data->mouse.x <= (WIDTH / 2 - 10))
			rotate_player_left(data);
		mlx_mouse_move(data->mlx_ptr, data->win_ptr, WIDTH / 2, HEIGHT / 2);
		return (1);
	}
	return (0);
}
