/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neleon <neleon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 13:57:24 by neleon            #+#    #+#             */
/*   Updated: 2025/02/04 15:36:00 by neleon           ###   ########.fr       */
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