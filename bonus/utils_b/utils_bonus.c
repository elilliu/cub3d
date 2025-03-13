/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neleon <neleon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 15:20:50 by neleon            #+#    #+#             */
/*   Updated: 2025/03/13 17:53:24 by neleon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d_bonus.h"

t_bool	is_door(char c)
{
	if (c == OPEN_D || c == CLOSE_D)
		return (true);
	return (false);
}

t_bool	is_wall_or_door(char c)
{
	if (c == CLOSE_D || c == WALL)
		return (true);
	return (false);
}

t_bool	is_wall_door_or_empty(char c)
{
	if (c == CLOSE_D || c == WALL || c == ' ' || !c)
		return (true);
	return (false);
}
