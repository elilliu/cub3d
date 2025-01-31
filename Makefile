# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: elilliu <elilliu@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/24 16:43:24 by elilliu           #+#    #+#              #
#    Updated: 2025/01/31 18:22:35 by elilliu          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

GREEN			= \033[0;32m\e[1m
RESET			= \e[0m\033[0m

# NAME 			= cub3d

# INCLUDE 		= include/cub3d.h

# SRCS_DIR 		= srcs

# SRCS 			= main.c data_init.c utils.c verif_map.c

# LIBFT_DIR		= ./libft/
# LIBFT_PATH		= ./libft.a

# MLX_DIR			= mlx
# MLX_PATH		= mlx/libmlx.a

# OBJS_DIR		= objs

# OBJS			= ${addprefix ${OBJS_DIR}/, ${SRCS:.c=.o}}
# DEPS			= ${OBJS:.o=.d}

# CC = cc
# CFLAGS			= -Wall -Wextra -Werror -MMD -MP

# RM				= rm -rf

# ${OBJS_DIR}/%.o: ${SRCS_DIR}/%.c ${INCLUDE}
# 		@mkdir -p ${OBJS_DIR}
# 		@${CC} ${CFLAGS} -c $< -o $@ -g3

# ${NAME}: ${OBJS} ${LIBFT_PATH} ${MLX_PATH}
# 		@${CC} ${CFLAGS} ${OBJS} -o $@ -L${LIBFT_DIR} -lft ${MLX_PATH} -L${MLX_DIR} -lX11 -lXext -lmlx

# all: ${NAME}

# clean:
# 		@${RM} ${OBJS} ${DEPS} ${OBJS_DIR}

# fclean: clean
# 		@${RM} ${NAME}

# re: fclean all

# -include ${DEPS}

# .PHONY: all clean fclean re ${OBJS_DIR}INCS_PATH		= ./include

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
# SRC_DIR_B		= ./bonus
OBJ_DIR			= ./objs/
# OBJ_DIR_B		= ./objs_bonus/

SRCS			= srcs/main.c srcs/data_init.c srcs/utils.c srcs/verif_map.c\
				srcs/garbage_collector.c srcs/map_init.c srcs/fill_window.c\
				srcs/utils_gc.c srcs/move_player.c srcs/put_img_to_img.c\
				srcs/rotate_player.c
	
# SRCS_BONUS		= 

OBJS			= ${SRCS:${SRC_DIR}/%.c=${OBJ_DIR}%.o}
# OBJS_BONUS		= ${SRCS_BONUS:${SRC_DIR_B}/%.c=${OBJ_DIR_B}%.o}
# DEPS			= ${OBJS:.o=.d}

LIBFTDIR		= ./libft/
INCLUDE 		= -L./libft -lft

CC				= cc
LFLAGS 			+= -lbsd -lXext -lX11 -lm

${OBJ_DIR}%.o: ${SRC_DIR}/%.c ${HEADER}
	@mkdir -p ${OBJ_DIR}
	@${CC} -c $< -o $@

# ${OBJ_DIR_B}%.o: ${SRC_DIR_B}/%.c
# 	@mkdir -p ${OBJ_DIR_B}
# 	@${CC} -c $< -o $@

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
	@echo "${GREEN}MLX         : DONE!${RESET}"

# bonus: ${NAME_BONUS}

clean:
	@${RM} ${OBJ_DIR}
	@${MAKE} --no-print-directory -C ${LIBFTDIR} fclean
	@echo "${GREEN}Clean       : DONE!${RESET}"

fclean: clean
	@${RM} ${NAME}
	@${RM} $(OUTPUT_LEAKS)
	@echo "${GREEN}Full clean  : DONE!${RESET}"

re: fclean all

-include ${DEPS}

leaks: all
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./${NAME}

.PHONY: all clean fclean re show leaks bonus
