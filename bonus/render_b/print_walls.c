/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_walls.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neleon <neleon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 14:51:57 by elilliu           #+#    #+#             */
/*   Updated: 2025/03/17 19:58:50 by neleon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d_bonus.h"

void	print_wall(t_ray ray, t_draw draw, t_point tex, int tex_type)
{
	int		i;
	int		color;
	t_data	*data;

	data = get_data();
	i = draw.start;
	while (i < draw.end)
	{
		if (tex_type == T_SO)
			color = get_good_mike_color(data, tex.x, tex.y);
		else if (ray.type == CLOSE_D)
			color = get_good_door_color(data, tex.x, tex.y);
		else
			color = get_pixel_img(data->textures[tex_type], tex.x, (int)tex.y
					% data->textures[tex_type].h);
		put_pixel_img(data->background, draw.x, i, color);
		tex.y += draw.step;
		i++;
	}
}

void	print_north(t_data *data, t_ray ray, float x, float y)
{
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
	draw.step = (float)data->img_size / ray.size;
	if (ray.size > HEIGHT)
		tex.y = ((ray.size - HEIGHT) / 2.0) * draw.step;
	else
		tex.y = 0;
	draw.x = x;
	print_wall(ray, draw, tex, T_NO);
}

void	print_south(t_data *data, t_ray ray, float x, float y)
{
	t_draw	draw;
	t_point	tex;

	tex.x = (int)(ray.horizontal_x) % data->img_size;
	draw.step = (float)data->img_size / ray.size;
	tex.y = 0;
	draw.start = y;
	draw.end = y + ray.size;
	if (ray.size > HEIGHT)
		tex.y = ((ray.size - HEIGHT) / 2.0) * draw.step;
	if (draw.start < 0)
		draw.start = 0;
	if (draw.end >= HEIGHT)
		draw.end = HEIGHT;
	draw.x = x;
	print_wall(ray, draw, tex, T_SO);
}

void	print_west(t_data *data, t_ray ray, float x, float y)
{
	t_draw	draw;
	t_point	tex;

	tex.x = (int)(ray.vertical_y) % data->img_size;
	if (ray.angle > 90 && ray.angle < 270)
		tex.x = data->img_size - tex.x - 1;
	draw.step = (float)data->img_size / ray.size;
	tex.y = 0;
	draw.start = y;
	draw.end = y + ray.size;
	if (ray.size > HEIGHT)
		tex.y = ((ray.size - HEIGHT) / 2.0) * draw.step;
	if (draw.start < 0)
		draw.start = 0;
	if (draw.end >= HEIGHT)
		draw.end = HEIGHT;
	draw.x = x;
	print_wall(ray, draw, tex, T_WE);
}

void	print_east(t_data *data, t_ray ray, float x, float y)
{
	t_draw	draw;
	t_point	tex;

	tex.x = (int)(ray.vertical_y) % data->img_size;
	if (ray.angle > 90 && ray.angle < 270)
		tex.x = data->img_size - tex.x - 1;
	draw.step = (float)data->img_size / ray.size;
	tex.y = 0;
	draw.start = y;
	draw.end = y + ray.size;
	if (ray.size > HEIGHT)
		tex.y = ((ray.size - HEIGHT) / 2.0) * draw.step;
	if (draw.start < 0)
		draw.start = 0;
	if (draw.end >= HEIGHT)
		draw.end = HEIGHT;
	draw.x = x;
	print_wall(ray, draw, tex, T_EA);
}
