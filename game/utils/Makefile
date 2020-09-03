# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nelisabe <nelisabe@student.21-school.ru    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/08/25 13:56:56 by nelisabe          #+#    #+#              #
#    Updated: 2020/09/03 16:06:58 by nelisabe         ###   ########.fr        #
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

libcomp:
	@$(MAKE) bonus -C ./libft

$(NAME): $(HEADER) libcomp $(OBJ)
	@cp ./libft/libft.a $(NAME)
	@ar -rcs $(NAME) $(OBJ)

$(addprefix $(OBJDIR), %.o): $(addprefix $(SRCDIR), %.c)
	@$(COMP) $(FLAGS) -c $< -o $@

clean:
	@rm -rf $(OBJ)
	@$(MAKE) clean -C ./libft

fclean: clean
	@rm -rf $(NAME)
	@$(MAKE) fclean -C ./libft

re: fclean all

.PHONY: all, re, clean, fclean
