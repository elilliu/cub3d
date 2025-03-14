/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bineleon <neleon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 16:50:05 by elilliu           #+#    #+#             */
/*   Updated: 2025/03/14 19:48:26 by bineleon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

t_bool  is_in_map(t_data *data, double x, double y)
{
  if ((int)y / data->img_size > 0
		&& (int)y / data->img_size < data->map.rows
		&& (int)x / data->img_size > 0
		&& (int)x / data->img_size < data->map.columns
		&& data->map.tab[(int)y / data->img_size][(int)x / data->img_size] != WALL)
      return (true);
  return (false);
}

void   sub_h(t_data *data, t_ray *ray)
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
	return (sqrt(pow(ray->horizontal_x - data->player.x, 2)
			+ pow(ray->horizontal_y - data->player.y, 2)));
}

void  sub_v(t_data *data, t_ray *ray)
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
	return (sqrt(pow(ray->vertical_x - data->player.x, 2) + pow(ray->vertical_y
				- data->player.y, 2)));
}

void  sub_add_rays(t_data *data, t_ray *ray, float step)
{
  int i;

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
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
		data->background.img_ptr, 0, 0);
	mlx_destroy_image(data->mlx_ptr, data->background.img_ptr);
}

// double	check_horizontal_lines(t_data *data, t_ray *ray)
// {
// 	if (ray->angle > 0 && ray->angle < 180)
// 		ray->horizontal_y = ((int)data->player.y / data->img_size)
// 			* data->img_size + data->img_size;
// 	else if (ray->angle > 180 && ray->angle < 360)
// 		ray->horizontal_y = ((int)data->player.y / data->img_size)
// 			* data->img_size - 0.0001;
// 	else
// 		return (0);
// 	if (tan(deg_to_rad(ray->angle)) == 0)
// 		ray->horizontal_x = data->player.x;
// 	else
// 		ray->horizontal_x = data->player.x + (ray->horizontal_y
// 				- data->player.y) / tan(deg_to_rad(ray->angle));
// 	while ((int)ray->horizontal_y / data->img_size > 0 && (int)ray->horizontal_y
// 		/ data->img_size < data->map.rows && (int)ray->horizontal_x
// 		/ data->img_size > 0 && (int)ray->horizontal_x
// 		/ data->img_size < data->map.columns
// 		&& data->map.tab[(int)ray->horizontal_y
// 		/ data->img_size][(int)ray->horizontal_x / data->img_size] != WALL)
// 	{
// 		if (ray->angle > 0 && ray->angle < 180)
// 			ray->horizontal_y += data->img_size;
// 		else if (ray->angle > 180 && ray->angle < 360)
// 			ray->horizontal_y -= data->img_size;
// 		else
// 			break ;
// 		if (tan(deg_to_rad(ray->angle)) != 0)
// 			ray->horizontal_x = data->player.x + (ray->horizontal_y
// 					- data->player.y) / tan(deg_to_rad(ray->angle));
// 	}
// 	return (sqrt(pow(ray->horizontal_x - data->player.x, 2)
// 			+ pow(ray->horizontal_y - data->player.y, 2)));
// }

// double	check_vertical_lines(t_data *data, t_ray *ray)
// {
// 	if (ray->angle > 270 || ray->angle < 90)
// 		ray->vertical_x = ((int)data->player.x / data->img_size)
// 			* data->img_size + data->img_size;
// 	else if (ray->angle > 90 && ray->angle < 270)
// 		ray->vertical_x = ((int)data->player.x / data->img_size)
// 			* data->img_size - 0.0001;
// 	else
// 		return (0);
// 	if (tan(deg_to_rad(ray->angle)) == 0)
// 		ray->vertical_y = data->player.y;
// 	else
// 		ray->vertical_y = data->player.y + (ray->vertical_x - data->player.x)
// 			* tan(deg_to_rad(ray->angle));
// 	while ((int)ray->vertical_y / data->img_size > 0 && (int)ray->vertical_y
// 		/ data->img_size < data->map.rows && (int)ray->vertical_x
// 		/ data->img_size > 0 && (int)ray->vertical_x
// 		/ data->img_size < data->map.columns
// 		&& data->map.tab[(int)ray->vertical_y
// 		/ data->img_size][(int)ray->vertical_x / data->img_size] != WALL)
// 	{
// 		if (ray->angle > 270 || ray->angle < 90)
// 			ray->vertical_x += data->img_size;
// 		else if (ray->angle > 90 && ray->angle < 270)
// 			ray->vertical_x -= data->img_size;
// 		if (tan(deg_to_rad(ray->angle)) != 0)
// 			ray->vertical_y = data->player.y + (ray->vertical_x
// 					- data->player.x) * tan(deg_to_rad(ray->angle));
// 	}
// 	return (sqrt(pow(ray->vertical_x - data->player.x, 2) + pow(ray->vertical_y
// 				- data->player.y, 2)));
// }

// void	add_rays(t_data *data)
// {
// 	t_ray	ray;
// 	float	step;
// 	float	fov;
// 	float	width;
// 	int		i;

// 	fov = (float)FOV;
// 	ray.angle = data->player.angle - fov / 2;
// 	width = (float)WIDTH;
// 	step = fov / width;
// 	if (ray.angle < 0)
// 		ray.angle += 360;
// 	i = 0;
// 	while (i < WIDTH)
// 	{
// 		ray.nb = i;
// 		ray.horizontal_distance = check_horizontal_lines(data, &ray);
// 		ray.vertical_distance = check_vertical_lines(data, &ray);
// 		if (ray.horizontal_distance < ray.vertical_distance)
// 			put_horizontal_wall(data, ray);
// 		else
// 			put_vertical_wall(data, ray);
// 		ray.angle += step;
// 		if (ray.angle >= 360)
// 			ray.angle -= 360.0;
// 		i++;
// 	}
// }

// void	add_player(t_data *data)
// {
// 	float	x;
// 	float	y;

// 	x = data->player.x - 4;
// 	while (x != data->player.x + 4)
// 	{
// 		y = data->player.y - 4;
// 		while (y != data->player.y + 4)
// 		{
// 			put_pixel_img(data->background, x, y, 0x0);
// 			y++;
// 		}
// 		x++;
// 	}
// }

// void	fill_window(t_data *data)
// {
// 	data->background.img_ptr = mlx_new_image(data->mlx_ptr, WIDTH, HEIGHT);
// 	data->background.w = WIDTH;
// 	data->background.h = HEIGHT;
// 	data->background.addr = mlx_get_data_addr(data->background.img_ptr,
// 			&data->background.bpp, &data->background.line_len,
// 			&data->background.endian);
// 	data->test = 1;
// 	add_ceiling(data);
// 	add_floor(data);
// 	add_rays(data);
// 	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
// 		data->background.img_ptr, 0, 0);
// 	mlx_destroy_image(data->mlx_ptr, data->background.img_ptr);
// }
