/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_lines.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neleon <neleon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 20:57:10 by nelbi             #+#    #+#             */
/*   Updated: 2025/03/17 13:39:12 by neleon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d_bonus.h"

static t_bool	is_in_map(t_data *data, double x, double y)
{
	if ((int)y / data->img_size > 0 && (int)y / data->img_size < data->map.rows
		&& (int)x / data->img_size > 0 && (int)x
		/ data->img_size < data->map.columns
		&& !is_wall_or_door(map_value_at(data, x, y)))
		return (true);
	return (false);
}

static void	sub_h(t_data *data, t_ray *ray)
{
	while (is_in_map(data, ray->horizontal_x, ray->horizontal_y))
	{
		if (ray->angle > 0 && ray->angle < 180)
			ray->horizontal_y += data->img_size;
		else if (ray->angle > 180 && ray->angle < 360)
			ray->horizontal_y -= data->img_size;
		else
			return ;
		if (tan(deg_to_rad(ray->angle)) != 0)
			ray->horizontal_x = data->player.x + (ray->horizontal_y
					- data->player.y) / tan(deg_to_rad(ray->angle));
	}
}

double	check_horizontal_lines(t_data *data, t_ray *ray)
{
	if (ray->angle > 0 && ray->angle < 180)
		ray->horizontal_y = ((int)data->player.y / data->img_size)
			* data->img_size + data->img_size;
	else if (ray->angle > 180 && ray->angle < 360)
		ray->horizontal_y = ((int)data->player.y / data->img_size)
			* data->img_size - 0.0001;
	else
		return (0);
	if (tan(deg_to_rad(ray->angle)) == 0)
		ray->horizontal_x = data->player.x;
	else
		ray->horizontal_x = data->player.x + (ray->horizontal_y
				- data->player.y) / tan(deg_to_rad(ray->angle));
	sub_h(data, ray);
	find_door(data, ray, ray->horizontal_x, ray->horizontal_y);
	return (sqrt(pow(ray->horizontal_x - data->player.x, 2)
			+ pow(ray->horizontal_y - data->player.y, 2)));
}

static void	sub_v(t_data *data, t_ray *ray)
{
	while (is_in_map(data, ray->vertical_x, ray->vertical_y))
	{
		if (ray->angle > 270 || ray->angle < 90)
			ray->vertical_x += data->img_size;
		else if (ray->angle > 90 && ray->angle < 270)
			ray->vertical_x -= data->img_size;
		if (tan(deg_to_rad(ray->angle)) != 0)
			ray->vertical_y = data->player.y + (ray->vertical_x
					- data->player.x) * tan(deg_to_rad(ray->angle));
	}
}

double	check_vertical_lines(t_data *data, t_ray *ray)
{
	if (ray->angle > 270 || ray->angle < 90)
		ray->vertical_x = ((int)data->player.x / data->img_size)
			* data->img_size + data->img_size;
	else if (ray->angle > 90 && ray->angle < 270)
		ray->vertical_x = ((int)data->player.x / data->img_size)
			* data->img_size - 0.0001;
	else
		return (0);
	if (tan(deg_to_rad(ray->angle)) == 0)
		ray->vertical_y = data->player.y;
	else
		ray->vertical_y = data->player.y + (ray->vertical_x - data->player.x)
			* tan(deg_to_rad(ray->angle));
	sub_v(data, ray);
	find_door(data, ray, ray->vertical_x, ray->vertical_y);
	return (sqrt(pow(ray->vertical_x - data->player.x, 2) + pow(ray->vertical_y
				- data->player.y, 2)));
}
