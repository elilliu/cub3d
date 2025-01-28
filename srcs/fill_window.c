/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elilliu <elilliu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 14:23:29 by elilliu           #+#    #+#             */
/*   Updated: 2025/01/28 14:59:13 by elilliu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	fill_window(t_data *data)
{
	// int	x;
	// int	y;

	mlx_pixel_put(data->mlx_ptr, data->win_ptr, 32, 32, 0xf0f8ff);
}
