/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elilliu <elilliu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 14:50:30 by elilliu           #+#    #+#             */
/*   Updated: 2025/01/29 17:03:35 by elilliu          ###   ########.fr       */
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
}			t_bool;

typedef enum e_mem
{
	MALLOC,
	FREE,
	FULL_CLEAN
}			t_mem;

typedef struct s_garbage_co
{
	void				*ptr;
	struct s_garbage_co	*next;
}			t_garbage_co;

typedef struct s_fill_tab
{
	int		fd;
	int		i;
	int		row;
	char	*line;
}			t_fill_tab;

typedef struct s_map
{
	char	**tab;
	int		rows;
}			t_map;

typedef struct s_player
{
	int	line;
	int	column;
	int	x;
	int	y;

}			t_player;

typedef struct s_data
{
	void			*mlx_ptr;
	void			*win_ptr;
	char			*map_path;
	t_player		player;
	int				sizex;
	int				sizey;
	t_map			map;
	t_garbage_co	*garbage;

}			t_data;

int		main(int ac, char **av);
t_data	*get_data(void);
int		verif_path(char *str);
int		data_init(t_data *data, char *str);
int		verif_map(t_data *data);
void	print_error(char *s);
void	*gc_mem(t_mem type, size_t size, void *ptr);
int		fill_window(t_data *data);
int		map_init(t_data *data);
t_bool	is_whitespace(char c);
int		skip_whitespaces(char *line, int i);
char	*gc_strdup(const char *s1);
void	move_player_up(t_data *data);
void	move_player_left(t_data *data);
void	move_player_down(t_data *data);
void	move_player_right(t_data *data);

#endif
