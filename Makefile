# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tvermeil <tvermeil@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/18 19:13:31 by tvermeil          #+#    #+#              #
#    Updated: 2016/03/18 15:14:01 by tvermeil         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem-in
CC = gcc
CPPFLAGS = -I include
CFLAGS = -Wall -Wextra -Werror
LDFLAGS = -L.
LDLIBS = -lft

SRC_PATH = src
INC_PATH = include
OBJ_PATH = obj/$(NAME)

MAKEFLAGS += --no-print-directory

SRC_NAME =	lem_in.c \
			ant.c \
			path.c \
			graph.c \
			room.c \
			tunnel.c \
			save_description.c

OBJ_NAME = $(SRC_NAME:.c=.o)

SRC = $(addprefix $(SRC_PATH)/,$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir -p $(OBJ_PATH)
	@$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@
	@echo -n .

all: $(NAME)

libft.a:
	@make -C libft all

$(NAME): libft.a $(OBJ)
	@$(CC) $(OBJ) $(LDFLAGS) $(LDLIBS) -o $(NAME)
	@echo " . \033[32m$(NAME)\033[0m done"

clean:
	@make -C libft clean
	@-rm -fv $(OBJ)
	@rmdir $(OBJ_PATH) obj 2> /dev/null || true

fclean: clean
	@make -C libft fclean
	@-rm -fv $(NAME)

re: fclean all

ac: all clean

norme:
	norminette $(LIBFT_SRC) $(SRC) include/*.h

.PHONY: all clean fclean re
