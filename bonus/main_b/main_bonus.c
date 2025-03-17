/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elilliu <elilliu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 17:48:05 by elilliu           #+#    #+#             */
/*   Updated: 2025/03/17 17:55:13 by elilliu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d_bonus.h"

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
	gettimeofday(&data->start, NULL);
	gettimeofday(&data->mike, NULL);
	print_textures(data);
	print_rgb(data);
	print_map(data);
	fill_window(data);
	mlx_loop_hook(data->mlx_ptr, &render, data);
	mlx_loop_hook(data->mlx_ptr, &handle_mouse, data);
	mlx_hook(data->win_ptr, KeyPress, KeyPressMask, &handle_keypress, data);
	mlx_hook(data->win_ptr, DestroyNotify, StructureNotifyMask, &clean_all,
		data);
	mlx_loop(data->mlx_ptr);
	return (0);
}
