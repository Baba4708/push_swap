# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bcaresme <bcaresme@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/11/13 10:49:59 by bcaresme          #+#    #+#              #
#    Updated: 2026/11/13 12:15:29 by bcaresme         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SUBDIR = libft/

LIB = libft/libft.a

SOURCES = parse.c \
	parse_option.c \
	parse_count.c \
	parse_fill.c \
	parse_number.c \
	main.c \
	push.c \
	rotate.c \
	swap.c \
	O_square.c

OBJECTS = $(SOURCES:.c=.o)

CFLAGS = -Wall -Wextra -Werror -g

CC = cc

all : $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(LIB) : $(SUBDIR)
	make -C $<

$(NAME) : $(OBJECTS) $(LIB)
	$(CC) $(CFLAGS) $(OBJECTS) $(LIB) -o $(NAME)

clean :
	rm -rf $(OBJECTS)

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY : all clean fclean re
