/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neleon <neleon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 20:03:05 by elilliu@stu       #+#    #+#             */
/*   Updated: 2025/03/13 16:03:39 by neleon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d_bonus.h"

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
