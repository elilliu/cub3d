/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_error_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neleon <neleon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 18:34:03 by bineleon          #+#    #+#             */
/*   Updated: 2025/03/11 18:36:43 by neleon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d_bonus.h"

t_bool	path_exist(char *path)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (false);
	close(fd);
	return (true);
}

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
			print_clean(data, "Texture path must be in .xpm");
		else if (!path_exist(textures[i]))
			print_clean(data, "Wrong texture path");
		i++;
	}
}
