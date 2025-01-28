/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neleon <neleon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: Invalid date        by                   #+#    #+#             */
/*   Updated: 2025/01/28 15:37:34 by neleon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

t_data	*get_data(void)
{
	static t_data	data;

	return (&data);
}

int	data_init(t_data *data, char *str)
{
	data->map_path = ft_strdup(str);
	data->map.rows = 0;
	data->map.length = 0;
	if (!map_init(data))
		return (0);
	data->mlx_ptr = mlx_init();
	if (!data->mlx_ptr)
		return (0);
	data->win_ptr = mlx_new_window(data->mlx_ptr, data->map.length * 32,
			data->map.rows * 32, "cub3d");
	if (!data->win_ptr)
		return (free(data->mlx_ptr), 0);
	return (1);
}
