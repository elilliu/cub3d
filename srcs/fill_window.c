/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elilliu@student.42.fr <elilliu>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 14:23:29 by elilliu           #+#    #+#             */
/*   Updated: 2025/02/06 17:14:24 by elilliu@stu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

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

void	check_vertical_lines(t_data *data)
{
	// printf("ray angle: %.16f\n", data->ray.angle);
	// printf("3 * PI / 2 = %.16f\n", 3 * PI / 2);
	data->ray.dof = 0;
	if (cos(deg_to_rad(data->player.angle)) > 0.001) // looking left
	{
		// printf("4\n");
		// printf("player x: %f\n", data->player.x);
		// printf("player x int: %d\n", (int)data->player.x);
		// printf("%d\n", (int)data->player.x / 64);
		data->ray.x = (((int)data->player.x / 64) * 64) + 64;
		// printf("ray x: %f\n", data->ray.x);
		data->ray.y = (data->player.x - data->ray.x) * data->ray.tangent + data->player.y;
		// printf("ray y: %f\n", data->ray.y);
		data->ray.x_offset = 64;
		data->ray.y_offset = -data->ray.x_offset * data->ray.tangent;
		// printf("xo: %f\n", data->ray.x_offset);
		// printf("yo: %f\n", data->ray.y_offset);
	}
	else if (cos(deg_to_rad(data->player.angle)) < -0.001) // looking right
	{
		// printf("5\n");
		data->ray.x = (((int)data->player.x / 64) * 64) - 0.0001;
		data->ray.y = (data->player.x - data->ray.x) * data->ray.tangent + data->player.y;
		data->ray.x_offset = -64;
		data->ray.y_offset = -data->ray.x_offset * data->ray.tangent;
		// printf("xo: %f\n", data->ray.x_offset);
		// printf("yo: %f\n", data->ray.y_offset);
	}
	else // looking up or down
	{
		// printf("6\n");
		// printf("bonsoir\n");
		data->ray.x = data->player.x;
		data->ray.y = data->player.y;
		data->ray.dof = 8;
	}
	// printf("je suis la\n");
	while (data->ray.dof < 8)
	{
		// printf("[%f][%f]\n", data->ray.x, data->ray.y);
		put_square(data, (int)data->ray.x - 2, (int)data->ray.y - 2, 0xcd5c5c, 4);
		data->ray.map_x = (int)data->ray.x / 64;
		data->ray.map_y = (int)data->ray.y / 64;
		// printf("[%d][%d]\n", data->ray.map_y, data->ray.map_x);
		if (data->map.tab[data->ray.map_y][data->ray.map_x] == '1')
			data->ray.dof = 8;
		else
		{
			data->ray.x += data->ray.x_offset;
			data->ray.y += data->ray.y_offset;
			data->ray.dof += 1;
		}
	}
	// printf("\n");
}

void	check_horizontal_lines(t_data *data)
{
	// printf("\n");
	data->ray.dof = 0;
	// printf("ray angle: %f\n", data->ray.angle);
	// printf("PI: %f\n", PI);
	if (sin(deg_to_rad(data->ray.angle)) > 0.001) // looking up
	{
		// printf("1\n");
		// printf("mais quest ce que tu fais la\n");
		data->ray.y = (((int)data->player.y / 64) * 64) - 0.0001;
		data->ray.x = (data->player.y - data->ray.y) * data->ray.ntangent + data->player.x;
		data->ray.y_offset = -64;
		data->ray.x_offset = -data->ray.y_offset * data->ray.ntangent;
	}
	else if (sin(deg_to_rad(data->ray.angle)) < -0.001) // looking down
	{
		// printf("2\n");
		// printf("mais quest ce que tu fais la\n");
		data->ray.y = (((int)data->player.y / 64) * 64) + 64;
		data->ray.x = (data->player.y - data->ray.y) * data->ray.ntangent + data->player.x;
		data->ray.y_offset = 64;
		data->ray.x_offset = -data->ray.y_offset * data->ray.ntangent;
	}
	else // looking left or right
	{
		printf("3\n");
		data->ray.x = data->player.x;
		data->ray.y = data->player.y;
		data->ray.dof = 8;
	}
	while (data->ray.dof < 8)
	{
		put_square(data, (int)data->ray.x - 2, (int)data->ray.y - 2, 0x8a2be2, 4);
		data->ray.map_x = (int)data->ray.x / 64;
		data->ray.map_y = (int)data->ray.y / 64;
		if (data->map.tab[data->ray.map_y][data->ray.map_x] == '1')
			data->ray.dof = 8;
		else
		{
			data->ray.x += data->ray.x_offset;
			data->ray.y += data->ray.y_offset;
			data->ray.dof += 1;
		}
	}
}

void	add_ray(t_data *data)
{
	printf("player angle: %f\n", data->player.angle);
	data->ray.angle = data->player.angle;
	data->ray.tangent = tan(deg_to_rad(data->ray.angle));
	// printf("tan: %f\n", data->ray.tangent);
	data->ray.ntangent = 1 / data->ray.tangent;
	// printf("ntan: %f\n", data->ray.ntangent);
	check_vertical_lines(data);
	check_horizontal_lines(data);
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

void	add_background(t_data *data)
{
	int	line;
	int	column;

	// printf("lines: %d\n", data->map.rows);
	// printf("columns: %d\n", data->map.columns);
	line = 0;
	while (line < data->map.rows)
	{
		column = 0;
		while (column < data->map.columns)
		{
			new_square(data, column * 64, line * 64, data->map.tab[line][column]);
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
	add_player(data);
	add_ray(data);
	// add_ceiling(data);
	// add_floor(data);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->background.img_ptr, 0, 0);
	mlx_destroy_image(data->mlx_ptr, data->background.img_ptr);
}
