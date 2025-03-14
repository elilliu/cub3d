/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_img_to_img.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelbi <neleon@student.42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 18:43:43 by elilliu           #+#    #+#             */
/*   Updated: 2025/03/14 20:42:57 by nelbi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d_bonus.h"

unsigned int	get_pixel_img(t_img img, float x, float y)
{
	return (*(unsigned int *)(img.addr + ((int)y * img.line_len)
		+ ((int)x * img.bpp / 8)));
}

void	put_pixel_img(t_img img, int x, int y, int color)
{
	char	*dst;

	if (color == (int)0xFF000000)
		return ;
	dst = img.addr + (y * img.line_len + x * (img.bpp / 8));
	*(unsigned int *)dst = color;
}

void	put_img_to_img(t_img dst, t_img src, int x, int y)
{
	int	i;
	int	j;

	j = 0;
	while (j < src.w)
	{
		i = 0;
		while (i < src.h)
		{
			put_pixel_img(dst, x + j, y + i, get_pixel_img(src, j, i));
			i++;
		}
		j++;
	}
}

int	rgb_to_int(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}
