/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elilliu@student.42.fr <elilliu>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 16:50:05 by elilliu           #+#    #+#             */
/*   Updated: 2025/02/15 23:49:26 by elilliu@stu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

double	check_horizontal_lines(t_data *data, float angle)
{
	float	y;
	float	x;

	if (angle > 0 && angle < 180)
		y = ((int)data->player.y / 64) * 64 + 64;
	else if (angle > 180 && angle < 360)
		y = ((int)data->player.y / 64) * 64 - 0.0001;
	else
		return (0);
	if (tan(deg_to_rad(angle)) == 0)
		x = data->player.x;
	else
		x = data->player.x + (y - data->player.y) / tan(deg_to_rad(angle));
	while ((int)y / 64 > 0 && (int)y / 64 < data->map.rows && (int)x / 64 > 0 && (int)x / 64 < data->map.columns && data->map.tab[(int)y / 64][(int)x / 64] != '1')
	{
		if (angle > 0 && angle < 180)
			y += 64;
		else if (angle > 180 && angle < 360)
			y -= 64;
		else
			break ;
		if (tan(deg_to_rad(angle)) != 0)
			x = data->player.x + (y - data->player.y) / tan(deg_to_rad(angle));
	}
	return (sqrt((x - data->player.x) * (x - data->player.x) + (y - data->player.y) * (y - data->player.y)));
}

double	check_vertical_lines(t_data *data, float angle)
{
	float	x;
	float	y;

	if (angle > 270 || angle < 90)
		x = ((int)data->player.x / 64) * 64 + 64;
	else if (angle > 90 && angle < 270)
		x = ((int)data->player.x / 64) * 64 - 0.0001;
	else
		return (0);
	y = data->player.y + (x - data->player.x) * tan(deg_to_rad(angle));
	while ((int)y / 64 > 0 && (int)y / 64 < data->map.rows && (int)x / 64 > 0 && (int)x / 64 < data->map.columns && data->map.tab[(int)y / 64][(int)x / 64] != '1')
	{
		if (angle > 270 || angle < 90)
			x += 64;
		else if (angle > 90 && angle < 270)
			x -= 64;
		y = data->player.y + (x - data->player.x) * tan(deg_to_rad(angle));
	}
	return (sqrt((x - data->player.x) * (x - data->player.x) + (y - data->player.y) * (y - data->player.y)));
}

void	add_rays(t_data *data)
{
	t_ray	ray;
	float	step;
	float	fov;
	float	width;
	int		i;

	fov = (float)FOV;
	ray.angle = data->player.angle - fov / 2;
	width = (float)WIDTH;
	step = fov / width;
	// printf("step: %f\n", step);
	if (ray.angle < 0)
		ray.angle += 360;
	i = 0;
	while (i < WIDTH)
	{
		ray.nb = i;
		printf("angle: %f\n", ray.angle);
		ray.horizontal_distance = check_horizontal_lines(data, ray.angle);
		ray.vertical_distance = check_vertical_lines(data, ray.angle);
		if (ray.horizontal_distance < ray.vertical_distance)
			put_horizontal_wall(data, ray);
		else
			put_vertical_wall(data, ray);
		ray.angle += step;
		if (ray.angle >= 360)
			ray.angle -= 360.0;
		i++;
	}
	// printf("i: %d\n", i);
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
	// add_background(data);int
	// printf("angle: %f\n", data->player.angle);
	// printf("radian: %f\n", deg_to_rad(data->player.angle));
	// add_player(data);
	add_ceiling(data);
	add_floor(data);
	add_rays(data);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->background.img_ptr, 0, 0);
	mlx_destroy_image(data->mlx_ptr, data->background.img_ptr);
}
