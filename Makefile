# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: elilliu <elilliu@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/24 16:43:24 by elilliu           #+#    #+#              #
#    Updated: 2025/03/18 13:47:20 by elilliu          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

RESET				= \e[0m\033[0m
GREEN				= \033[0;32m\e[1m
YELLOW				= \033[1;33m
BLUE				= \033[1;34m
CYAN				= \033[1;36m

NAME 				= cub3d
NAME_BONUS 			= cub3d_bonus
INC     			= /usr/include
LIBMLX  			= ./mlx/
NAME_MLX			= libmlx.a
CC					= cc
CFLAGS				= -Wall -Werror -Wextra -g3 -I$(INC) -MMD
LFLAGS				= -L$(LIBMLX) -lmlx
RM						= rm -rf

PARSING_DIR			= parsing/
PARSING				= map_init.c map_validation.c parsing.c parsing2.c parsing_utils.c\
					parsing_error.c parsing_utils2.c parsing_textures.c parsing_utils3.c
SRCS				+= $(addprefix ${PARSING_DIR}, ${PARSING})

MAIN_DIR			= main/
MAIN				= main.c data_init.c init_textures.c
SRCS				+= $(addprefix ${MAIN_DIR}, ${MAIN})

MOVES_DIR			= moves/
MOVES				= move_player.c rotate_player.c hooks.c
SRCS				+= $(addprefix ${MOVES_DIR}, ${MOVES})

RAYCASTING_DIR		= raycasting/
RAYCASTING			= fill_window.c fill_window_utils.c put_walls.c check_lines.c
SRCS				+= $(addprefix ${RAYCASTING_DIR}, ${RAYCASTING})

RENDER_DIR			= render/
RENDER				= print_walls.c put_img_to_img.c
SRCS				+= $(addprefix ${RENDER_DIR}, ${RENDER})

UTILS_DIR			= utils/
UTILS				= utils.c garbage_collector.c utils_gc.c clean.c debug.c
SRCS				+= $(addprefix ${UTILS_DIR}, ${UTILS})

PARSING_B_DIR		= parsing_b/
PARSING_B			= map_init_bonus.c map_validation_bonus.c parsing_bonus.c parsing2_bonus.c parsing_utils_bonus.c\
					parsing_error_bonus.c parsing_utils2_bonus.c parsing_textures.c parsing_utils3.c
SRCS_B				+= $(addprefix ${PARSING_B_DIR}, ${PARSING_B})

MAIN_B_DIR			= main_b/
MAIN_B				= main_bonus.c data_init.c init_textures.c
SRCS_B				+= $(addprefix ${MAIN_B_DIR}, ${MAIN_B})

MOVES_B_DIR			= moves_b/
MOVES_B				= move_player.c rotate_player.c handle_mouse.c hooks.c
SRCS_B				+= $(addprefix ${MOVES_B_DIR}, ${MOVES_B})

RAYCASTING_B_DIR	= raycasting_b/
RAYCASTING_B		= fill_window.c fill_window_utils.c put_walls.c check_lines.c check_lines_utils.c
SRCS_B				+= $(addprefix ${RAYCASTING_B_DIR}, ${RAYCASTING_B})

RENDER_B_DIR		= render_b/
RENDER_B			= print_walls.c put_img_to_img.c
SRCS_B				+= $(addprefix ${RENDER_B_DIR}, ${RENDER_B})

UTILS_B_DIR			= utils_b/
UTILS_B				= utils.c garbage_collector.c utils_gc.c clean.c utils_bonus.c debug.c
SRCS_B				+= $(addprefix ${UTILS_B_DIR}, ${UTILS_B})

BONUS_B_DIR			= bonus_b/
BONUS_B				= door.c minimap.c minimap_utils.c
SRCS_B				+= $(addprefix ${BONUS_B_DIR}, ${BONUS_B})

SRC_DIR				= ./srcs
BONUS_DIR			= ./bonus
OBJ_DIR				= ./objs/
OBJ_DIR_B			= ./objs_b/

OBJS_FILES 			= ${SRCS:.c=.o}
OBJS_FILES_B		= ${SRCS_B:.c=.o}

OBJS				= ${addprefix ${OBJ_DIR}, ${OBJS_FILES}}
OBJS_B				= ${addprefix ${OBJ_DIR_B}, ${OBJS_FILES_B}}

DEPS				= ${OBJS:.o=.d}
DEPS_B				= ${OBJS_B:.o=.d}

LIBFTDIR			= ./libft/
INCLUDE 			= -L./libft -lft

CC					= cc
LFLAGS 				+= -lbsd -lXext -lX11 -lm

$(OBJ_DIR)%.o: $(SRC_DIR)/%.c
	@mkdir -p $(@D)
	@${CC} ${CFLAGS} -c $< -o $@

$(OBJ_DIR_B)%.o: $(BONUS_DIR)/%.c
	@mkdir -p $(@D)
	@${CC} ${CFLAGS} -c $< -o $@

${NAME}: ${OBJS} ${LIBMLX}${NAME_MLX}
	@${MAKE} --no-print-directory -C ${LIBFTDIR}
	@echo "${GREEN}Libft		: DONE!${RESET}"
	@${CC} ${CFLAGS} ${OBJS} ${LFLAGS} ${LIBFT} -o ${NAME} ${INCLUDE}
	@echo "${GREEN}Cub3d		: DONE!${RESET}"

all: ${NAME}

${LIBMLX}${NAME_MLX}:
	@${MAKE} --no-print-directory -C ${LIBMLX}
	@echo "${GREEN}Mlx		: DONE!${RESET}"

bonus: ${NAME_BONUS}

${NAME_BONUS}: ${OBJS_B} ${LIBMLX}${NAME_MLX}
	@${MAKE} --no-print-directory -C ${LIBFTDIR}
	@echo "${GREEN}Libft		: DONE!${RESET}"
	@${CC} ${CFLAGS} ${OBJS_B} ${LFLAGS} ${LIBFT} -o ${NAME_BONUS} ${INCLUDE}
	@echo "${GREEN}Bonus		: DONE!${RESET}"

-include ${DEPS}
-include ${DEPS_B}

clean:
	@${RM} ${OBJ_DIR}
	@${RM} ${OBJ_DIR_B}
	@${MAKE} --no-print-directory -C ${LIBFTDIR} fclean
	@${MAKE} --no-print-directory -C ${LIBMLX} clean
	@echo "${GREEN}Clean		: DONE!${RESET}"

fclean: clean
	@${RM} ${NAME}
	@${RM} ${NAME_BONUS}
	@echo "${GREEN}Full clean	: DONE!${RESET}"

re: fclean all

leaks: all
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./${NAME}

.PHONY: all clean fclean re leaks bonus
