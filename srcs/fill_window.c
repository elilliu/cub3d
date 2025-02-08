/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elilliu@student.42.fr <elilliu>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 16:50:05 by elilliu           #+#    #+#             */
/*   Updated: 2025/02/08 22:28:01 by elilliu@stu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

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

void	add_ray(t_data *data)
{
	float	x;
	float	y;
	int		i;

	i = 0;
	x = data->player.x;
	y = data->player.y;
	while (i <= 50)
	{
		put_pixel_img(data->background, x, y, 0x0);
		x += data->player.delta_x;
		y += data->player.delta_y;
		i++;
	}
}

void	check_horizontal_lines(t_data *data)
{
	float	y;
	float	x;

	if (data->player.angle > 0 && data->player.angle < 180)
		y = ((int)data->player.y / 64) * 64 + 64;
	else if (data->player.angle > 180 && data->player.angle <= 359)
		y = ((int)data->player.y / 64) * 64 - 0.0001;
	else
		y = data->player.y;
	if (tan(deg_to_rad(data->player.angle)) == 0)
		x = data->player.x;
	else
		x = data->player.x + (y - data->player.y) / tan(deg_to_rad(data->player.angle));
	put_square(data, x - 2, y - 2, 0xcd5c5c, 4);
	while ((int)y / 64 > 0 && (int)y / 64 < data->map.rows && (int)x / 64 > 0 && (int)x / 64 < data->map.columns && data->map.tab[(int)y / 64][(int)x / 64] != '1')
	{
		if (data->player.angle > 0 && data->player.angle < 180)
			y += 64;
		else if (data->player.angle > 180 && data->player.angle <= 359)
			y -= 64;
		else
			break ;
		if (tan(deg_to_rad(data->player.angle)) != 0)
			x = data->player.x + (y - data->player.y) / tan(deg_to_rad(data->player.angle));
		if (x > 0 && y > 0)
			put_square(data, x - 2, y - 2, 0xcd5c5c, 4);
	}
	// return (sqrt((x - data->player.x) + (y - data->player.y)));
}

void	check_vertical_lines(t_data *data)
{
	float	x;
	float	y;

	if (data->player.angle > 270 || data->player.angle < 90)
		x = ((int)data->player.x / 64) * 64 + 64;
	else if (data->player.angle > 90 && data->player.angle < 270)
		x = ((int)data->player.x / 64) * 64 - 0.0001;
	else
		x = data->player.x;
	y = data->player.y + (x - data->player.x) * tan(deg_to_rad(data->player.angle));
	put_square(data, x - 2, y - 2, 0x8a2be2, 4);
	while ((int)y / 64 > 0 && (int)y / 64 < data->map.rows && (int)x / 64 > 0 && (int)x / 64 < data->map.columns && data->map.tab[(int)y / 64][(int)x / 64] != '1')
	{
		if (data->player.angle > 270 || data->player.angle < 90)
			x += 64;
		else if (data->player.angle > 90 && data->player.angle < 270)
			x -= 64;
		else
			break ;
		y = data->player.y + (x - data->player.x) * tan(deg_to_rad(data->player.angle));
		if (x > 0 && y > 0)
			put_square(data, x - 2, y - 2, 0x8a2be2, 4);
	}
}

void	add_player(t_data *data)
{
	float	x;
	float	y;

	x = data->player.x - 4;
	while (x != data->player.x + 4)
	{
		y = data->player.y - 4;
		while (y != data->player.y + 4)
		{
			put_pixel_img(data->background, x, y, 0x0);
			y++;
		}
		x++;
	}
}

void	add_background(t_data *data)
{
	int	line;
	int	column;

	line = 0;
	while (line < data->map.rows)
	{
		column = 0;
		while (column < data->map.columns)
		{
			if (data->map.tab[line][column] == '1')
				put_square(data, column * 64, line * 64, 0x2f4f4f, 64);
			else if (data->map.tab[line][column] == '0' || data->map.tab[line][column] == 'N')
				put_square(data, column * 64, line * 64, 0xf8f8ff, 64);
			column++;
		}
		line++;
	}
}

void	fill_window(t_data *data)
{
	data->background.img_ptr = mlx_new_image(data->mlx_ptr, WIDTH, HEIGHT);
	data->background.w = WIDTH;
	data->background.h = HEIGHT;
	data->background.addr = mlx_get_data_addr(data->background.img_ptr,
		&data->background.bpp, &data->background.line_len, &data->background.endian);
	add_background(data);
	printf("angle: %f\n", data->player.angle);
	// printf("radian: %f\n", deg_to_rad(data->player.angle));
	add_player(data);
	add_ray(data);
	check_horizontal_lines(data);
	check_vertical_lines(data);
	// add_ceiling(data);
	// add_floor(data);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->background.img_ptr, 0, 0);
	mlx_destroy_image(data->mlx_ptr, data->background.img_ptr);
}
