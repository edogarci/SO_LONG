# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: edogarci <edogarci@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/10 13:43:51 by alvalope          #+#    #+#              #
#    Updated: 2023/12/07 12:16:46 by edogarci         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SO_LONG = so_long.a

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
		map_handler_01.c \
		map_handler_02.c \
		memory_handler.c

OBJS = $(SRCS:.c=.o)

RM = rm -f

LIB = ar rcs

all: $(NAME)

$(OBJS): $(SRCS)
	@echo "Compilando so_long..."
	@$(CC) $(CFLAGS) -c $(SRCS)

$(NAME): $(OBJS) $(MINILIBX) $(HEADER)
	@echo "Generando libreria so_long..."
	@$(LIB) $(SO_LONG) $(OBJS)
#	$(CC) -g $(CFLAGS) $(SO_LONG) $(MINILIBX) $(FRAMEWORK) -o $(NAME)
	@$(CC) -g $(CFLAGS) $(SRCS) $(MINILIBX) $(FRAMEWORK) -o $(NAME)
	@echo "\033[0;32mPROCESO TERMINADO.\033[0m"

$(MINILIBX):
	@make  -C $(MINILIBX_PATH) all

clean:
	@echo "\033[0;31mBorrando archivos generados en la compilacion...\033[0m"
	@make -C $(MINILIBX_PATH) clean
	@$(RM) $(OBJS) $(BONUS_OBJS)

fclean: clean
	@echo "\033[0;31mBorrando librerias generadas...\033[0m"
	@$(RM) $(NAME) $(NAME_BONUS) $(SO_LONG) $(SO_LONG_BONUS)

re: fclean all

.PHONY: all clean fclean re