/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neleon <neleon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 13:46:29 by neleon            #+#    #+#             */
/*   Updated: 2025/03/13 15:43:45 by neleon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d_bonus.h"

void	free_texture(t_data *data, int nb)
{
	int	i;

	i = 0;
	while (i < nb && data->textures[i].img_ptr)
	{
		mlx_destroy_image(data->mlx_ptr, data->textures[i].img_ptr);
		i++;
	}
}

static char	*assign_path(t_data *data, int tex_type)
{
	if (tex_type == T_NO)
		return (data->t_paths.t_no);
	else if (tex_type == T_SO)
		return (data->t_paths.t_so);
	else if (tex_type == T_EA)
		return (data->t_paths.t_ea);
	else if (tex_type == T_WE)
		return (data->t_paths.t_we);
	else if (tex_type == T_DO)
		return (data->t_paths.t_do);
	return (0);
}

int	xpm_to_img(t_data *data, int tex_type)
{
	char	*path;

	path = assign_path(data, tex_type);
	data->textures[tex_type].img_ptr = mlx_xpm_file_to_image(data->mlx_ptr,
			path, &data->textures[tex_type].w, &data->textures[tex_type].h);
	if (!data->textures[tex_type].img_ptr)
		return (free_texture(data, tex_type), 0);
	data->textures[tex_type].addr = mlx_get_data_addr(
			data->textures[tex_type].img_ptr,
			&data->textures[tex_type].bpp, &data->textures[tex_type].line_len,
			&data->textures[tex_type].endian);
	return (1);
}

void	init_textures(t_data *data)
{
	if (!xpm_to_img(data, T_NO)
		|| !xpm_to_img(data, T_SO)
		|| !xpm_to_img(data, T_WE)
		|| !xpm_to_img(data, T_EA)
		|| !xpm_to_img(data, T_DO))
		print_clean(data, "Failed texture allocation");
}
