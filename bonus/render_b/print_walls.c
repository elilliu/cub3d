/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_walls.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelbi <neleon@student.42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 14:51:57 by elilliu           #+#    #+#             */
/*   Updated: 2025/03/10 10:44:36 by nelbi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d_bonus.h"

void	free_texture(t_data *data, int nb)
{
	int	i;

	i = 0;
	while (i <= nb)
	{
        if (data->textures[nb].img_ptr) // changer data->textures[nb] par data->textures[i] ?
		    mlx_destroy_image(data->mlx_ptr, data->textures[nb].img_ptr);
		i++;
	}
}

void	init_textures(t_data *data)
{
	data->textures[T_NO].img_ptr = mlx_xpm_file_to_image(data->mlx_ptr, data->t_paths.t_no, &data->textures[T_NO].w, &data->textures[T_NO].h);
	if (!data->textures[T_NO].img_ptr)
		return (free_texture(data, T_NO), print_clean(data, "Failed texture allocation"));
	data->textures[T_NO].addr = mlx_get_data_addr(data->textures[T_NO].img_ptr, &data->textures[T_NO].bpp, &data->textures[T_NO].line_len, &data->textures[T_NO].endian);

	data->textures[T_SO].img_ptr = mlx_xpm_file_to_image(data->mlx_ptr,	data->t_paths.t_so, &data->textures[T_SO].w, &data->textures[T_SO].h);
	if (!data->textures[T_SO].img_ptr)
		return (free_texture(data, T_SO));
	data->textures[T_SO].addr = mlx_get_data_addr(data->textures[T_SO].img_ptr,	&data->textures[T_SO].bpp, &data->textures[T_SO].line_len, &data->textures[T_SO].endian);

	data->textures[T_EA].img_ptr = mlx_xpm_file_to_image(data->mlx_ptr, data->t_paths.t_ea, &data->textures[T_EA].w, &data->textures[T_EA].h);
	if (!data->textures[T_EA].img_ptr)
		return (free_texture(data, T_EA));
	data->textures[T_EA].addr = mlx_get_data_addr(data->textures[T_EA].img_ptr, &data->textures[T_EA].bpp, &data->textures[T_EA].line_len, &data->textures[T_EA].endian);

	data->textures[T_WE].img_ptr = mlx_xpm_file_to_image(data->mlx_ptr, data->t_paths.t_we, &data->textures[T_WE].w, &data->textures[T_WE].h);
	if (!data->textures[T_WE].img_ptr)
		return (free_texture(data, T_WE));
	data->textures[T_WE].addr = mlx_get_data_addr(data->textures[T_WE].img_ptr, &data->textures[T_WE].bpp, &data->textures[T_WE].line_len, &data->textures[T_WE].endian);
	data->textures[T_DO].img_ptr = mlx_xpm_file_to_image(data->mlx_ptr, data->t_paths.t_do, &data->textures[T_DO].w, &data->textures[T_DO].h);
	if (!data->textures[T_DO].img_ptr)
	{
		printf("\n\n\ntextures path : %s\n", data->t_paths.t_do);
		return (free_texture(data, T_DO), print_clean(data, "Failed texture allocation"));
	}
	data->textures[T_DO].addr = mlx_get_data_addr(data->textures[T_DO].img_ptr, &data->textures[T_DO].bpp, &data->textures[T_DO].line_len, &data->textures[T_DO].endian);

}

void	print_door(t_data *data, t_ray ray, float x, float y)
{
	int		color;
	int		i;
	float	step;
	t_draw	draw;
	t_point	tex;

	tex.x = ((int)ray.horizontal_x % data->img_size);
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
		color = get_pixel_img(data->textures[T_DO], tex.x, (int)tex.y % data->textures[T_DO].h);
		put_pixel_img(data->background, x, i, color);
		tex.y += step;
		i++;
	}
}


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
			color = get_pixel_img(data->textures[T_DO], tex.x, (int)tex.y
			% data->textures[T_DO].h);
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
