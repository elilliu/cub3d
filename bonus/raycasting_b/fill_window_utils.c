/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_window_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neleon <neleon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 14:46:50 by elilliu@stu       #+#    #+#             */
/*   Updated: 2025/03/04 15:21:11 by neleon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d_bonus.h"

void	print_line(t_data *data, float x, float y, float size, int color)
{
	int	i;

	i = 0;
	while (i <= size)
	{
		put_pixel_img(data->background, x, y, color);
		y++;
		i++;
	}
}

void	add_ceiling(t_data *data)
{
	int	x;
	int	y;
  int color;

	y = 0;
  color = rgb_to_int(data->t_paths.ce.r, data->t_paths.ce.g, data->t_paths.ce.b);
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
  int color;

	y = HEIGHT / 2;
  color = rgb_to_int(data->t_paths.fl.r, data->t_paths.fl.g, data->t_paths.fl.b);
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
