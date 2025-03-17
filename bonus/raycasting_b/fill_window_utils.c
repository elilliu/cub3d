/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_window_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elilliu <elilliu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 14:46:50 by elilliu@stu       #+#    #+#             */
/*   Updated: 2025/03/17 16:19:59 by elilliu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d_bonus.h"

void	add_ceiling(t_data *data)
{
	int	x;
	int	y;
	int	color;

	y = 0;
	color = rgb_to_int(data->t_paths.ce.r, data->t_paths.ce.g,
			data->t_paths.ce.b);
	while (y < HEIGHT / 2)
	{
		x = 0;
		while (x <= WIDTH)
		{
			put_pixel_img(data->background, x, y, color);
			x++;
		}
		y++;
	}
}

void	add_floor(t_data *data)
{
	int	x;
	int	y;
	int	color;

	y = HEIGHT / 2;
	color = rgb_to_int(data->t_paths.fl.r, data->t_paths.fl.g,
			data->t_paths.fl.b);
	while (y <= HEIGHT)
	{
		x = 0;
		while (x <= WIDTH)
		{
			put_pixel_img(data->background, x, y, color);
			x++;
		}
		y++;
	}
}

int	get_good_door_color(t_data *data, float x, float y)
{
	if (data->door == 1)
		return (get_pixel_img(data->textures[T_DO1], x,
				(int)y % data->textures[T_DO1].h));
	else if (data->door == 2)
		return (get_pixel_img(data->textures[T_DO2], x,
				(int)y % data->textures[T_DO2].h));
	else if (data->door == 3)
		return (get_pixel_img(data->textures[T_DO3], x,
				(int)y % data->textures[T_DO3].h));
	else if (data->door == 4)
		return (get_pixel_img(data->textures[T_DO4], x,
				(int)y % data->textures[T_DO4].h));
	return (0);
}
