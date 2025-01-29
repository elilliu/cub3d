/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neleon <neleon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 18:01:02 by elilliu           #+#    #+#             */
/*   Updated: 2025/01/29 14:09:58 by neleon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	verif_path(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	if (str[i - 1] != 'b' || str[i - 2] != 'u'
		|| str[i - 3] != 'c' || str[i - 4] != '.')
		return (0);
	return (1);
}

void  print_error(char *s)
{
  ft_putstr_fd("Error\n", 2);
  ft_putstr_fd(s, 2);
  ft_putstr_fd("\n", 2);
}

t_bool	is_whitespace(char c)
{
	if ((c == 32 || (c >= 9 && c <= 13)))
		return (true);
	return (false);
}

int	skip_whitespaces(char *line, int i)
{
	while (line[i] && is_whitespace(line[i]))
		i++;
	return (i);
}

void	clean_map_reading(char *line, int map_fd)
{
	if (line)
		free(line);
	line = NULL;
	get_next_line(map_fd, 1);
	close(map_fd);
}