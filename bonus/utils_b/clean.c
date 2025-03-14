/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelbi <neleon@student.42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 14:46:45 by bineleon          #+#    #+#             */
/*   Updated: 2025/03/14 20:14:05 by nelbi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d_bonus.h"

void	print_error(char *s)
{
	ft_putstr_fd(RED, 2);
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(s, 2);
	ft_putstr_fd("\n", 2);
	ft_putstr_fd(RESET, 2);
}

void	print_clean(t_data *data, char *err_mess)
{
	if (err_mess)
		print_error(err_mess);
	clean_all(data);
}

void	clean_map_reading(char *line, int map_fd)
{
	if (line)
		free(line);
	line = NULL;
	get_next_line(map_fd, 1);
	close(map_fd);
}

void	print_clean_reading(t_data *data, char *line, char *mess)
{
	if (mess)
		print_error(mess);
	clean_map_reading(line, data->fd_cub);
	clean_all(data);
}

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
