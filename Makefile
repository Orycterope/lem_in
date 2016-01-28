# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tvermeil <tvermeil@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/18 19:13:31 by tvermeil          #+#    #+#              #
#    Updated: 2016/01/28 23:43:25 by tvermeil         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem-in
CC = gcc
CFLAGS += -Wall -Wextra -Werror -I include
LDFLAGS += -L. -lft

SRCS =     	src/lem_in.c \
			src/ant.c \
			src/path.c \
			src/room.c \
			src/tunnel.c \
			src/save_description.c \
			src/get_next_line/get_next_line.c


LIBFT_SRCS =    src/libft/ft_memset.c \
		    	src/libft/ft_bzero.c \
   		    	src/libft/ft_memcpy.c \
   		    	src/libft/ft_memccpy.c \
   		    	src/libft/ft_memmove.c \
   		    	src/libft/ft_memchr.c \
   		    	src/libft/ft_memcmp.c \
   		    	src/libft/ft_strlen.c \
   		    	src/libft/ft_strdup.c \
   		    	src/libft/ft_strcpy.c \
   		    	src/libft/ft_strncpy.c \
   		    	src/libft/ft_strcat.c \
   		    	src/libft/ft_strncat.c \
   		    	src/libft/ft_strlcat.c \
   		    	src/libft/ft_strchr.c \
   		    	src/libft/ft_strrchr.c \
   		    	src/libft/ft_strstr.c \
   		    	src/libft/ft_strnstr.c \
   		    	src/libft/ft_strcmp.c \
   		    	src/libft/ft_strncmp.c \
   		    	src/libft/ft_atoi.c \
   		    	src/libft/ft_isalpha.c \
   		    	src/libft/ft_isdigit.c \
   		    	src/libft/ft_isalnum.c \
   		    	src/libft/ft_isascii.c \
   		    	src/libft/ft_isprint.c \
   		    	src/libft/ft_toupper.c \
   		    	src/libft/ft_tolower.c \
   		    	src/libft/ft_memalloc.c \
   		    	src/libft/ft_memdel.c \
   		    	src/libft/ft_strnew.c \
   		    	src/libft/ft_strdel.c \
   		    	src/libft/ft_strclr.c \
   		    	src/libft/ft_striter.c \
   		    	src/libft/ft_striteri.c \
   		    	src/libft/ft_strmap.c \
   		    	src/libft/ft_strmapi.c \
   		    	src/libft/ft_strequ.c \
   		    	src/libft/ft_strnequ.c \
   		    	src/libft/ft_strsub.c \
   		    	src/libft/ft_strjoin.c \
   		    	src/libft/ft_strjoin_free.c \
   		    	src/libft/ft_strtrim.c \
   		    	src/libft/ft_strsplit.c \
   		    	src/libft/ft_itoa.c \
   		    	src/libft/ft_putchar.c \
   		    	src/libft/ft_putstr.c \
   		    	src/libft/ft_putendl.c \
   		    	src/libft/ft_putnbr.c \
   		    	src/libft/ft_putchar_fd.c \
   		    	src/libft/ft_putstr_fd.c \
   		    	src/libft/ft_putendl_fd.c \
   		    	src/libft/ft_putnbr_fd.c \
   		    	src/libft/ft_lstnew.c \
   		    	src/libft/ft_lstdelone.c \
   		    	src/libft/ft_lstdel.c \
   		    	src/libft/ft_lstadd.c \
   		    	src/libft/ft_lstiter.c \
   		    	src/libft/ft_lstmap.c \

OBJS = $(SRCS:.c=.o)

LIBFT_OBJS = $(LIBFT_SRCS:.c=.o)

all: $(NAME)

libft.a: $(LIBFT_OBJS)
	ar rcs libft.a $(LIBFT_OBJS)

$(NAME): libft.a $(OBJS)
	gcc $(OBJS) $(LDFLAGS) -o $(NAME)

clean:
	-rm -f $(OBJS) $(LIBFT_OBJS)

fclean: clean
	-rm -f $(NAME) libft.a

re: fclean all

ac: all clean

.PHONY: all clean fclean re
