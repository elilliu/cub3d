/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bineleon <neleon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 17:48:05 by elilliu           #+#    #+#             */
/*   Updated: 2025/01/31 18:17:16 by bineleon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	clean_all(t_data *data)
{
  if (data->mlx_ptr)
  {
    if (data->win_ptr)
      mlx_destroy_window(data->mlx_ptr, data->win_ptr);
    mlx_destroy_display(data->mlx_ptr);
	  free(data->mlx_ptr);
  }
	gc_mem(FULL_CLEAN, 0, NULL);
	exit (0);
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
	return (1);
}

int	render(t_data *data)
{
	fill_window(data);
	return (1);
}

void  print_map(t_data *data)
{
  int i;

  i = 0;
  while(data->map.tab[i])
  {
    printf("%s\n", data->map.tab[i]);
    i++;
  }
}

void  print_textures(t_data *data)
{
  printf("%s\n", data->t_no);
  printf("%s\n", data->t_so);
  printf("%s\n", data->t_ea);
  printf("%s\n", data->t_we);
  printf("%s\n", data->t_ce);
  printf("%s\n", data->t_fl);
  printf("\n");

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
  print_textures(data);
  print_map(data);
	mlx_loop_hook(data->mlx_ptr, &render, data);
	mlx_hook(data->win_ptr, KeyPress, KeyPressMask, &handle_keypress, data);
	mlx_hook(data->win_ptr, DestroyNotify, StructureNotifyMask, &clean_all, data);
	mlx_loop(data->mlx_ptr);
	return (0);
}
