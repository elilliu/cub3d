/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_window_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elilliu@student.42.fr <elilliu>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 14:46:50 by elilliu@stu       #+#    #+#             */
/*   Updated: 2025/02/10 17:32:22 by elilliu@stu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

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

	y = 0;
	while (y < HEIGHT / 2)
	{
		x = 0;
		while (x <= WIDTH)
		{
			put_pixel_img(data->background, x, y, 0x87ceeb);
			x++;
		}
		y++;
	}
}

void	add_floor(t_data *data)
{
	int	x;
	int	y;

	y = HEIGHT / 2;
	while (y <= HEIGHT)
	{
		x = 0;
		while (x <= WIDTH)
		{
			put_pixel_img(data->background, x, y, 0x2f4f4f);
			x++;
		}
		y++;
	}
}

void	put_square(t_data *data, int x, int y, int color, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			put_pixel_img(data->background, x + i, y + j, color);
			j++;
		}
		i++;
	}
}
