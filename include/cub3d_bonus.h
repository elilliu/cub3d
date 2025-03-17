/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elilliu <elilliu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 14:50:30 by elilliu           #+#    #+#             */
/*   Updated: 2025/03/17 14:41:31 by elilliu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_BONUS_H
# define CUB3D_BONUS_H

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

# define RADIAN 0.0174533

# define WIDTH 1600
# define HEIGHT 800
# define FOV 60
# define IMG_SIZE 400
# define MINIMAP_SIZE 256
# define WALL_DIST 50
# define DOOR_DIST 1
# define PLAYER_SPEED 20
# define DOOR_SPEED 100

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
	FLOOR = '0',
	CLOSE_D = 'C',
	OPEN_D = 'O'
}						t_chars_game;

typedef enum e_textures
{
	T_NO,
	T_SO,
	T_WE,
	T_EA,
	T_DO,
	T_CE,
	T_FL,
	T_DO1,
	T_DO2,
	T_DO3,
	T_DO4
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
	char				*t_do;
	char				*t_do1;
	char				*t_do2;
	char				*t_do3;
	char				*t_do4;
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
	char				type;
}						t_ray;

typedef struct s_rotate
{
	t_img				src;
	t_img				dst;
	double				angle;
	int					x;
	int					y;
}						t_rotate;

typedef struct s_point
{
	float				x;
	float				y;
	int					min_x;
	int					min_y;
	int					max_x;
	int					max_y;
}						t_point;

typedef struct s_draw
{
	float				start;
	float				end;
	float				step;
	float				x;
}						t_draw;

typedef struct s_mouse
{
	int					x;
	int					y;
}						t_mouse;

typedef struct s_data
{
	int					door;
	int					timer;
	int					*tex_buff[4];
	int					test;
	void				*mlx_ptr;
	void				*win_ptr;
	char				*map_path;
	t_player			player;
	int					fd_cub;
	t_img				background;
	t_img				minimap;
	t_img				textures[11];
	t_img				arrow;
	t_map				map;
	t_map2				*map2;
	int					row_count;
	int					img_size;
	t_tex_path			t_paths;
	t_mouse				mouse;
	char				player_dir;
	t_bool				mouse_on;
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
void					put_img_to_img(t_img dst, t_img src, int x, int y);
void					put_pixel_img(t_img img, int x, int y, int color);
void					rotate_player_left(t_data *data);
void					rotate_player_right(t_data *data);
void					set_rgb(t_data *data);
float					deg_to_rad(float a);
void					add_ceiling(t_data *data);
void					add_floor(t_data *data);
void					put_square(t_img img, t_point p, int color, int size);
void					put_horizontal_wall(t_data *data, t_ray ray);
void					put_vertical_wall(t_data *data, t_ray ray);
unsigned int			get_pixel_img(t_img img, float x, float y);
void					init_textures(t_data *data);
void					print_north(t_data *data, t_ray ray, float x, float y);
void					print_south(t_data *data, t_ray ray, float x, float y);
void					print_east(t_data *data, t_ray ray, float x, float y);
void					print_west(t_data *data, t_ray ray, float x, float y);
int						rgb_to_int(int r, int g, int b);
void					minimap(t_data *data);
t_bool					path_exist(char *path);
t_bool					is_door(char c);
t_bool					is_wall_or_door(char c);
void					open_or_close_door(t_data *data);
t_bool					door_around(t_data *data, int *door_x, int *door_y);
void					free_texture(t_data *data, int nb);
int						handle_mouse(t_data *data);
int						handle_keypress(int keysym, t_data *data);
void					print_map(t_data *data);
void					print_textures(t_data *data);
void					print_rgb(t_data *data);
int						set_texture_path(char **texture, char *line, int start);
int						extract_t_path(char *line, t_data *data);
void					check_textures(t_data *data, char *line,
							int *texture_count);
int						extract_rgb(char *line, t_data *data);
int						parse_textures(t_data *data, char **line);
int						check_texture(char *line);
int						skip_empty_line(char **line, int fd);
t_bool					is_valid_rgb_value(int value);
t_bool					is_valid_rgb(char *str);
int						path_len(char *path);
int						skip_tex_type(char *line, int i, int size);
int						extract_line(char *line, t_data *data);
t_bool					is_wall_door_or_empty(char c);
void					toggle_mouse(t_data *data);
double					check_horizontal_lines(t_data *data, t_ray *ray);
double					check_vertical_lines(t_data *data, t_ray *ray);
void					find_door(t_data *data, t_ray *ray, double x, double y);
int						map_value_at(t_data *data, double x, double y);
int						get_good_door_color(t_data *data, float x, float y);

#endif
