/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neleon <neleon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 16:50:05 by elilliu           #+#    #+#             */
/*   Updated: 2025/03/17 19:54:59 by neleon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d_bonus.h"

void	sub_add_rays(t_data *data, t_ray *ray, float step)
{
	int	i;

	i = 0;
	while (i < WIDTH)
	{
		ray->nb = i;
		ray->horizontal_distance = check_horizontal_lines(data, ray);
		ray->vertical_distance = check_vertical_lines(data, ray);
		if (ray->horizontal_distance < ray->vertical_distance)
			put_horizontal_wall(data, *ray);
		else
			put_vertical_wall(data, *ray);
		ray->angle += step;
		if (ray->angle >= 360)
			ray->angle -= 360.0;
		i++;
	}
}

void	add_rays(t_data *data)
{
	t_ray	ray;
	float	step;
	float	fov;
	float	width;

	fov = (float)FOV;
	ray.angle = data->player.angle - fov / 2;
	width = (float)WIDTH;
	step = fov / width;
	if (ray.angle < 0)
		ray.angle += 360;
	sub_add_rays(data, &ray, step);
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

void	fill_window(t_data *data)
{
	data->background.img_ptr = mlx_new_image(data->mlx_ptr, WIDTH, HEIGHT);
	data->background.w = WIDTH;
	data->background.h = HEIGHT;
	data->background.addr = mlx_get_data_addr(data->background.img_ptr,
			&data->background.bpp, &data->background.line_len,
			&data->background.endian);
	data->test = 1;
	add_ceiling(data);
	add_floor(data);
	add_rays(data);
	minimap(data);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
		data->background.img_ptr, 0, 0);
	mlx_destroy_image(data->mlx_ptr, data->background.img_ptr);
}
