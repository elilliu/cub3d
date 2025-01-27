/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelbi <neleon@student.42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 17:48:05 by elilliu           #+#    #+#             */
/*   Updated: 2025/01/27 15:17:29 by nelbi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	main(int ac, char **av)
{
	t_data	data;

  data = get_data();
	if (ac != 2)
		return (printf("Please follow this format: ./cub3d map_path\n"), 1);
	if (!verif_path(av[1]))
		return (printf("Map must be a .cub type file\n"), 1);
	data_init(&data, av[1]);
	return (0);
}
