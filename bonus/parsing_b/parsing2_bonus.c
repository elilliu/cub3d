/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elilliu <elilliu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 13:57:24 by neleon            #+#    #+#             */
/*   Updated: 2025/03/18 15:20:02 by elilliu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d_bonus.h"

int	extract_number(char *line, int *index)
{
	int		k;
	char	temp[4];

	k = 0;
	*index = skip_whitespaces(line, *index);
	while (line[*index] && ft_isdigit(line[*index]) && k < 3)
		temp[k++] = line[(*index)++];
	temp[k] = '\0';
	if (k == 0)
		return (-1);
	return (ft_atoi(temp));
}

int	extract_rgb_values(char *line, t_rgb *rgb)
{
	int	i;
	int	j;
	int	values[3];

	i = 0;
	j = 0;
	while (line[i] && j < 3)
	{
		values[j] = extract_number(line, &i);
		if (values[j] == -1 || !is_valid_rgb_value(values[j]))
			return (print_error("Invalid RGB value (must be 0-255)"), 0);
		j++;
		i = skip_whitespaces(line, i);
		if (j < 3 && (line[i] != ',' || !line[i + 1]))
			return (print_error("Invalid RGB format"), 0);
		if (j < 3)
			i++;
	}
	i = skip_whitespaces(line, i);
	if (j != 3 || line[i] != '\0')
		return (print_error("Invalid RGB format"), 0);
	rgb->r = values[0];
	rgb->g = values[1];
	rgb->b = values[2];
	return (1);
}

void	set_rgb(t_data *data)
{
	if (!data->t_paths.t_fl || !data->t_paths.t_ce)
		clean_all(data);
	if (!is_valid_rgb(data->t_paths.t_fl)
		|| !extract_rgb_values(data->t_paths.t_fl, &data->t_paths.fl))
		clean_all(data);
	if (!is_valid_rgb(data->t_paths.t_ce)
		|| !extract_rgb_values(data->t_paths.t_ce, &data->t_paths.ce))
		clean_all(data);
}
