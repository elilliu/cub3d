/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_window_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neleon <neleon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 14:46:50 by elilliu@stu       #+#    #+#             */
/*   Updated: 2025/03/13 12:20:08 by neleon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

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
