# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bcaresme <bcaresme@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/11/13 10:49:59 by bcaresme          #+#    #+#              #
#    Updated: 2026/11/18 15:41:52 by bcaresme         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := push_swap

SUBDIR := libft/

LIB := libft/libft.a

SOURCES := parse.c \
	parse_option.c \
	parse_count.c \
	parse_fill.c \
	parse_number.c \
	main.c \
	push.c \
	rotate.c \
	swap.c \
	O_square.c \
	bucket_op.c \
	bucket_sort.c \
	bucket_utils.c \
	bench.c \
	bench_print.c \

OBJ_DIR := obj/

OBJECTS = $(addprefix $(OBJ_DIR), $(SOURCES:.c=.o))

CFLAGS := -Wall -Wextra -Werror -g

CC := cc

RM := rm -rf

all : $(NAME)

$(OBJ_DIR)%.o : %.c
	@echo "\033[34mCompiling $< -> $(notdir $@)\033[0m"
	@$(CC) $(CFLAGS) -c $< -o $@

$(LIB) : $(SUBDIR)
	@echo "\033[94;3mCompiling libft\033[0m"
	@make -C $< --no-print-directory

$(NAME) : $(LIB) $(OBJ_DIR) $(OBJECTS)
	@echo "\033[92;1mLinking $@\033[0m"
	@$(CC) $(CFLAGS) $(OBJECTS) $(LIB) -o $(NAME)

$(OBJ_DIR):
	@mkdir $(OBJ_DIR)

clean :
ifdef LIBFT
	@make clean -C $(SUBDIR) --no-print-directory
else
	@$(RM) $(OBJ_DIR)
	@echo "\033[31;1m$(OBJ_DIR) cleaned\033[0m"
endif

fclean : clean
ifdef LIBFT
	@$(RM) $(LIB)
	@echo "\033[31;1m$(notdir $(basename $(LIB))) cleaned\033[0m"
else
	@$(RM) $(NAME)
	@echo "\033[31;1m$(NAME) cleaned\033[0m"
endif

re : fclean all

.PHONY : all clean fclean re
