# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nelbi <neleon@student.42.fr>               +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/24 16:43:24 by elilliu           #+#    #+#              #
#    Updated: 2025/01/27 15:11:31 by nelbi            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d

INCLUDE = include/cub3d.h

SRCS_DIR = srcs

SRCS = main.c data_init.c utils.c verif_map.c

LIBFT_DIR = libft
LIBFT_PATH = libft/libft.a

MLX_DIR = mlx
MLX_PATH = mlx/libmlx.a

OBJS_DIR = objs

OBJS = ${addprefix ${OBJS_DIR}/, ${SRCS:.c=.o}}

CC = cc
CFLAGS = -Wall -Wextra -Werror

RM				= rm -rf

${OBJS_DIR}/%.o: ${SRCS_DIR}/%.c ${INCLUDE}
		@mkdir -p ${OBJS_DIR}
		@${CC} ${CFLAGS} -c $< -o $@ -g3

${NAME}: ${OBJS} ${LIBFT_PATH} ${MLX_PATH}
		@${CC} ${CFLAGS} ${OBJS} -o $@ -L${LIBFT_DIR} -lft ${MLX_PATH} -L${MLX_DIR} -lX11 -lXext -lmlx

all: ${NAME}

clean:
		@${RM} ${OBJS} ${OBJS_DIR}

fclean: clean;
		@${RM} ${NAME}

re: fclean all

.PHONY: al clean fclean re ${OBJS_DIR}
