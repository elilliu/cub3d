# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bineleon <neleon@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/24 16:43:24 by elilliu           #+#    #+#              #
#    Updated: 2025/01/27 16:17:11 by bineleon         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

GREEN			= \033[0;32m\e[1m
RESET			= \e[0m\033[0m

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
DEPS = ${OBJS:.o=.d}

CC = cc
CFLAGS = -Wall -Wextra -Werror -MMD -MP

RM				= rm -rf

${OBJS_DIR}/%.o: ${SRCS_DIR}/%.c ${INCLUDE}
		@mkdir -p ${OBJS_DIR}
		@${CC} ${CFLAGS} -c $< -o $@ -g3

${NAME}: ${OBJS} ${LIBFT_PATH} ${MLX_PATH}
		@${CC} ${CFLAGS} ${OBJS} -o $@ -L${LIBFT_DIR} -lft ${MLX_PATH} -L${MLX_DIR} -lX11 -lXext -lmlx

all: ${NAME}

clean:
		@${RM} ${OBJS} ${DEPS} ${OBJS_DIR}

fclean: clean
		@${RM} ${NAME}

re: fclean all

-include ${DEPS}

.PHONY: all clean fclean re ${OBJS_DIR}
