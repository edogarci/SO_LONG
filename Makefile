# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: edogarci <edogarci@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/10 13:43:51 by alvalope          #+#    #+#              #
#    Updated: 2023/12/11 12:14:08 by edogarci         ###   ########.fr        #
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
		map_checks_04.c \
		map_handler_01.c \
		map_handler_02.c \
		memory_handler.c

OBJS = $(SRCS:.c=.o)

RM = rm -f

LIB = ar rcs

all: $(NAME)

$(OBJS): $(SRCS)
	@echo "COMPILANDO SO_LONG..."
	@$(CC) $(CFLAGS) -c $(SRCS)
	@echo "PROCESO TERMINADO."

$(NAME): $(OBJS) $(MINILIBX) $(HEADER)
	@echo "COMPILANDO SO_LONG..."
	@$(LIB) $(SO_LONG) $(OBJS)
#	$(CC) -g $(CFLAGS) $(SO_LONG) $(MINILIBX) $(FRAMEWORK) -o $(NAME)
	@$(CC) -g $(CFLAGS) memory_leaks.a $(SRCS) $(MINILIBX) $(FRAMEWORK) -o $(NAME)
	@echo "PROCESO TERMINADO."

$(MINILIBX):
	@make  -C $(MINILIBX_PATH) all

clean:
	@echo "BORRANDO ARCHIVOS GENERADOS EN LA COMPILACION..."
	@make -C $(MINILIBX_PATH) clean
	@$(RM) $(OBJS) $(BONUS_OBJS)
	@echo "PROCESO TERMINADO."

fclean: clean
	@echo "BORRANDO FICHEROS GENERADOS..."
	@$(RM) $(NAME) $(NAME_BONUS) $(SO_LONG) $(SO_LONG_BONUS)
	@echo "PROCESO TERMINADO."

re: fclean all

.PHONY: all clean fclean re