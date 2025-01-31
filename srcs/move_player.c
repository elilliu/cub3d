/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elilliu <elilliu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 12:54:16 by elilliu@stu       #+#    #+#             */
/*   Updated: 2025/01/29 17:09:30 by elilliu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	move_player_up(t_data *data)
{
	if (data->player.y == 0)
	{
		if (data->map.tab[data->player.line - 1][data->player.column] == '1')
			return ;
		else
		{
			data->map.tab[data->player.line][data->player.column] = '0';
			data->player.line--;
			data->player.y = 60;
			data->map.tab[data->player.line][data->player.column] = 'N';
			return ;
		}
	}
	else
		data->player.y -= 4;
}

void	move_player_left(t_data *data)
{
	if (data->player.x == 0)
	{
		if (data->map.tab[data->player.line][data->player.column - 1] == '1')
			return ;
		else
		{
			data->map.tab[data->player.line][data->player.column] = '0';
			data->player.column--;
			data->player.x = 60;
			data->map.tab[data->player.line][data->player.column] = 'N';
			return ;
		}
	}
	else
		data->player.x -= 4;
}

void	move_player_down(t_data *data)
{
	if (data->player.y == 56)
	{
		if (data->map.tab[data->player.line + 1][data->player.column] == '1')
			return ;
		else
		{
			data->player.y = 60;
			return ;
		}
	}
	else if (data->player.y == 60)
	{
		data->map.tab[data->player.line][data->player.column] = '0';
		data->player.line++;
		data->player.y = 0;
		data->map.tab[data->player.line][data->player.column] = 'N';
	}
	else
		data->player.y += 4;
}

void	move_player_right(t_data *data)
{
	if (data->player.x == 56)
	{
		if (data->map.tab[data->player.line][data->player.column + 1] == '1')
			return ;
		else
		{
			data->player.x = 60;
			return ;
		}
	}
	else if (data->player.x == 60)
	{
		data->map.tab[data->player.line][data->player.column] = '0';
		data->player.column++;
		data->player.x = 0;
		data->map.tab[data->player.line][data->player.column] = 'N';
	}
	else
		data->player.x += 4;
}
