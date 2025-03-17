/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bineleon <neleon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 20:03:05 by elilliu@stu       #+#    #+#             */
/*   Updated: 2025/03/14 21:41:31 by bineleon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d_bonus.h"

void	put_square(t_img img, t_point p, int color, int size)
{
	int	i;
	int	j;

	j = 0;
	while (j < size && p.y + j < img.h)
	{
		i = 0;
		while (i < size && p.x + i < img.w)
		{
			put_pixel_img(img, p.x + i, p.y + j, color);
			i++;
		}
		j++;
	}
}
