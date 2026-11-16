# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bcaresme <bcaresme@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/10/20 13:52:12 by bcaresme          #+#    #+#              #
#    Updated: 2026/11/16 16:12:30 by bcaresme         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME := libft.a

SOURCES := ft_isalpha.c \
	ft_isdigit.c \
	ft_isalnum.c \
	ft_isascii.c \
	ft_isprint.c \
	ft_strlen.c \
	ft_memset.c \
	ft_bzero.c \
	ft_memcpy.c \
	ft_memmove.c \
	ft_strlcpy.c \
	ft_strlcat.c \
	ft_toupper.c \
	ft_tolower.c \
	ft_strchr.c \
	ft_strrchr.c \
	ft_strncmp.c \
	ft_memchr.c \
	ft_memcmp.c \
	ft_strnstr.c \
	ft_atoi.c \
	ft_calloc.c \
	ft_strdup.c \
	ft_substr.c \
	ft_strjoin.c \
	ft_strtrim.c \
	ft_split.c \
	ft_itoa.c \
	ft_strmapi.c \
	ft_striteri.c \
	ft_putchar_fd.c \
	ft_putstr_fd.c \
	ft_putendl_fd.c \
	ft_putnbr_fd.c \
	ft_lstnew.c \
	ft_lstadd_front.c \
	ft_lstsize.c \
	ft_lstlast.c \
	ft_lstadd_back.c \
	ft_lstdelone.c \
	ft_lstclear.c \
	ft_lstiter.c \
	ft_lstmap.c \
	ft_printf.c \
	ft_putnbr_hexa.c\
	ft_putnbr_len.c \
	ft_putptr_len.c \
	ft_putstr_len.c \
	ft_unsigned_putnbr_len.c

OBJ_DIR := obj/

OBJECTS = $(addprefix $(OBJ_DIR), $(SOURCES:.c=.o))

CFLAGS := -Wall -Wextra -Werror

all : $(NAME)

$(OBJ_DIR)%.o : %.c
	@cc $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	@mkdir $(OBJ_DIR)

$(NAME) : $(OBJ_DIR) $(OBJECTS)
	@ar rcs $(NAME) $(OBJECTS)
	@ranlib $(NAME)

clean :
	@rm -rf $(OBJECTS)
	@echo "\033[31;1m$(NAME) objects cleaned\033[0m"

fclean : clean
	@rm -rf $(NAME)
	@echo "\033[31;1m$(NAME) cleaned\033[0m"

re : fclean all

.PHONY : all clean fclean re
