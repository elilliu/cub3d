/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neleon <neleon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 13:57:24 by neleon            #+#    #+#             */
/*   Updated: 2025/02/28 17:32:46 by neleon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

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
        {
            print_error("Invalid RGB format");
            return (false);
        }
        i++;
    }
    return (true);
}

t_bool  is_valid_rgb_value(int value)
{
    if (value >= 0  && value <= 255)
        return (true);
    return (false);
}

int extract_number(char *line, int *index)
{
    int k;
    char temp[4];

    k = 0;
    *index = skip_whitespaces(line, *index);
    while (line[*index] && ft_isdigit(line[*index]) && k < 3)
        temp[k++] = line[(*index)++];
    temp[k] = '\0';
    if (k == 0)
        return (-1);
    return (ft_atoi(temp));
}

int extract_rgb_values(char *line, t_rgb *rgb)
{
    int i;
    int j;
    int values[3];

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
	if (!is_valid_rgb(data->t_paths.t_fl)
      ||!extract_rgb_values(data->t_paths.t_fl, &data->t_paths.fl))
		clean_all(data);
	if (!is_valid_rgb(data->t_paths.t_ce)
      ||!extract_rgb_values(data->t_paths.t_ce, &data->t_paths.ce))
		clean_all(data);
}
