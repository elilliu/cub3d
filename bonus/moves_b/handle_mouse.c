/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_mouse.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bineleon <neleon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 15:51:46 by elilliu           #+#    #+#             */
/*   Updated: 2025/03/14 17:34:30 by bineleon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d_bonus.h"

void  toggle_mouse(t_data *data)
{
  if(data->mouse_on)
    data->mouse_on = false;
  else
    data->mouse_on = true;
}

int	handle_mouse(t_data *data)
{
  if (data->mouse_on)
  {
    mlx_mouse_get_pos(data->mlx_ptr, data->win_ptr,
      &data->mouse.x, &data->mouse.y);
    if (data->mouse.x >= (WIDTH / 2 + 10))
      rotate_player_right(data);
    if (data->mouse.x <= (WIDTH / 2 - 10))
      rotate_player_left(data);
    mlx_mouse_move(data->mlx_ptr, data->win_ptr, WIDTH / 2, HEIGHT / 2);
	  return (1);
  }
  return (0);
}
