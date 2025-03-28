/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_walls.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elilliu <elilliu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 15:33:14 by elilliu@stu       #+#    #+#             */
/*   Updated: 2025/03/18 14:45:05 by elilliu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d_bonus.h"

void	put_horizontal_wall(t_data *data, t_ray *ray)
{
	float	x;
	float	y;

	ray->horizontal_distance *= cos(deg_to_rad(ray->angle)
			- deg_to_rad(data->player.angle));
	if (ray->horizontal_distance < 0)
		return ;
	ray->size = (float)HEIGHT / ray->horizontal_distance * (float)data->img_size
		* 1.5;
	x = ray->nb;
	y = ((float)HEIGHT / 2) - (ray->size / 2);
	find_door(data, ray, ray->horizontal_x, ray->horizontal_y);
	if (ray->angle > 0 && ray->angle < 180)
		print_north(data, *ray, x, y);
	else
		print_south(data, *ray, x, y);
}

void	put_vertical_wall(t_data *data, t_ray *ray)
{
	float	x;
	float	y;

	ray->vertical_distance *= cos(deg_to_rad(ray->angle)
			- deg_to_rad(data->player.angle));
	if (ray->vertical_distance < 0)
		return ;
	ray->size = (float)HEIGHT / ray->vertical_distance * (float)data->img_size
		* 1.5;
	x = ray->nb;
	y = ((float)HEIGHT / 2) - (ray->size / 2);
	find_door(data, ray, ray->vertical_x, ray->vertical_y);
	if (ray->angle > 270 || ray->angle < 90)
		print_west(data, *ray, x, y);
	else
		print_east(data, *ray, x, y);
}
