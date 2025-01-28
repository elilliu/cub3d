/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neleon <neleon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 18:12:34 by elilliu           #+#    #+#             */
/*   Updated: 2025/01/28 13:59:45 by neleon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

t_data	*get_data(void)
{
	static t_data	data;

	return (&data);
}

int	data_init(t_data *data, char *str)
{
	data->map_path = ft_strdup(str);
	return (1);
}
