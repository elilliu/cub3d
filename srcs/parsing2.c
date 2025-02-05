/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelbi <neleon@student.42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 13:57:24 by neleon            #+#    #+#             */
/*   Updated: 2025/02/05 12:49:01 by nelbi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

t_bool  is_valid_rgb_char(char c)
{
    if (ft_isdigit(c) || is_whitespace(c) || c == ',')
        return (true);
    return (false);
}

t_bool  is_valid_rgb(char *str)
{
    int i;

    i = 0;
    while (str[i])
    {
        if (!is_valid_rgb_char(str[i]))
            return (false);
    }
    return (true);
}

t_bool  is_valid_rgb_value(int value)
{
    if (value >= 0  && value <= 255)
        return (true);
    return (false);
}

int extract_rgb(char *line, t_rgb *rgb)
{
    int i = 0;
	int j = 0;
	int k;
	int values[3];
    char temp[4];

	i = 0;
	j = 0;
	k = 0;
	if (!is_valid_rgb(line))
		return (print_error("Invalid RGB format"), 0);
    while (line[i] && j < 3)
    {
        while (line[i] && is_whitespace(line[i]))
            i++;
        while (line[i] && ft_isdigit(line[i]) && k < 3)
            temp[k++] = line[i++];
        temp[k] = '\0';
        if (k == 0)
            return (print_error("Invalid number format\n"), 0);
        values[j] = ft_atoi(temp);
        if (!is_valid_rgb_value(values[j]))
            return (print_error("Invalid RGB value (must be 0-255)\n", values[j]), 0);
        j++;
        while (line[i] && is_whitespace(line[i]))
            i++;
        if (j < 3 && (line[i] != ',' || !line[i + 1]))
            return (print_error("Invalid RGB format"), 0);
        i++;
    }
    if (j != 3 || line[i] != '\0')
        return (print_error("Invalid RGB format\n"), 0);
    rgb->r = values[0];
    rgb->g = values[1];
    rgb->b = values[2];
    return (1);
}

void	set_rgb(t_data *data)
{
	if (!extract_rgb(data->t_paths.t_fl, data->t_paths.fl))
		clean_all(data);
	if (!extract_rgb(data->t_paths.t_ce, data->t_paths.ce))
		clean_all(data);
}

