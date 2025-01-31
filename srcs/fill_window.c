/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elilliu <elilliu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 14:23:29 by elilliu           #+#    #+#             */
/*   Updated: 2025/01/31 19:41:11 by elilliu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	add_player(t_data *data)
{
	int	x;
	int	y;

	x = data->player.x - 4;
	while (x != data->player.x + 4)
	{
		y = data->player.y - 4;
		while (y != data->player.y + 4)
		{
			put_pixel_img(data->background, x, y, 0xcd5c5c);
			y++;
		}
		x++;
	}
}

void	add_ray(t_data *data)
{
	int	i;
	int	x;
	int	y;

	i = 0;
	x = data->player.x;
	y = data->player.y;
	while (i <= 50)
	{
		put_pixel_img(data->background, x, y, 0xcd5c5c);
		x += data->player.delta_x;
		y += data->player.delta_y;
		i++;
	}
}

void	put_white_square(t_data *data, int x, int y, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			put_pixel_img(data->background, x + i, y + j, 0xf8f8ff);
			j++;
		}
		i++;
	}
}

void	put_grey_square(t_data *data, int x, int y, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			put_pixel_img(data->background, x + i, y + j, 0x2f4f4f);
			j++;
		}
		i++;
	}
}

void	new_square(t_data *data, int x, int y, int type)
{
	if (type == '1')
		put_grey_square(data, x, y, 64);
	else if (type == '0' || type == 'N')
		put_white_square(data, x, y, 64);
}

void	fill_window(t_data *data)
{
	int	row;
	int	i;

	data->background.img_ptr = mlx_new_image(data->mlx_ptr, 1080, 1080);
	data->background.w = 1080;
	data->background.h = 1080;
	data->background.addr = mlx_get_data_addr(data->background.img_ptr,
		&data->background.bpp, &data->background.line_len, &data->background.endian);
	row = 0;
	while (data->map.tab[row])
	{
		i = 0;
		while (data->map.tab[row][i])
		{
			new_square(data, i * 64, row * 64, data->map.tab[row][i]);
			i++;
		}
		row++;
	}
	add_player(data);
	add_ray(data);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->background.img_ptr, 0, 0);
	mlx_destroy_image(data->mlx_ptr, data->background.img_ptr);
}
