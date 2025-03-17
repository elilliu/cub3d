/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neleon <neleon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 11:22:46 by neleon            #+#    #+#             */
/*   Updated: 2025/03/13 11:22:50 by neleon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

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
