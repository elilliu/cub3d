/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_walls.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elilliu@student.42.fr <elilliu>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 15:33:14 by elilliu@stu       #+#    #+#             */
/*   Updated: 2025/02/15 23:48:09 by elilliu@stu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	put_horizontal_wall(t_data *data, t_ray ray)
{
	float	size;
	float	x;
	float	y;

	size = (float)HEIGHT / ray.horizontal_distance * 64.0;
	if (size > HEIGHT)
		size = (float)HEIGHT;
	x = ray.nb;
	y = ((float)HEIGHT / 2) - (size / 2);
	if (ray.angle > 0 && ray.angle < 180)
		print_line(data, x, y, size, 0x8b);
	else
		print_line(data, x, y, size, 0x6495ed);
}

void	put_vertical_wall(t_data *data, t_ray ray)
{
	float	size;
	float	x;
	float	y;

	size = (float)HEIGHT / ray.vertical_distance * 64.0;
	if (size > HEIGHT)
		size = (float)HEIGHT;
	x = ray.nb;
	y = ((float)HEIGHT / 2) - (size / 2);
	if (ray.angle > 270 || ray.angle < 90)
		print_line(data, x, y, size, 0x9b30ff);
	else
		print_line(data, x, y, size, 0x5d478b);
}
