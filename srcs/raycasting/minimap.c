/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neleon <neleon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 12:06:55 by elilliu           #+#    #+#             */
/*   Updated: 2025/02/28 16:19:39 by neleon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

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
			if (line >= 0 && column >= 0 && data->map.tab[line][column] == '1')
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
	put_square(data->minimap, 0, 0, 0x0, MINIMAP_SIZE);
	data->arrow.img_ptr = mlx_xpm_file_to_image(data->mlx_ptr, "textures/arrow.xpm",
		&data->arrow.w, &data->arrow.h);
	if (!data->arrow.img_ptr)
		return ;
	data->arrow.addr = mlx_get_data_addr(data->arrow.img_ptr, &data->arrow.bpp,
		&data->arrow.line_len, &data->arrow.endian);
	add_lines(data);
	put_img_to_img(data->minimap, data->arrow, MINIMAP_SIZE / 2 - 8, MINIMAP_SIZE / 2 - 8);
	x = WIDTH - 32 - MINIMAP_SIZE;
	y = HEIGHT - 32 - MINIMAP_SIZE;
	put_img_to_img(data->background, data->minimap, x, y);
}
