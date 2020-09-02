# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nelisabe <nelisabe@student.21-school.ru    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/08/25 13:56:56 by nelisabe          #+#    #+#              #
#    Updated: 2020/09/02 11:56:51 by nelisabe         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libutils.a

COMP = clang

HEADER = ./get_next_line/get_next_line.h

FLAGS = -Wall -Wextra -Werror -fPIC

SRC =	get_next_line.c \
		get_next_line_utils.c

SRCDIR = get_next_line/

OBJDIR = ../temp/get_next_line/

OBJ = $(addprefix $(OBJDIR), $(SRC:.c=.o))

all: $(NAME)

$(NAME): $(OBJ) $(HEADER)
	@cd ./libft && make bonus
	@cp ./libft/libft.a $(NAME)
	@ar -rcs $(NAME) $(HEADER) $(OBJ)

$(addprefix $(OBJDIR), %.o): $(addprefix $(SRCDIR), %.c)
	@$(COMP) $(FLAGS) -c $< -o $@

clean:
	@rm -rf $(OBJ)
	@cd libft && make clean

fclean: clean
	@rm -rf $(NAME)
	@cd libft && make fclean

re: fclean all

.PHONY: all, re, clean, fclean
