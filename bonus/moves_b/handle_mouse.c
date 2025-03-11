/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_mouse.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elilliu <elilliu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 15:51:46 by elilliu           #+#    #+#             */
/*   Updated: 2025/03/11 16:01:15 by elilliu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d_bonus.h"

void	handle_mouse(t_data *data)
{
	mlx_mouse_get_pos(data->mlx_ptr, data->win_ptr,
		&data->mouse.x, &data->mouse.y);
	if (data->mouse.x >= (WIDTH / 2 + 10))
		rotate_player_right(data);
	if (data->mouse.y <= (WIDTH / 2 - 10))
		rotate_player_left(data);
	mlx_mouse_move(data->mlx_ptr, data->win_ptr, WIDTH / 2, HEIGHT / 2);
}
