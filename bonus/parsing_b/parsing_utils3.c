/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neleon <neleon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 11:46:46 by neleon            #+#    #+#             */
/*   Updated: 2025/03/13 15:44:06 by neleon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d_bonus.h"

t_bool	is_valid_rgb_char(char c)
{
	if (ft_isdigit(c) || is_whitespace(c) || c == ',')
		return (true);
	return (false);
}

t_bool	is_valid_rgb(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!is_valid_rgb_char(str[i]))
		{
			print_error("Invalid RGB format");
			return (false);
		}
		i++;
	}
	return (true);
}

t_bool	is_valid_rgb_value(int value)
{
	if (value >= 0 && value <= 255)
		return (true);
	return (false);
}
