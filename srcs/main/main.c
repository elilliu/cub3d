/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neleon <neleon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 17:48:05 by elilliu           #+#    #+#             */
/*   Updated: 2025/03/13 14:17:19 by neleon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	render(void)
{
	return (1);
}

int	main(int ac, char **av)
{
	t_data	*data;

	data = get_data();
	if (ac != 2)
		return (print_error("Please follow this format: ./cub3d map_path"), 1);
	if (!verif_path(av[1], ".cub"))
		return (print_error("Map must be a .cub type file"), 1);
	if (!data_init(data, av[1]))
		return (1);
	print_textures(data);
	print_rgb(data);
	print_map(data);
	fill_window(data);
	mlx_loop_hook(data->mlx_ptr, &render, data);
	mlx_hook(data->win_ptr, KeyPress, KeyPressMask, &handle_keypress, data);
	mlx_hook(data->win_ptr, DestroyNotify, StructureNotifyMask, &clean_all,
		data);
	mlx_loop(data->mlx_ptr);
	return (0);
}
