# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bineleon <neleon@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/24 16:43:24 by elilliu           #+#    #+#              #
#    Updated: 2025/01/31 18:07:11 by bineleon         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

RESET		= \e[0m\033[0m
GREEN		= \033[0;32m\e[1m
YELLOW		= \033[1;33m
BLUE		= \033[1;34m
CYAN		= \033[1;36m

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
# # HEADER	 		= include/cub3d.h
# INC     		= /usr/include
# LIBMLX  		= ./mlx/
# NAME_MLX		= libmlx.a
# CC				= cc
# CFLAGS			= -Wall -Werror -Wextra -g3 -I$(INC) -I$(INCS_PATH)
# LFLAGS			= -L$(LIBMLX) -lmlx
# RM				= rm -rf_linux

# SRC_DIR			= ./srcs
# OBJ_DIR			= ./objs/

# SRCS			= srcs/main.c srcs/data_init.c srcs/utils.c srcs/verif_map.c\
# 				srcs/garbage_collector.c srcs/map_init.c srcs/fill_window.c\
# 				srcs/utils_gc.c srcs/parsing.c srcs/parsing_utils.c

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

NAME    	= cub3D

SRCS_DIR	= ./srcs/
OBJS_DIR	= ./objs/

SRCS_FILE	= main.c data_init.c utils.c verif_map.c\
			  garbage_collector.c map_init.c fill_window.c\
			  utils_gc.c parsing.c parsing_utils.c move_player.c
SRC			= $(addprefix $(SRCS_DIR), $(SRCS_FILE))

OBJ			= $(patsubst $(SRCS_DIR)%, $(OBJS_DIR)%, $(SRC:.c=.o))
DEP			= $(OBJ:.o=.d)

LIBMLX		= ./mlx/
OMLX		= -I/usr/include -Imlx
CLIB		= -L${LIBMLX} -lmlx -lbsd -lXext -lX11 -lm
CLIB		+= -lz -Llibft -lft

CFLAGS		= -Wall -Wextra -Werror -g3 -Isrc -Ilibft -Imlx
# export		CFLAGS

CC			= cc
MAKE		= make
RM			= rm -rf


${OBJS_DIR}%.o: ${SRCS_DIR}%.c
	@mkdir -p ${OBJS_DIR}
	@echo "${YELLOW}Compiling	: $<${RESET}"
	@${CC} -c $< -o $@

${NAME}: $(OBJ)
	@echo "${CYAN}Building	: Libft...${RESET}"
	@${MAKE} --no-print-directory -C libft
	@echo "${GREEN}Libft		: DONE!${RESET}"

	@echo "${CYAN}Building	: MinilibX...${RESET}"
	@${MAKE} --no-print-directory -C mlx
	@echo "${GREEN}MinilibX	: DONE!${RESET}"

	@echo "${CYAN}Linking		: ${NAME}${RESET}"
	@${CC} ${CFLAGS} ${OBJ} ${OMLX} ${CLIB} -o ${NAME}
	@echo "${GREEN}Cub3D		: DONE!${RESET}"

all: ${NAME}

clean:
	@echo "${BLUE}Cleaning	: Objects & dependencies...${RESET}"
	@${RM} -r ${OBJS_DIR}
	@${MAKE} --no-print-directory clean -C mlx
	@${MAKE} --no-print-directory clean -C libft
	@echo "${GREEN}Clean		: DONE!${RESET}"

fclean: clean
	@${RM} ${NAME}
	@${MAKE} --no-print-directory fclean -C libft
	@echo "${GREEN}Full clean	: DONE!${RESET}"

re: fclean all

-include ${DEP}

.PHONY: all clean fclean re bonus
