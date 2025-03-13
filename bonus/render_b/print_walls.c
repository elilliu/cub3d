/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_walls.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neleon <neleon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 14:51:57 by elilliu           #+#    #+#             */
/*   Updated: 2025/03/13 18:23:21 by neleon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d_bonus.h"

void	print_north(t_data *data, t_ray ray, float x, float y)
{
	int		color;
	int		i;
	float	step;
	t_draw	draw;
	t_point	tex;

	draw.start = y;
	draw.end = y + ray.size;
	if (draw.start < 0)
		draw.start = 0;
	if (draw.end >= HEIGHT)
		draw.end = HEIGHT;
	tex.x = (int)(ray.horizontal_x) % data->img_size;
	if (ray.angle > 0 && ray.angle < 180)
		tex.x = data->img_size - tex.x - 1;
	step = (float)data->img_size / ray.size;
	if (ray.size > HEIGHT)
		tex.y = ((ray.size - HEIGHT) / 2.0) * step;
	else
		tex.y = 0;
	i = draw.start;
	while (i < draw.end)
	{
		if (ray.type == CLOSE_D)
		{
			color = get_pixel_img(data->textures[T_DO], tex.x, (int)tex.y
					% data->textures[T_DO].h);
		}
		else
			color = get_pixel_img(data->textures[T_NO], tex.x, (int)tex.y
					% data->textures[T_NO].h);
		put_pixel_img(data->background, x, i, color);
		tex.y += step;
		i++;
	}
}

void	print_south(t_data *data, t_ray ray, float x, float y)
{
	int		color;
	int		i;
	float	step;
	t_draw	draw;
	t_point	tex;

	tex.x = (int)(ray.horizontal_x) % data->img_size;
	step = (float)data->img_size / ray.size;
	tex.y = 0;
	draw.start = y;
	draw.end = y + ray.size;
	if (ray.size > HEIGHT)
		tex.y = ((ray.size - HEIGHT) / 2.0) * step;
	if (draw.start < 0)
		draw.start = 0;
	if (draw.end >= HEIGHT)
		draw.end = HEIGHT;
	i = draw.start;
	while (i < draw.end)
	{
		if (ray.type == CLOSE_D)
			color = get_pixel_img(data->textures[T_DO], tex.x, (int)tex.y
					% data->textures[T_DO].h);
		else
			color = get_pixel_img(data->textures[T_SO], tex.x, (int)tex.y
					% data->img_size);
		put_pixel_img(data->background, x, i, color);
		tex.y += step;
		i++;
	}
}

void	print_west(t_data *data, t_ray ray, float x, float y)
{
	int		color;
	int		i;
	float	step;
	t_draw	draw;
	t_point	tex;

	tex.x = (int)(ray.vertical_y) % data->img_size;
	if (ray.angle > 90 && ray.angle < 270)
		tex.x = data->img_size - tex.x - 1;
	step = (float)data->img_size / ray.size;
	tex.y = 0;
	draw.start = y;
	draw.end = y + ray.size;
	if (ray.size > HEIGHT)
		tex.y = ((ray.size - HEIGHT) / 2.0) * step;
	if (draw.start < 0)
		draw.start = 0;
	if (draw.end >= HEIGHT)
		draw.end = HEIGHT;
	i = draw.start;
	while (i < draw.end)
	{
		if (ray.type == CLOSE_D)
			color = get_pixel_img(data->textures[T_DO], tex.x, (int)tex.y
					% data->textures[T_DO].h);
		else
			color = get_pixel_img(data->textures[T_WE], tex.x, (int)tex.y
					% data->img_size);
		put_pixel_img(data->background, x, i, color);
		tex.y += step;
		i++;
	}
}

void	print_east(t_data *data, t_ray ray, float x, float y)
{
	int		color;
	int		i;
	float	step;
	t_draw	draw;
	t_point	tex;

	tex.x = (int)(ray.vertical_y) % data->img_size;
	if (ray.angle > 90 && ray.angle < 270)
		tex.x = data->img_size - tex.x - 1;
	step = (float)data->img_size / ray.size;
	tex.y = 0;
	draw.start = y;
	draw.end = y + ray.size;
	if (ray.size > HEIGHT)
		tex.y = ((ray.size - HEIGHT) / 2.0) * step;
	if (draw.start < 0)
		draw.start = 0;
	if (draw.end >= HEIGHT)
		draw.end = HEIGHT;
	i = draw.start;
	while (i < draw.end)
	{
		if (ray.type == CLOSE_D)
			color = get_pixel_img(data->textures[T_DO], tex.x, (int)tex.y
					% data->textures[T_DO].h);
		else
			color = get_pixel_img(data->textures[T_EA], tex.x, (int)tex.y
					% data->img_size);
		put_pixel_img(data->background, x, i, color);
		tex.y += step;
		i++;
	}
}
