/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bineleon <neleon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 14:50:30 by elilliu           #+#    #+#             */
/*   Updated: 2025/02/20 13:27:40 by bineleon         ###   ########.fr       */
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

# define PI 3.1415926535
# define RADIAN 0.0174533

# define WIDTH 1600
# define HEIGHT 800
# define FOV 60
# define IMG_SIZE 128

# define RESET "\033[0m"
# define SMRED "\033[0;31m"
# define SMGREEN "\033[0;32m"
# define SMYELLOW "\033[0;33m"
# define SMBLUE "\033[0;34m"
# define SMMAGENTA "\033[0;35m"
# define SMCYAN "\033[0;36m"
# define RED "\033[1;31m"
# define GREEN "\033[1;32m"
# define YELLOW "\033[1;33m"
# define BLUE "\033[1;34m"
# define MAGENTA "\033[1;35m"
# define CYAN "\033[1;36m"

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
	int					columns;
	// int					square_size;
}						t_map;

typedef struct s_map2
{
	char				*line;
	struct s_map2		*next;
}						t_map2;

typedef struct s_player
{
	float				x;
	float				y;
	float				delta_x;
	float				delta_y;
	double				angle;
}						t_player;

typedef struct s_rgb
{
	int					r;
	int					g;
	int					b;
}						t_rgb;

typedef struct s_tex_path
{
	char				*t_no;
	char				*t_so;
	char				*t_we;
	char				*t_ea;
	char				*t_fl;
	char				*t_ce;
	t_rgb				fl;
	t_rgb				ce;
}						t_tex_path;

typedef struct s_img
{
	void				*img_ptr;
	char				*addr;
	int					h;
	int					w;
	int					bpp;
	int					endian;
	int					line_len;
}						t_img;

typedef struct s_ray
{
	double				horizontal_x;
	double				horizontal_y;
	double				vertical_x;
	double				vertical_y;
	float				nb;
	float				angle;
	double				horizontal_distance;
	double				vertical_distance;
	double				size;
}						t_ray;

typedef struct s_data
{
	int					*tex_buff[4];
	int					test;
	void				*mlx_ptr;
	void				*win_ptr;
	char				*map_path;
	t_player			player;
	int					fd_cub;
	t_img				background;
	t_img				textures[6];
	t_map				map;
	t_map2				*map2;
	int					row_count;
	int					img_size;
	t_tex_path			t_paths;
	t_garbage_co		*garbage;
}						t_data;

int						main(int ac, char **av);
int						verif_path(char *str, char *extension);
int						parse_textures(t_data *data, char **line);
int						data_init(t_data *data, char *str);
int						verif_map(t_data *data);
t_data					*get_data(void);
void					print_error(char *s);
void					*gc_mem(t_mem type, size_t size, void *ptr);
void					fill_window(t_data *data);
int						map_init(t_data *data);
t_bool					is_whitespace(char c);
int						skip_whitespaces(char *line, int i);
char					*gc_strdup(const char *s1);
void					clean_map_reading(char *line, int map_fd);
t_bool					is_texture(char *line);
t_bool					empty_line(char *line);
int						clean_all(t_data *data);
t_bool					is_valid_char_map(char c);
t_bool					is_wall_texture(char *line);
char					*gc_dup_map(const char *s1);
int						parse_file(t_data *data);
void					move_player_up(t_data *data);
void					move_player_left(t_data *data);
void					move_player_down(t_data *data);
void					move_player_right(t_data *data);
void					error_t_path(t_data *data);
t_bool					is_player_char(char c);
void					print_clean(t_data *data, char *err_mess);
void					print_clean_reading(t_data *data, char *line,
							char *mess);
void					map_validation(t_data *data, char **map);
void					put_pixel_img(t_img img, int x, int y, int color);
void					rotate_player_left(t_data *data);
void					rotate_player_right(t_data *data);
void					set_rgb(t_data *data);
float					deg_to_rad(float a);
void					add_ceiling(t_data *data);
void					add_floor(t_data *data);
void					print_line(t_data *data, float x, float y, float size,
							int color);
void					put_square(t_data *data, int x, int y, int color,
							int size);
void					put_horizontal_wall(t_data *data, t_ray ray);
void					put_vertical_wall(t_data *data, t_ray ray);
unsigned int			get_pixel_img(t_img img, float x, float y);
void					init_textures(t_data *data);
void					print_north(t_data *data, t_ray ray, float x, float y);
void					print_south(t_data *data, t_ray ray, float x, float y);
void					print_east(t_data *data, t_ray ray, float x, float y);
void					print_west(t_data *data, t_ray ray, float x, float y);

#endif
