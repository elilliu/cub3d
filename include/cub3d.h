/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neleon <neleon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: Invalid date        by                   #+#    #+#             */
/*   Updated: 2025/01/29 17:53:04 by neleon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../libft/gnl/get_next_line_bonus.h"
# include "../libft/libft/libft.h"
# include "../mlx/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <fcntl.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef enum e_bool
{
	false,
	true
}						t_bool;

typedef enum e_mem
{
	MALLOC,
	FREE,
	FULL_CLEAN
}						t_mem;

typedef enum e_chars_game
{
	PL_NO = 'N',
	PL_SO = 'S',
	PL_WE = 'W',
	PL_EA = 'E',
	WALL = '1',
	FLOOR = '0'
}						t_chars_game;

typedef enum e_textures
{
	T_NO,
	T_SO,
	T_WE,
	T_EA,
	T_CE,
	T_FL
}						t_textures;

typedef struct s_garbage_co
{
	void				*ptr;
	struct s_garbage_co	*next;
}						t_garbage_co;

typedef struct s_fill_tab
{
	int					fd;
	int					i;
	int					row;
	char				*line;
}						t_fill_tab;

typedef struct s_map
{
	char				**tab;
	int					rows;
}						t_map;

typedef struct s_player
{
	int					square_x;
	int					square_y;
	int					x;
	int					y;
}						t_player;

typedef struct s_tex_path
{
	char				*t_no;
	char				*t_so;
	char				*t_we;
	char				*t_ea;
	char				*t_fl;
	char				*t_ce;
}						t_tex_path;

typedef struct s_data
{
	void				*mlx_ptr;
	void				*win_ptr;
	char				*map_path;
	t_player			player;
	int					sizex;
	int					sizey;
	int					fd_cub;
	t_map				map;
	t_tex_path			tex_path;
	t_garbage_co		*garbage;

}						t_data;

int						main(int ac, char **av);
int						verif_path(char *str);
int						data_init(t_data *data, char *str);
int						verif_map(t_data *data);
t_data					*get_data(void);
void					print_error(char *s);
void					*gc_mem(t_mem type, size_t size, void *ptr);
int						fill_window(t_data *data);
int						map_init(t_data *data);
t_bool					is_whitespace(char c);
int						skip_whitespaces(char *line, int i);
char					*gc_strdup(const char *s1);
void					clean_map_reading(char *line, int map_fd);
t_bool					is_texture(char *line);
t_bool					empty_line(char *line);
int						clean_all(t_data *data);
t_bool					is_valid_char_map(char c);

#endif
