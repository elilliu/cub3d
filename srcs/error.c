/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelbi <neleon@student.42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 14:46:45 by bineleon          #+#    #+#             */
/*   Updated: 2025/02/05 12:06:20 by nelbi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

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

void	print_clean_reading(t_data *data, char *line, char *mess)
{
    if (mess)
	    print_error(mess);
	clean_map_reading(line, data->fd_cub);
	clean_all(data);
}
