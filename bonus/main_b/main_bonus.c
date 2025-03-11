/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neleon <neleon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 17:48:05 by elilliu           #+#    #+#             */
/*   Updated: 2025/03/11 17:57:50 by neleon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d_bonus.h"

int	clean_all(t_data *data)
{
	if (data->mlx_ptr)
	{
		if (data->win_ptr)
		{
			free_texture(data, 5);
			mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		}
		mlx_destroy_display(data->mlx_ptr);
		free(data->mlx_ptr);
	}
	gc_mem(FULL_CLEAN, 0, NULL);
	exit(0);
}

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

int	render(void)
{
	return (1);
}

void	print_map(t_data *data)
{
	int	i;

	i = 0;
	while (data->map.tab[i])
	{
		printf("%s\n", data->map.tab[i]);
		i++;
	}
}

void	print_textures(t_data *data)
{
	printf("%s\n", data->t_paths.t_no);
	printf("%s\n", data->t_paths.t_so);
	printf("%s\n", data->t_paths.t_ea);
	printf("%s\n", data->t_paths.t_we);
	printf("%s\n", data->t_paths.t_fl);
	printf("%s\n", data->t_paths.t_ce);
	printf("\n");
}

void	print_rgb(t_data *data)
{
	printf("Floor RGB :\n");
	printf("red : %d\n", data->t_paths.fl.r);
	printf("green : %d\n", data->t_paths.fl.g);
	printf("blue : %d\n", data->t_paths.fl.b);
	printf("Ceiling RGB :\n");
	printf("red : %d\n", data->t_paths.ce.r);
	printf("green : %d\n", data->t_paths.ce.g);
	printf("blue : %d\n", data->t_paths.ce.b);
	printf("\n");
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
	init_textures(data);
	fill_window(data);
	mlx_loop_hook(data->mlx_ptr, &render, data);
	mlx_hook(data->win_ptr, KeyPress, KeyPressMask, &handle_keypress, data);
	mlx_hook(data->win_ptr, DestroyNotify, StructureNotifyMask, &clean_all,
		data);
	mlx_loop(data->mlx_ptr);
	return (0);
}
