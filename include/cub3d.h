/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neleon <neleon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: Invalid date        by                   #+#    #+#             */
/*   Updated: 2025/01/28 14:31:29 by neleon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#ifndef CUB3D_H
# define CUB3D_H

# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <math.h>
# include "../mlx/mlx.h"
# include "../libft/libft/libft.h"
# include "../libft/gnl/get_next_line_bonus.h"
# include <X11/keysym.h>
# include <X11/X.h>

typedef enum e_mem
{
	MALLOC,
	FREE,
	FULL_CLEAN
}							t_mem;

typedef struct s_garbage_co
{
	void					*ptr;
	struct s_garbage_co		*next;
}							t_garbage_co;

typedef struct s_fill_tab
{
	int		fd;
	int		i;
	int		row;
	char	*line;
}				t_fill_tab;

typedef struct s_map
{
	char	**tab;
	int		rows;
	int		length;
}				t_map;


typedef struct s_data
{
	void			*mlx_ptr;
	void			*win_ptr;
	char			*map_path;
	t_map			map;
	t_garbage_co	*garbage;

}				t_data;


int		main(int ac, char **av);
int		verif_path(char *str);
int		data_init(t_data *data, char *str);
int		verif_map(t_data *data);
t_data	*get_data(void);
void	print_error(char *s);

#endif
