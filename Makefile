# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nelisabe <nelisabe@student.21-school.ru    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/08/27 16:48:02 by nelisabe          #+#    #+#              #
#    Updated: 2020/08/27 18:17:36 by nelisabe         ###   ########.fr        #
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

OBJ_DIR =			game/temp/game/

OBJ =				$(addprefix $(OBJ_DIR), $(SRC:.c=.o))

PARS_OBJ =			$(addprefix $(OBJ_DIR), $(PARS_SRC:.c=.o))

LIBUTILS =			game/utils/libutils.a

all: $(NAME)

$(NAME): $(OBJ) $(HEADER)
	$(COMP) main.c $(LIBUTILS) $(OBJ) $(PARS_OBJ) -o $@

$(addprefix $(OBJ_DIR), %.o): %.c


%.o: %.c


clean:

fclean: clean

re: fclean all