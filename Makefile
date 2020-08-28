# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nelisabe <nelisabe@student.21-school.ru    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/08/27 16:48:02 by nelisabe          #+#    #+#              #
#    Updated: 2020/08/28 18:17:40 by nelisabe         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =				cub3D

COMP =				gcc

FLAGS =				-Wall -Wextra -Werror

HEADER = 			cub3D.h

PARS_HEADER = 		parser.h

CORE_SRC =			cub3D.c

PARS_SRC =			parser.c

PARS_UTIL_SRC =		params.c

CORE_SRC_DIR =		game/core/

PARS_DIR =			game/parser/

PARS_UTIL_DIR =		game/parser/parser_utils/

OBJ_CORE_DIR =		game/temp/game/core/

OBJ_PARS_DIR =		game/temp/game/parser/

OBJ_PARS_UTIL_DIR =	game/temp/game/parser/parser_utils/

OBJ =				$(addprefix $(OBJ_CORE_DIR), $(CORE_SRC:.c=.o))

PARS_OBJ =			$(addprefix $(OBJ_PARS_DIR), $(PARS_SRC:.c=.o))

PARS_UTIL_OBJ =		$(addprefix $(OBJ_PARS_UTIL_DIR), $(PARS_UTIL_SRC:.c=.o))

LIBUTILS =			game/utils/libutils.a

MAIN =				game/main.c

all: $(NAME)

#add flags!
$(NAME): $(OBJ) $(PARS_OBJ) $(PARS_UTIL_OBJ) $(HEADER)
	$(COMP) $(MAIN) $(LIBUTILS) $(OBJ) $(PARS_OBJ) -o $@

$(addprefix $(OBJ_CORE_DIR), %.o): $(addprefix $(CORE_SRC_DIR), %.c)
	$(COMP) -c $< -o $@

$(addprefix $(OBJ_PARS_DIR), %.o): $(addprefix $(PARS_DIR), %.c)
	$(COMP) -c $< -o $@

$(addprefix $(OBJ_PARS_UTIL_DIR), %.o): $(addprefix $(addprefix $(PARS_UTIL_DIR), parser_utils/), %.c)
	$(COMP) -c $< -o $@

clean:
	rm -rf $(OBJ_CORE_DIR)
	rm -rf $(OBJ_PARS_DIR)
	rm -rf $(OBJ_PARS_UTIL_DIR)
	cd game/utils/ && make clean

fclean: clean
	rm -rf $(NAME)
	cd game/utils/ && make fclean

re: fclean all