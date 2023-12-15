# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: edogarci <edogarci@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/10 13:43:51 by alvalope          #+#    #+#              #
#    Updated: 2023/12/12 19:39:44 by edogarci         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

MINILIBX_PATH = ./mlx

MINILIBX = $(MINILIBX_PATH)/libmlx.a

HEADER = error_handler.h \
		game_handler.h \
		general.h \
		itoa.h \
		load_map_utils.h \
		map_checks.h \
		map_handler.h \
		memory_handler.h \
		structs_definitions.h

CC = gcc

CFLAGS = -Wall -Wextra -Werror

FRAMEWORK = -framework OpenGL -framework AppKit

RM = rm -f

SRCS = error_handler.c \
		game_handler_01.c \
		game_handler_02.c \
		load_map_utils_01.c \
		load_map_utils_02.c \
		main.c \
		itoa.c \
		map_checks_01.c \
		map_checks_02.c \
		map_checks_03.c \
		map_checks_04.c \
		map_handler_01.c \
		map_handler_02.c \
		memory_handler.c

RM = rm -f

all: $(NAME)

$(NAME): $(SRCS) $(MINILIBX) $(HEADER)
	@echo "Compilando SO_LONG..."
	@$(CC) -g $(CFLAGS) $(SRCS) $(MINILIBX) $(FRAMEWORK) -o $(NAME)
	@echo "Terminado."

$(MINILIBX):
	@echo "Compilando MLX..."
	@make -C $(MINILIBX_PATH) all
	@echo "Terminado."

clean:
	@echo "Ejecutando CLEAN..."
	@make -C $(MINILIBX_PATH) clean
	@echo "Terminado."

fclean: clean
	@echo "Ejecutando FCLEAN..."
	@$(RM) $(NAME) $(SO_LONG)
	@echo "Terminado."

re: fclean all

.PHONY: all clean fclean re