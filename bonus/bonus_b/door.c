/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bineleon <neleon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 14:05:51 by bineleon          #+#    #+#             */
/*   Updated: 2025/03/05 15:57:34 by bineleon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d_bonus.h"

void  assign_points(t_data *data, int *x, int *y, t_point *p)
{
  *x = (int)data->player.x / data->img_size;
	*y = (int)data->player.y / data->img_size;
	p->min_x = *x - DOOR_DIST;
	p->max_x = *x + DOOR_DIST;
	p->min_y = *y - DOOR_DIST;
	p->max_y = *y + DOOR_DIST;
}

t_bool	door_around(t_data *data, int *door_x, int *door_y)
{
	int	x;
	int	y;
  t_point p;

	assign_points(data, &x, &y, &p);
  if (is_door(data->map.tab[y][x]))
    return (false);
	while (p.min_y <= p.max_y)
	{
		x = p.min_x;
		while (x <= p.max_x)
		{
			if (x >= 0 && x < data->map.columns
        && p.min_y >= 0 && p.min_y < data->map.rows
        && (is_door(data->map.tab[p.min_y][x])))
			{
				*door_x = x;
				*door_y = p.min_y;
				return (true);
			}
			x++;
		}
		p.min_y++;
	}
	return (false);
}

void	open_or_close_door(t_data *data)
{
	int	door_x;
	int	door_y;

	if (door_around(data, &door_x, &door_y))
	{
		if (data->map.tab[door_y][door_x] == CLOSE_D)
			data->map.tab[door_y][door_x] = OPEN_D;
		else if (data->map.tab[door_y][door_x] == OPEN_D)
			data->map.tab[door_y][door_x] = CLOSE_D;
		fill_window(data);
	}
}
