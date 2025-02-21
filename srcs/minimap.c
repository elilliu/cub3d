/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elilliu <elilliu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 12:06:55 by elilliu           #+#    #+#             */
/*   Updated: 2025/02/21 19:59:12 by elilliu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

// void	add_player(t_data *data)
// {

// }

void	minimap(t_data *data)
{
	double	x;
	double	y;
	int		color;

	x = WIDTH - 32 - 256;
	y = HEIGHT - 32 - 256;
	put_square(data, x, y, 0x0, 256);
	data->arrow.img_ptr = mlx_xpm_file_to_image(data->mlx_ptr, "textures/arrow.xpm",
		&data->arrow.w, &data->arrow.h);
	if (!data->arrow.img_ptr)
		return ;
	printf("je suis la\n");
	color = get_pixel_img(data->arrow, 0, 0);
	printf("color: %d\n", color);
	put_img_to_img(data->background, data->arrow, x + 126 - 16, y + 126 - 16);
}
