/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_walls.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bineleon <neleon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 15:33:14 by elilliu@stu       #+#    #+#             */
/*   Updated: 2025/02/20 15:09:10 by bineleon         ###   ########.fr       */
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
	ray.size = (float)HEIGHT / ray.horizontal_distance * (float)data->img_size * 1.5;
	// if (ray.size > HEIGHT)
	// 	ray.size = (float)HEIGHT;
	x = ray.nb;
	y = ((float)HEIGHT / 2) - (ray.size / 2);
	if (ray.angle > 0 && ray.angle < 180)
		print_north(data, ray, x, y);
	else
    print_south(data, ray, x, y);
		// print_line(data, x, y, ray.size, 0x6495ed);
}

void	put_vertical_wall(t_data *data, t_ray ray)
{
	// float	size;
	float	x;
	float	y;

	ray.vertical_distance *= cos(deg_to_rad(ray.angle) - deg_to_rad(data->player.angle));
	if (ray.vertical_distance < 0)
		return ;
	ray.size = (float)HEIGHT / ray.vertical_distance * (float)data->img_size * 1.5;
	// if (ray.size > HEIGHT)
	// 	ray.size = (float)HEIGHT;
	x = ray.nb;
	y = ((float)HEIGHT / 2) - (ray.size / 2);
	if (ray.angle > 270 || ray.angle < 90)
  {
    print_east(data, ray, x, y);
  }
	else
  {
		print_west(data, ray, x, y);
    // print_line(data, x, y, ray.size, 0x6495ed);
  }
}
