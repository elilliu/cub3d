/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elilliu <elilliu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 14:23:29 by elilliu           #+#    #+#             */
/*   Updated: 2025/01/29 17:32:36 by elilliu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	put_player(t_data *data, int x, int y, int size)
{
	int	i;
	int	j;

	j = 0;
	while (j < size)
	{
		i = 0;
		while (i < size)
		{
			if (i >= data->player.x && i <= data->player.x + 8 && j >= data->player.y && j <= data->player.y + 8)
				mlx_pixel_put(data->mlx_ptr, data->win_ptr, x + i, y + j, 0xcd5c5c);
			else
				mlx_pixel_put(data->mlx_ptr, data->win_ptr, x + i, y + j, 0xf8f8ff);
			i++;
		}
		j++;
	}
}

void	put_grey_square(t_data *data, int x, int y, int size)
{
	int	i;
	int	j;

	j = 0;
	while (j < size)
	{
		i = 0;
		while (i < size)
		{
			mlx_pixel_put(data->mlx_ptr, data->win_ptr, x + i, y + j, 0x2f4f4f);
			i++;
		}
		j++;
	}
}

void	put_white_square(t_data *data, int x, int y, int size)
{
	int	i;
	int	j;

	j = 0;
	while (j < size)
	{
		i = 0;
		while (i < size)
		{
			mlx_pixel_put(data->mlx_ptr, data->win_ptr, x + i, y + j, 0xf8f8ff);
			i++;
		}
		j++;
	}
}

int	fill_window(t_data *data)
{
	int	x;
	int	y;
	int	row;
	int	i;

	x = 0;
	y = 0;
	row = 0;
	i = 0;
	while (data->map.tab[row])
	{
		i = 0;
		x = 0;
		while (data->map.tab[row][i])
		{
			if (data->map.tab[row][i] == 'N')
				put_player(data, x, y, 63);
			if (data->map.tab[row][i] == '1')
				put_grey_square(data, x, y, 63);
			else if (data->map.tab[row][i] == '0')
				put_white_square(data, x, y, 63);
			x += 64;
			i++;
		}
		y += 64;
		row++;
	}
	return (1);
}
