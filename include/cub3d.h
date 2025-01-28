/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bineleon <neleon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 17:48:44 by elilliu           #+#    #+#             */
/*   Updated: 2025/01/27 17:01:50 by bineleon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include "../mlx/mlx.h"
# include "../libft/libft.h"
# include "../gnl/get_next_line.h"
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


typedef struct s_data
{
	void			*mlx_ptr;
	void			*win_ptr;
	char			*map_path;
  	t_garbage_co	*garbage;

}			t_data;


int	main(int ac, char **av);
int	verif_path(char *str);
int	data_init(t_data *data, char *str);
int	verif_map(t_data *data);
t_data	*get_data(void);
void  print_error(char *s);

#endif
