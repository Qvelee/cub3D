# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nelisabe <nelisabe@student.21-school.ru    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/08/27 16:48:02 by nelisabe          #+#    #+#              #
#    Updated: 2020/09/03 16:14:27 by nelisabe         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =				cub3D

COMP =				clang

FLAGS =				-Wall -Wextra -Werror

HEADER = 			game/core/cub3D.h

PARS_HEADER = 		parser.h

CORE_SRC =			cub3D.c

PARS_SRC =			parser.c

PARS_UTIL_SRC =		params.c \
					map_solve.c

CORE_SRC_DIR =		game/core/

PARS_DIR =			game/parser/

PARS_UTIL_DIR =		game/parser/parser_ulils/

OBJ_CORE_DIR =		game/temp/game/core/

OBJ_PARS_DIR =		game/temp/game/parser/

OBJ_PARS_UTIL_DIR =	game/temp/game/parser/parser_utils/

OBJ =				$(addprefix $(OBJ_CORE_DIR), $(CORE_SRC:.c=.o))

PARS_OBJ =			$(addprefix $(OBJ_PARS_DIR), $(PARS_SRC:.c=.o))

PARS_UTIL_OBJ =		$(addprefix $(OBJ_PARS_UTIL_DIR), $(PARS_UTIL_SRC:.c=.o))

LIBUTILS =			-Lgame/utils/ -lutils

MAIN =				game/main.c

all: lib $(NAME)

#add flags!
lib:
	@$(MAKE) -C game/utils/

$(NAME): $(HEADER) $(OBJ) $(PARS_OBJ) $(PARS_UTIL_OBJ)
	@$(COMP) $(^:$(HEADER)=) $(MAIN) $(LIBUTILS) -o $@

$(addprefix $(OBJ_CORE_DIR), %.o): $(addprefix $(CORE_SRC_DIR), %.c)
	@$(COMP) -c $< -o $@

$(addprefix $(OBJ_PARS_DIR), %.o): $(addprefix $(PARS_DIR), %.c)
	@$(COMP) -c $< -o $@

$(addprefix $(OBJ_PARS_UTIL_DIR), %.o): $(addprefix $(PARS_UTIL_DIR), %.c)
	@$(COMP) -c $< -o $@

clean:
	@rm -rf $(OBJ)
	@rm -rf $(PARS_OBJ)
	@rm -rf $(PARS_UTIL_OBJ)
	@$(MAKE) clean -C game/utils/

fclean: clean
	@rm -rf $(NAME)
	@$(MAKE) fclean -C game/utils/

re: fclean all