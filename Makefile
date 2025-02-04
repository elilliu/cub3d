# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: elilliu <elilliu@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/24 16:43:24 by elilliu           #+#    #+#              #
#    Updated: 2025/02/04 16:09:44 by elilliu          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

RESET		= \e[0m\033[0m
GREEN		= \033[0;32m\e[1m
YELLOW		= \033[1;33m
BLUE		= \033[1;34m
CYAN		= \033[1;36m

NAME 			= cub3d
HEADER	 		= include/cub3d.h
INC     		= /usr/include
LIBMLX  		= ./mlx/
NAME_MLX		= libmlx.a
CC				= cc
CFLAGS			= -Wall -Werror -Wextra -g3 -I$(INC) -I$(INCS_PATH) -MMD
LFLAGS			= -L$(LIBMLX) -lmlx
RM				= rm -rf

SRC_DIR			= ./srcs
OBJ_DIR			= ./objs/

SRCS			= srcs/main.c srcs/data_init.c srcs/utils.c srcs/verif_map.c\
				srcs/garbage_collector.c srcs/map_init.c srcs/fill_window.c\
				srcs/utils_gc.c srcs/move_player.c srcs/put_img_to_img.c\
				srcs/rotate_player.c srcs/parsing_error.c srcs/map_validation.c srcs/error.c\
				srcs/parsing.c srcs/parsing2.c srcs/parsing_utils.c

OBJS			= ${SRCS:${SRC_DIR}/%.c=${OBJ_DIR}%.o}
DEPS			= ${OBJS:.o=.d}

LIBFTDIR		= ./libft/
INCLUDE 		= -L./libft -lft

CC				= cc
LFLAGS 			+= -lbsd -lXext -lX11 -lm

${OBJ_DIR}%.o: ${SRC_DIR}/%.c
	@mkdir -p ${OBJ_DIR}
	@${CC} -c $< -o $@

.c.o:
	${CC} -c $< -o ${<:.c=.o}

${NAME}: ${OBJS} ${LIBMLX}${NAME_MLX}
	@${MAKE} --no-print-directory -C ${LIBFTDIR}
	@echo "${GREEN}Libft		: DONE!${RESET}"
	@${CC} ${CFLAGS} ${OBJS} ${LFLAGS} ${LIBFT} -o ${NAME} ${INCLUDE}
	@echo "${GREEN}Cub3d		: DONE!${RESET}"

all: ${NAME}

${LIBMLX}${NAME_MLX}:
	@${MAKE} --no-print-directory -C ${LIBMLX}
	@echo "${GREEN}Mlx		: DONE!${RESET}"

clean:
	@${RM} ${OBJ_DIR}
	@${MAKE} --no-print-directory -C ${LIBFTDIR} fclean
	@${MAKE} --no-print-directory -C ${LIBMLX} clean
	@echo "${GREEN}Clean		: DONE!${RESET}"

fclean: clean
	@${RM} ${NAME}
	@${RM} $(OUTPUT_LEAKS)
	@echo "${GREEN}Full clean	: DONE!${RESET}"

re: fclean all

# -include ${DEPS}

leaks: all
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./${NAME}

.PHONY: all clean fclean re leaks bonus
