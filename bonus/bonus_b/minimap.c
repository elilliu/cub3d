/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neleon <neleon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 12:06:55 by elilliu           #+#    #+#             */
/*   Updated: 2025/03/17 14:42:59 by neleon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d_bonus.h"

void	rot_put_img_to_img(t_img dst, t_img src, double angle, t_point p)
{
	int		i;
	int		j;
	int		src_x;
	int		src_y;
	double	rad;

	rad = deg_to_rad(angle + 90);
	j = 0;
	while (j < src.w)
	{
		i = 0;
		while (i < src.h)
		{
			src_x = (int)(cos(rad) * (j - src.w / 2) - sin(rad) * (i - src.w
						/ 2));
			src_y = (int)(sin(rad) * (j - src.w / 2) + cos(rad) * (i - src.h
						/ 2));
			put_pixel_img(dst, p.min_x + src_x, p.min_y + src_y,
				get_pixel_img(src, j, i));
			i++;
		}
		j++;
	}
}

void	add_arrow(t_data *data)
{
	t_point	p;

	p.min_x = MINIMAP_SIZE / 2;
	p.min_y = MINIMAP_SIZE / 2;
	data->arrow.img_ptr = mlx_xpm_file_to_image(data->mlx_ptr,
			"textures/arrow.xpm", &data->arrow.w, &data->arrow.h);
	if (!data->arrow.img_ptr)
		return ;
	data->arrow.addr = mlx_get_data_addr(data->arrow.img_ptr, &data->arrow.bpp,
			&data->arrow.line_len, &data->arrow.endian);
	rot_put_img_to_img(data->minimap, data->arrow, data->player.angle, p);
	mlx_destroy_image(data->mlx_ptr, data->arrow.img_ptr);
}

static void	sub_add_line(t_data *data, t_point *p, int line, int column)
{
	while (p->x < MINIMAP_SIZE && column <= (int)data->player.x / IMG_SIZE + 4)
	{
		if (column < 0 || column >= data->map.columns
			|| column >= (int)ft_strlen(data->map.tab[line]))
		{
			column++;
			p->x += 32;
			continue ;
		}
		if (data->map.tab[line][column] == WALL)
			put_square(data->minimap, *p, 0xfffaf0, 32);
		else if (data->map.tab[line][column] == CLOSE_D)
			put_square(data->minimap, *p, 0xaec3b0, 32);
		else if (data->map.tab[line][column] == OPEN_D)
			put_square(data->minimap, *p, 0x598392, 32);
		column++;
		p->x += 32;
	}
}

void	add_lines(t_data *data)
{
	t_point	p;
	int		line;
	int		column;

	p.y = 32 - ((data->player.y - (int)data->player.y / IMG_SIZE * IMG_SIZE)
			/ IMG_SIZE * 32);
	line = (int)data->player.y / IMG_SIZE - 3;
	while (p.y < MINIMAP_SIZE && line < data->map.rows
		&& line <= (int)data->player.y / IMG_SIZE + 4)
	{
		if (line < 0 || !data->map.tab[line])
		{
			line++;
			p.y += 32;
			continue ;
		}
		p.x = 32 - ((data->player.x - (int)data->player.x / IMG_SIZE * IMG_SIZE)
				/ IMG_SIZE * 32);
		column = (int)data->player.x / IMG_SIZE - 3;
		sub_add_line(data, &p, line, column);
		line++;
		p.y += 32;
	}
}

void	minimap(t_data *data)
{
	t_point	p;
	float	x;
	float	y;

	p.x = 0;
	p.y = 0;
	data->minimap.img_ptr = mlx_new_image(data->mlx_ptr, MINIMAP_SIZE,
			MINIMAP_SIZE);
	data->minimap.w = MINIMAP_SIZE;
	data->minimap.h = MINIMAP_SIZE;
	data->minimap.addr = mlx_get_data_addr(data->minimap.img_ptr,
			&data->minimap.bpp, &data->minimap.line_len, &data->minimap.endian);
	put_square(data->minimap, p, 0x2f4f4f, MINIMAP_SIZE);
	add_lines(data);
	add_arrow(data);
	x = WIDTH - 32 - MINIMAP_SIZE;
	y = HEIGHT - 32 - MINIMAP_SIZE;
	put_img_to_img(data->background, data->minimap, x, y);
	mlx_destroy_image(data->mlx_ptr, data->minimap.img_ptr);
}
