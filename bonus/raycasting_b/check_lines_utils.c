/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_lines_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neleon <neleon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 21:01:04 by nelbi             #+#    #+#             */
/*   Updated: 2025/03/17 14:39:43 by neleon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d_bonus.h"

int	map_value_at(t_data *data, double x, double y)
{
	int	map_x;
	int	map_y;

	map_x = (int)x / data->img_size;
	map_y = (int)y / data->img_size;
	if (map_x < 0
		|| map_y < 0
		|| map_y >= data->map.rows
		|| !data->map.tab[map_y]
		|| map_x >= (int)ft_strlen(data->map.tab[map_y]))
		return (' ');
	return (data->map.tab[map_y][map_x]);
}

void	find_door(t_data *data, t_ray *ray, double x, double y)
{
	if (map_value_at(data, x, y) == CLOSE_D)
		ray->type = CLOSE_D;
	else
		ray->type = WALL;
}
