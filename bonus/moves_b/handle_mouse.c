/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_mouse.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elilliu <elilliu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 15:51:46 by elilliu           #+#    #+#             */
/*   Updated: 2025/03/17 18:05:42 by elilliu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d_bonus.h"

long	elapsed_time(struct timeval start)
{
	struct timeval	current;
	time_t			time;

	gettimeofday(&current, NULL);
	time = (current.tv_sec - start.tv_sec) * 1000000
		+ (current.tv_usec - start.tv_usec);
	return (time / 1000);
}

void	toggle_mouse(t_data *data)
{
	if (data->mouse_on)
		data->mouse_on = false;
	else
		data->mouse_on = true;
}

void	timer(t_data *data)
{
	if (elapsed_time(data->start) > TIMER)
	{
		data->door++;
		if (data->door == 5)
			data->door = 1;
		fill_window(data);
		gettimeofday(&data->start, NULL);
	}
	if (elapsed_time(data->mike) > MIKE)
	{
		data->mike_no++;
		if (data->mike_no == 5)
			data->mike_no = 1;
		fill_window(data);
		gettimeofday(&data->mike, NULL);
	}
}

int	handle_mouse(t_data *data)
{
	timer(data);
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
