/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elilliu <elilliu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 17:48:05 by elilliu           #+#    #+#             */
/*   Updated: 2025/01/28 17:56:16 by elilliu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	clean_all(t_data *data)
{
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	gc_mem(FULL_CLEAN, 0, NULL);
	exit (0);
}

int	handle_keypress(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
		clean_all(data);
	if (keysym == XK_d)
		data->player.x += 5;
	if (keysym == XK_a)
		data->player.x -= 5;
	if (keysym == XK_w)
		data->player.y -= 5;
	if (keysym == XK_s)
		data->player.y += 5;
	return (1);
}

int	render(t_data *data)
{
	fill_window(data);
	return (1);
}

int	main(int ac, char **av)
{
	t_data	*data;

	data = get_data();
	if (ac != 2)
		return (printf("Please follow this format: ./cub3d map_path\n"), 1);
	if (!verif_path(av[1]))
		return (printf("Map must be a .cub type file\n"), 1);
	if (!data_init(data, av[1]))
		return (1);
	mlx_loop_hook(data->mlx_ptr, &render, data);
	mlx_hook(data->win_ptr, KeyPress, KeyPressMask, &handle_keypress, data);
	mlx_hook(data->win_ptr, DestroyNotify, StructureNotifyMask, &clean_all, data);
	mlx_loop(data->mlx_ptr);
	return (0);
}
