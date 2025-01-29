/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elilliu@student.42.fr <elilliu>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 12:54:16 by elilliu@stu       #+#    #+#             */
/*   Updated: 2025/01/29 13:05:14 by elilliu@stu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	move_player_up(t_data *data)
{
	if (data->player.y < 5)
	{
		if (data->map.tab[data->player.square_y - 1] == '1')
		{
			while (data->player.y)
				data->player.y--;
			return ;
		}
		else
		
	}
	data->player.y -= 5;
	if (data->player.y < 0)
	{
		data->
	}
}
