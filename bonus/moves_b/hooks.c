/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neleon <neleon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 11:31:37 by neleon            #+#    #+#             */
/*   Updated: 2025/03/13 18:09:13 by neleon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d_bonus.h"

int	handle_keypress(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
		clean_all(data);
	if (keysym == XK_w)
		move_player_up(data);
	if (keysym == XK_a)
		move_player_left(data);
	if (keysym == XK_s)
		move_player_down(data);
	if (keysym == XK_d)
		move_player_right(data);
	if (keysym == XK_Right)
		rotate_player_right(data);
	if (keysym == XK_Left)
		rotate_player_left(data);
	if (keysym == XK_space)
		open_or_close_door(data);
	return (1);
}
