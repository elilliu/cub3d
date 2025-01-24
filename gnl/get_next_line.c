/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elilliu@student.42.fr <elilliu>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 18:54:31 by elilliu           #+#    #+#             */
/*   Updated: 2023/11/21 18:13:41 by elilliu@stu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*add_to_stash(int fd, char *stash, int *count)
{
	char	*buf;

	buf = ft_calloc(sizeof(char), (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	while (ft_strchr(buf) && *count)
	{
		*count = (int)read(fd, buf, BUFFER_SIZE);
		if (*count < 0 || (*count == 0 && stash == NULL))
		{
			free(buf);
			free(stash);
			return (NULL);
		}
		buf[*count] = '\0';
		stash = ft_strjoin(stash, buf);
		if (!stash)
		{
			free(buf);
			return (NULL);
		}
	}
	free(buf);
	return (stash);
}

char	*stash_to_line(char *stash)
{
	char	*line;
	int		i;

	i = 0;
	if (!stash[i])
		return (NULL);
	while (stash[i] && stash[i] != '\n')
		i++;
	line = ft_calloc(sizeof(char), (i + 2));
	if (!line)
		return (NULL);
	i = 0;
	while (stash[i] && stash[i] != '\n')
	{
		line[i] = stash[i];
		i++;
	}
	if (stash[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*new_stash(char *stash)
{
	char	*new;
	int		c;
	int		i;

	i = 0;
	while (stash[i] != '\n' && stash[i])
		i++;
	if (!stash[i])
	{
		free (stash);
		return (NULL);
	}
	new = ft_calloc(sizeof(char), (ft_strlen(stash) - i + 1));
	if (!new)
	{
		free(stash);
		return (NULL);
	}
	i++;
	c = 0;
	while (stash[i])
		new[c++] = stash[i++];
	new[c] = '\0';
	free(stash);
	return (new);
}

char	*get_next_line(int fd)
{
	static char	*stash = NULL;
	char		*line;
	int			count;

	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &line, 0) < 0)
		return (NULL);
	count = 1;
	stash = add_to_stash(fd, stash, &count);
	if (!stash)
		return (NULL);
	line = stash_to_line(stash);
	if (!line)
	{
		free(stash);
		return (NULL);
	}
	stash = new_stash(stash);
	return (line);
}
