/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bineleon <neleon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 18:01:02 by elilliu           #+#    #+#             */
/*   Updated: 2025/01/31 19:35:20 by bineleon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int verif_path(char *str, char *extension)
{
	int str_len;
	int ext_len;
  int i;

  i = 0;
	if (!str || !extension)
		return (0);
	str_len = ft_strlen(str);
	ext_len = ft_strlen(extension);
	if (str_len < ext_len)
		return (0);
  i = str_len - ext_len - 1;
  while (i >= 1)
  {
    if (str[i] == '.')
      return (0);
    i--;
  }
	if (ft_strcmp(&str[str_len - ext_len], extension) == 0)
		return (1);
	return (0);
}

void  print_error(char *s)
{
  ft_putstr_fd("Error\n", 2);
  ft_putstr_fd(s, 2);
  ft_putstr_fd("\n", 2);
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

void	clean_map_reading(char *line, int map_fd)
{
	if (line)
		free(line);
	line = NULL;
	get_next_line(map_fd, 1);
	close(map_fd);
}
