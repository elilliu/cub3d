/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neleon <neleon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 16:15:52 by neleon            #+#    #+#             */
/*   Updated: 2025/01/29 18:04:04 by neleon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int check_texture(char *line)
{
    int i;
    
    i = skip_whitespaces(line, i);
    if (line[i] == 'N')
        return(T_NO);
    else if (line[i] == 'S')
        return (T_SO);
    else if (line[i] == 'W')
        return (T_WE);
    else if (line[i] == 'E')
        return (T_EA);
    return (-1);
}

int skip_tex_type(char *line, int i)
{
    i = skip_whitespaces(line, i);
    i += 2;
    i = skip_whitespaces(line, i);
    return (i);
}

int path_len(char *path)
{
    int len;
    
    len = 0;
    while(path[len] && !is_whitespace(path[len]))
        len++;
    return (len);
}

int    extarct_text_path(char *line, t_data *data)
{
    int texture;
    int i;

    texture = check_texture(line);
    i = skip_tex_type(line, i);
    if (texture == T_NO) 
    {   
        if (!data->tex_path.t_no)
        {
            data->tex_path.t_no = gc_mem(MALLOC,  path_len(&line[i] + 1), NULL);     
            ft_strlcpy(data->tex_path.t_no, &line[i], path_len(&line[i] + 1));
            return (1); 
        }
        return (0);
    }
    else if (texture == T_SO) 
    {   
        if (!data->tex_path.t_so)
        {
            data->tex_path.t_so = gc_mem(MALLOC,  path_len(&line[i] + 1), NULL);     
            ft_strlcpy(data->tex_path.t_so, &line[i], path_len(&line[i] + 1));
            return (1);
        }
        return (0);
    }
    else if (texture == T_WE) 
    {   
        if (!data->tex_path.t_we)
        {
            data->tex_path.t_we = gc_mem(MALLOC,  path_len(&line[i] + 1), NULL);     
            ft_strlcpy(data->tex_path.t_we, &line[i], path_len(&line[i] + 1));
            return (1);
        }
        return (0);
    }
    else if (texture == T_EA) 
    {   
        if (!data->tex_path.t_ea)
        {
            data->tex_path.t_ea = gc_mem(MALLOC,  path_len(&line[i] + 1), NULL);     
            ft_strlcpy(data->tex_path.t_ea, &line[i], path_len(&line[i] + 1));
            return (1);
        }
        return (0);
    }
    return (0);
}

// t_bool before_map

void  map_start(char  *line, int fd)
{
    int i;
    
    i = 0;
    while (empty_line(line))
    {
        if (line)
            free(line);
        line = get_next_line(fd, 0);
    }
}

void	parse_textures(t_data *data)
{
	char	*line;
    int     texture_count;
    
    texture_count = 0;
	data->fd_cub = open(data->map_path, O_RDONLY);
	if (data->fd_cub < 0)
		return (print_error("Failed to open file"), 0);
	line = get_next_line(data->fd_cub, 0);
	if (!line)
		return (close(data->fd_cub), 0);
	while (line && texture_count <= 6)
	{ 
        if (is_texture(line) && texture_count == 6)
        {
            print_error("Too many textures in .cub file");
            clean_map_reading(line, data->fd_cub);
            clean_all(data);
        }
        if (!is_texture(line) && !empty_line(line) && texture_count < 6)
        {
            print_error("Wrong texture");
            clean_map_reading(line, data->fd_cub);
            clean_all(data);
        }
		if (is_texture(line))
        {
            extarct_text_path(line, data);
            texture_count++;
        }
		free(line);
		line = get_next_line(data->fd_cub, 0);
	}
	// clean_map_reading(line, data->fd_cub);
}

void parse_map(t_data *data)
{
    char    *line;

    line = NULL;
    map_start(line, data->fd_cub);
    while (line)
    {
        data->map.tab[i] = gc_strdup(line);
		free(line);
    }
    
}