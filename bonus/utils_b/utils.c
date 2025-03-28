/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elilliu <elilliu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 18:01:02 by elilliu           #+#    #+#             */
/*   Updated: 2025/03/17 17:47:01 by elilliu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d_bonus.h"

float	deg_to_rad(float a)
{
	return (a * RADIAN);
}

int	verif_path(char *str, char *extension)
{
	int	str_len;
	int	ext_len;
	int	i;

	i = 0;
	if (!str || !extension)
		return (0);
	str_len = ft_strlen(str);
	ext_len = ft_strlen(extension);
	if (str_len < ext_len)
		return (0);
	i = str_len - ext_len - 1;
	while (i >= 1 && str[i] != '/')
	{
		if (str[i] && i == 1 && str[i] == '.' && str[0] != '.')
			return (0);
		if (str[i] == '.')
			return (0);
		i--;
	}
	if (ft_strcmp(&str[str_len - ext_len], extension) == 0)
		return (1);
	return (0);
}

t_bool	is_whitespace(char c)
{
	if (!c)
		return (false);
	if ((c == 32 || (c >= 9 && c <= 13)))
		return (true);
	return (false);
}

int	skip_whitespaces(char *line, int i)
{
	if (!line)
		return (-1);
	while (line[i] && is_whitespace(line[i]))
		i++;
	return (i);
}

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
