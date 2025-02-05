/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_error.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelbi <neleon@student.42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 18:34:03 by bineleon          #+#    #+#             */
/*   Updated: 2025/02/05 12:41:10 by nelbi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	error_t_path(t_data *data)
{
	char	*textures[4];
	int		i;

	i = 0;
	textures[0] = data->t_paths.t_no;
	textures[1] = data->t_paths.t_so;
	textures[2] = data->t_paths.t_we;
	textures[3] = data->t_paths.t_ea;
	while (i < 4)
	{
		if (!verif_path(textures[i], ".xpm"))
		{
			print_error("Texture path must be in .xpm");
			clean_all(data);
		}
		i++;
	}
}


