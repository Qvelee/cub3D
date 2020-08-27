# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nelisabe <nelisabe@student.21-school.ru    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/08/27 16:48:02 by nelisabe          #+#    #+#              #
#    Updated: 2020/08/27 20:57:10 by nelisabe         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

COMP = gcc

FLAGS = -Wall -Wextra -Werror

HEADER = 			cub3D.h

PARS_HEADER = 		parser.h

SRC =				cub3D.c

SRC_DIR =			game/core/

PARS_SRC =			parser.c \
					parser_utils\params.c

PARS_DIR =			game/parser/

OBJ_CORE_DIR =		game/temp/game/core

OBJ_PARS_DIR =		gmae/temp/dame/parser

OBJ =				$(addprefix $(OBJ_DIR), $(SRC:.c=.o))

PARS_OBJ =			$(addprefix $(OBJ_DIR), $(PARS_SRC:.c=.o))

LIBUTILS =			game/utils/libutils.a

all: $(NAME)

$(NAME): $(OBJ) $(PARS_OBJ) $(HEADER)
	$(COMP) main.c $(LIBUTILS) $(OBJ) $(PARS_OBJ) -o $@

$(addprefix $(OBJ_CORE_DIR), %.o): $(addprefix $(SRC_DIR), %.c)
	$(COMP) -c $< -o $@

$(addprefix $(OBJ_PARS_DIR), %.o): $(addprefix $(PARS_DIR), %.c)
	$(COMP) -c $< -o $@

clean:
	rm -rf $(OBJ_CORE_DIR)
	rm -rf $(OBJ_PARS_DIR)
	cd game/utils && make clean

fclean: clean
	rm -rf $(NAME)
	cd game/utils && make fclean

re: fclean all