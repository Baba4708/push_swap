# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bcaresme <bcaresme@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/11/13 10:49:59 by bcaresme          #+#    #+#              #
#    Updated: 2026/11/25 12:19:46 by bcaresme         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ifndef BONUS
	NAME := push_swap
	OBJ_DIR := obj/
else
	NAME := checker
	OBJ_DIR := bonus_obj/
endif

SUBDIR := libft/

LIB := $(addprefix $(SUBDIR), libft.a)

SOURCES = push.c \
	rotate.c \
	swap.c \
	parse_number.c \
	parse_utils.c \
	compute_disorder.c

INCLUDES = push_swap_utils.h

ifndef BONUS
	SOURCES += parse.c \
		parse_option.c \
		parse_count.c \
		parse_fill.c \
		main.c \
		insertion_sort.c \
		bucket_op.c \
		bucket_sort.c \
		bucket_utils.c \
		bench.c \
		bench_print.c \
		radix_sort.c \
		radix_utils.c \
		adaptive_sort.c

	INCLUDES += push_swap.h
else
	SOURCES += bonus_main.c \
		bonus_parse.c \
		bonus_checker.c \
		bonus_get_next_line.c \
		bonus_get_next_line_utils.c

	INCLUDEs += bonus_push_swap.h \
		bonus_get_next_line.h
endif

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
	@echo -e '\033[1;93m     /\_/\  (\n    ( ^.^ ) _)\n      \"/  (\n    ( | | )\n   (__d b__)\n$(NAME) ready !\033[0m'

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
