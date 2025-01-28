/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neleon <neleon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 16:15:52 by neleon            #+#    #+#             */
/*   Updated: 2025/01/28 18:03:09 by neleon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

t_bool is_texture_cardi(char *line)
{
    int i;

    i = skip_whitespaces(line, 0);
    if (line[i] && line[i] == 'N' && line[i + 1] == 'O')
        return (true);
    else if (line[i] && line[i] == 'S' && line[i + 1] == 'O')
        return (true);
    else if (line[i] && line[i] == 'W' && line[i + 1] == 'E')
        return (true);
    else if (line[i] && line[i] == 'E' && line[i + 1] == 'A')
        return (true);
    return (false);
}
t_bool is_other_texture(char *line)
{
    int i;

    i = skip_whitespaces(line, 0);
    if (line[i] && line[i] == 'F' && line[i + 1] == ' ')
        return (true);
    else if (line[i] && line[i] == 'C' && line[i + 1] == ' ')
        return (true);
    return (false);
}

// int     parse_texture(char *line)
// {
//     while()
// }