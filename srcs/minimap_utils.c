/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elilliu@student.42.fr <elilliu>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 20:03:05 by elilliu@stu       #+#    #+#             */
/*   Updated: 2025/02/24 23:21:25 by elilliu@stu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	put_square(t_img img, int x, int y, int color, int size)
{
	int	i;
	int	j;

	j = 0;
	while (j < size && y + j < img.h)
	{
		i = 0;
		while (i < size && x + i < img.w)
		{
			put_pixel_img(img, x + i, y + j, color);
			i++;
		}
		j++;
	}
}
