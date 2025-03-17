# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bineleon <neleon@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/24 16:43:24 by elilliu           #+#    #+#              #
#    Updated: 2025/03/14 21:20:33 by bineleon         ###   ########.fr        #
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

# SRCS				= minimap.c minimap_utils.c

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

# ${LIBMLX}${NAME_MLX}:
# 	@${MAKE} --no-print-directory -C ${LIBMLX}
# 	@echo "${GREEN}Mlx		: DONE!${RESET}"

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

# NAME 			= cub3d
# HEADER	 		= include/cub3d.h
# INC     		= /usr/include
# LIBMLX  		= ./mlx/
# NAME_MLX		= libmlx.a
# CC				= cc
# CFLAGS			= -Wall -Werror -Wextra -g3 -I$(INC) -I$(INCS_PATH) -MMD
# LFLAGS			= -L$(LIBMLX) -lmlx
# RM				= rm -rf

# SRC_DIR			= ./srcs
# # SRC_DIR_B		= ./bonus
# OBJ_DIR			= ./objs/
# # OBJ_DIR_B		= ./objs_bonus/

# SRCS			= srcs/main.c srcs/data_init.c srcs/utils.c srcs/verif_map.c\
# 				srcs/garbage_collector.c srcs/map_init.c srcs/fill_window.c\
# 				srcs/utils_gc.c srcs/move_player.c srcs/put_img_to_img.c\
# 				srcs/rotate_player.c

# # SRCS_BONUS		=

# OBJS			= ${SRCS:${SRC_DIR}/%.c=${OBJ_DIR}%.o}
# OBJS_BONUS		= ${SRCS_BONUS:${SRC_DIR_B}/%.c=${OBJ_DIR_B}%.o}
# DEPS			= ${OBJS:.o=.d}
# NAME 			= cub3d
# # HEADER	 		= include/cub3d.h
# INC     		= /usr/include
# LIBMLX  		= ./mlx/
# NAME_MLX		= libmlx.a
# CC				= cc
# CFLAGS			= -Wall -Werror -Wextra -g3 -I$(INC) -I$(INCS_PATH)
# LFLAGS			= -L$(LIBMLX) -lmlx
# # RM				= rm -rf_linux

# SRC_DIR			= ./srcs
# OBJ_DIR			= ./objs/

# SRCS			= srcs/main.c srcs/data_init.c srcs/utils.c srcs/verif_map.c\
# 				srcs/garbage_collector.c srcs/map_init.c srcs/fill_window.c\
# 				srcs/utils_gc.c srcs/move_player.c srcs/put_img_to_img.c\
# 				srcs/rotate_player.c srcs/parsing_error.c srcs/map_validation.c srcs/error.c\
# 				srcs/parsing.c srcs/parsing2.c srcs/parsing_utils.c

# OBJS			= ${SRCS:${SRC_DIR}/%.c=${OBJ_DIR}%.o}
# DEPS			= ${OBJS:.o=.d}

# LIBFTDIR		= ./libft/
# INCLUDE 		= -L./libft -lft

# CC				= cc
# LFLAGS 			+= -lbsd -lXext -lX11 -lm

# OBJS			= ${SRCS:${SRC_DIR}/%.c=${OBJ_DIR}%.o}
# # DEPS			= ${OBJS:.o=.d}

# LIBFTDIR		= ./libft/
# INCLUDE 		= -L./libft -lft

# CC				= cc
# LFLAGS 			+= -lbsd -lXext -lX11 -lm

# ${OBJ_DIR}%.o: ${SRC_DIR}/%.c
# 	@mkdir -p ${OBJ_DIR}
# 	@${CC} -c $< -o $@

# .c.o:
# 	${CC} -c $< -o ${<:.c=.o}

# ${NAME}: ${OBJS} ${LIBMLX}${NAME_MLX}
# 	@${MAKE} --no-print-directory -C ${LIBFTDIR}
# 	@echo "${GREEN}Libft		: DONE!${RESET}"
# 	@${CC} ${CFLAGS} ${OBJS} ${LFLAGS} ${LIBFT} -o ${NAME} ${INCLUDE}
# 	@echo "${GREEN}Cub3d		: DONE!${RESET}"

# all: ${NAME}

# ${LIBMLX}${NAME_MLX}:
# 	@${MAKE} --no-print-directory -C ${LIBMLX}
# 	@echo "${GREEN}Mlx		: DONE!${RESET}"

# clean:
# 	@${RM} ${OBJ_DIR}
# 	@${MAKE} --no-print-directory -C ${LIBFTDIR} fclean
# 	@${MAKE} --no-print-directory -C ${LIBMLX} clean
# 	@echo "${GREEN}Clean		: DONE!${RESET}"

# fclean: clean
# 	@${RM} ${NAME}
# 	@${RM} $(OUTPUT_LEAKS)
# 	@echo "${GREEN}Full clean	: DONE!${RESET}"

# re: fclean all

# # -include ${DEPS}

# leaks: all
# 	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./${NAME}

# .PHONY: all clean fclean re leaks bonus

# NAME    	= cub3d

# SRCS_DIR	= ./srcs/
# OBJS_DIR	= ./objs/

# SRCS_FILE	= main.c data_init.c utils.c verif_map.c\
# 			  garbage_collector.c map_init.c fill_window.c\
# 			  utils_gc.c parsing.c parsing_utils.c move_player.c\
# 				parsing_error.c map_validation.c error.c
# SRC			= $(addprefix $(SRCS_DIR), $(SRCS_FILE))

# OBJ			= $(patsubst $(SRCS_DIR)%, $(OBJS_DIR)%, $(SRC:.c=.o))
# DEP			= $(OBJ:.o=.d)

# LIBMLX		= ./mlx/
# OMLX		= -I/usr/include -Imlx
# CLIB		= -L${LIBMLX} -lmlx -lbsd -lXext -lX11 -lm
# CLIB		+= -lz -Llibft -lft

# CFLAGS		= -Wall -Wextra -Werror -g3 -Isrc -Ilibft -Imlx
# # export		CFLAGS

# CC			= cc
# MAKE		= make
# RM			= rm -rf


# ${OBJS_DIR}%.o: ${SRCS_DIR}%.c
# 	@mkdir -p ${OBJS_DIR}
# 	@echo "${YELLOW}Compiling	: $<${RESET}"
# 	@${CC} -c $< -o $@

# ${NAME}: $(OBJ)
# 	@echo "${CYAN}Building	: Libft...${RESET}"
# 	@${MAKE} --no-print-directory -C libft
# 	@echo "${GREEN}Libft		: DONE!${RESET}"

# 	@echo "${CYAN}Building	: MinilibX...${RESET}"
# 	@${MAKE} --no-print-directory -C mlx
# 	@echo "${GREEN}MinilibX	: DONE!${RESET}"

# 	@echo "${CYAN}Linking		: ${NAME}${RESET}"
# 	@${CC} ${CFLAGS} ${OBJ} ${OMLX} ${CLIB} -o ${NAME}
# 	@echo "${GREEN}Cub3D		: DONE!${RESET}"
# ${OBJ_DIR}%.o: ${SRC_DIR}/%.c
# 	@mkdir -p ${OBJ_DIR}
# 	@${CC} -c $< -o $@

# .c.o:
# 	${CC} -c $< -o ${<:.c=.o}

# ${NAME}: ${OBJS} ${LIBMLX}${NAME_MLX}
# 	@${MAKE} --no-print-directory -C ${LIBFTDIR}
# 	@echo "${GREEN}Libft		: DONE!${RESET}"
# 	@${CC} ${CFLAGS} ${OBJS} ${LFLAGS} ${LIBFT} -o ${NAME} ${INCLUDE}
# 	@echo "${GREEN}Cub3d		: DONE!${RESET}"

# all: ${NAME}

# clean:
# 	@echo "${BLUE}Cleaning	: Objects & dependencies...${RESET}"
# 	@${RM} -r ${OBJS_DIR}
# 	@${MAKE} --no-print-directory clean -C mlx
# 	@${MAKE} --no-print-directory clean -C libft
# 	@echo "${GREEN}Clean		: DONE!${RESET}"

# fclean: clean
# 	@${RM} ${NAME}
# 	@${MAKE} --no-print-directory fclean -C libft
# 	@echo "${GREEN}Full clean	: DONE!${RESET}"
# ${LIBMLX}${NAME_MLX}:
# 	@${MAKE} --no-print-directory -C ${LIBMLX}
# 	@echo "${GREEN}Mlx		: DONE!${RESET}"

# clean:
# 	@${RM} ${OBJ_DIR}
# 	@${MAKE} --no-print-directory -C ${LIBFTDIR} fclean
# 	@${MAKE} --no-print-directory -C ${LIBMLX} clean
# 	@echo "${GREEN}Clean		: DONE!${RESET}"

# fclean: clean
# 	@${RM} ${NAME}
# 	@${RM} $(OUTPUT_LEAKS)
# 	@echo "${GREEN}Full clean	: DONE!${RESET}"

# re: fclean all

# -include ${DEP}

# .PHONY: all clean fclean re bonus
# -include ${DEPS}

# leaks: all
# 	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./${NAME}

# .PHONY: all clean fclean re leaks bonus
