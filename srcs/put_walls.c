/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_walls.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elilliu <elilliu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 15:33:14 by elilliu@stu       #+#    #+#             */
/*   Updated: 2025/02/19 17:18:42 by elilliu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	put_horizontal_wall(t_data *data, t_ray ray)
{
	float	x;
	float	y;

	// if (data->test)
	// {
	// 	printf("%f\n", data->player.angle - ray.angle);
	// 	printf("cos: %f\n", cos(data->player.angle - ray.angle));
	// 	data->test = 0;
	// }
	ray.horizontal_distance *= cos(deg_to_rad(ray.angle) - deg_to_rad(data->player.angle));
	if (ray.horizontal_distance < 0)
		return ;
	ray.size = (float)HEIGHT / ray.horizontal_distance * (float)data->img_size;
	if (ray.size > HEIGHT)
		ray.size = (float)HEIGHT;
	x = ray.nb;
	y = ((float)HEIGHT / 2) - (ray.size / 2);
	if (ray.angle > 0 && ray.angle < 180)
		print_north(data, ray, x, y);
	else
		print_line(data, x, y, ray.size, 0x6495ed);
}

void	put_vertical_wall(t_data *data, t_ray ray)
{
	float	size;
	float	x;
	float	y;

	ray.vertical_distance *= cos(deg_to_rad(ray.angle) - deg_to_rad(data->player.angle));
	if (ray.vertical_distance < 0)
		return ;
	size = (float)HEIGHT / ray.vertical_distance * (float)data->img_size;
	if (size > HEIGHT)
		size = (float)HEIGHT;
	x = ray.nb;
	y = ((float)HEIGHT / 2) - (size / 2);
	if (ray.angle > 270 || ray.angle < 90)
		print_line(data, x, y, size, 0x9b30ff);
	else
		print_line(data, x, y, size, 0x5d478b);
}
