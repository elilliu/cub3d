/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elilliu <elilliu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 12:06:55 by elilliu           #+#    #+#             */
/*   Updated: 2025/03/05 17:10:18 by elilliu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d_bonus.h"

void	rotate_and_put_img_to_img(t_img dst, t_img src, double angle, int x, int y)
{
	int	i;
	int	j;
	float	new_i;
	float	new_j;

	j = 0;
	// printf("player_angle: %f\n", angle);
	// printf("trying to draw here: %d %d\n", x, y);
	while (j < src.w)
	{
		i = 0;
		while (i < src.h)
		{
			new_i = (cos(deg_to_rad(angle)) * (j - src.w / 2) - sin(deg_to_rad(angle)) * (i - src.h / 2));
			new_j = (sin(deg_to_rad(angle)) * (j - src.w / 2) - cos(deg_to_rad(angle)) * (i - src.h / 2));
			// printf("new_j: %f | new_i: %f\n", new_j, new_i);
			put_pixel_img(dst, x + new_j, y + new_i, get_pixel_img(src, j, i));
			i++;
		}
		j++;
	}
}

void	add_arrow(t_data *data)
{
	data->arrow.img_ptr = mlx_xpm_file_to_image(data->mlx_ptr, "textures/arrow.xpm",
		&data->arrow.w, &data->arrow.h);
	if (!data->arrow.img_ptr)
		return ;
	data->arrow.addr = mlx_get_data_addr(data->arrow.img_ptr, &data->arrow.bpp,
		&data->arrow.line_len, &data->arrow.endian);
	// put_img_to_img(data->minimap, data->arrow, MINIMAP_SIZE / 2 - 8, MINIMAP_SIZE / 2 - 8);
	rotate_and_put_img_to_img(data->minimap, data->arrow,
		data->player.angle, MINIMAP_SIZE / 2 - 8, MINIMAP_SIZE / 2 - 8);
}

void	add_lines(t_data *data)
{
	float	x;
	float	y;
	int		line;
	int		column;

	y = 32 - ((data->player.y - (int)data->player.y / IMG_SIZE * IMG_SIZE) / IMG_SIZE * 32);
	line = (int)data->player.y / IMG_SIZE - 3;
	while (y < MINIMAP_SIZE && line < data->map.rows && line <= (int)data->player.y / IMG_SIZE + 4)
	{
		x = 32 - ((data->player.x - (int)data->player.x / IMG_SIZE * IMG_SIZE) / IMG_SIZE * 32);
		column = (int)data->player.x / IMG_SIZE - 3;
		while (x < MINIMAP_SIZE && column < data->map.columns && column <= (int)data->player.x / IMG_SIZE + 4)
		{
			if (line >= 0 && column >= 0 && data->map.tab[line][column] == WALL)
				put_square(data->minimap, x, y, 0xfffaf0, 32);
			column++;
			x += 32;
		}
		line++;
		y += 32;
	}
}

void	minimap(t_data *data)
{
	float	x;
	float	y;

	data->minimap.img_ptr = mlx_new_image(data->mlx_ptr, MINIMAP_SIZE, MINIMAP_SIZE);
	data->minimap.w = MINIMAP_SIZE;
	data->minimap.h = MINIMAP_SIZE;
	data->minimap.addr = mlx_get_data_addr(data->minimap.img_ptr,
		&data->minimap.bpp, &data->minimap.line_len, &data->minimap.endian);
	put_square(data->minimap, 0, 0, 0x2f4f4f, MINIMAP_SIZE);
	add_lines(data);
	add_arrow(data);
	// put_square(data->minimap, MINIMAP_SIZE / 2 - 4, MINIMAP_SIZE / 2 - 4, 0xcd5c5c, 8);
	x = WIDTH - 32 - MINIMAP_SIZE;
	y = HEIGHT - 32 - MINIMAP_SIZE;
	put_img_to_img(data->background, data->minimap, x, y);
}
