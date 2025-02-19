/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_walls.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elilliu <elilliu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 14:51:57 by elilliu           #+#    #+#             */
/*   Updated: 2025/02/19 16:57:44 by elilliu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	free_texture(t_data *data, int nb)
{
	int	i;

	i = 0;
	while (i <= nb)
	{
		mlx_destroy_image(data->mlx_ptr, data->textures[nb].img_ptr);
		i++;
	}
}

void	init_textures(t_data *data)
{
	data->textures[T_NO].w = 0;
	data->textures[T_NO].h = 0;
	data->textures[T_NO].img_ptr = mlx_xpm_file_to_image(data->mlx_ptr,
		data->t_paths.t_no, &data->textures[T_NO].w, &data->textures[T_NO].h);
	if (!data->textures[T_NO].img_ptr)
		return (free_texture(data, T_NO));
	data->textures[T_NO].addr = mlx_get_data_addr(data->textures[T_NO].img_ptr, &data->textures[T_NO].bpp, &data->textures[T_NO].line_len, &data->textures[T_NO].endian);
	// data->textures[T_SO].img_ptr = mlx_xpm_file_to_image(data->mlx_ptr,
	// 	data->t_paths.t_so, &data->textures[T_SO].w, &data->textures[T_SO].h);
	// if (!data->textures[T_SO].img_ptr)
	// 	return (free_texture(data, T_SO));
	// data->textures[T_EA].img_ptr = mlx_xpm_file_to_image(data->mlx_ptr,
	// 	data->t_paths.t_ea, &data->textures[T_EA].w, &data->textures[T_EA].h);
	// if (!data->textures[T_EA].img_ptr)
	// 	return (free_texture(data, T_EA));
	// data->textures[T_WE].img_ptr = mlx_xpm_file_to_image(data->mlx_ptr,
	// 	data->t_paths.t_we, &data->textures[T_WE].w, &data->textures[T_WE].h);
	// if (!data->textures[T_WE].img_ptr)
	// 	return (free_texture(data, T_WE));
}

// void	init_buffer(t_data *data)
// {
// 	int	i;

// 	i = 0;
// 	while (i < 4)
// 	{
// 		data->tex_buff[i] = gc_mem(MALLOC, sizeof(int) * 64 * 64, NULL);

// 		i++;
// 	}
// }

void	print_north(t_data *data, t_ray ray, float x, float y)
{
	int		color;
	int		i;
	float	z;
	float	step;
	float	end;

	i = 0;
	step = ray.size / data->img_size;
	z = ((int)ray.horizontal_x / data->img_size) * data->img_size + data->img_size - ray.horizontal_x;
	while (i < data->img_size)
	{
		color = get_pixel_img(data->textures[T_NO], z, i);
		end = y + step;
		while (y < end)
		{
			put_pixel_img(data->background, x, y, color);
			y += 0.1;
		}
		i++;
	}
}
