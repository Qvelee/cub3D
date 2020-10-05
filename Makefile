# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nelisabe <nelisabe@student.21-school.ru    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/08/27 16:48:02 by nelisabe          #+#    #+#              #
#    Updated: 2020/10/05 18:38:46 by nelisabe         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =				cub3D

COMP =				clang

FLAGS =				-Wall -Wextra -Werror

HEADER = 			game/core/cub3d.h

PARS_HEADER = 		parser.h

#SRC DIRS

CORE_SRC_DIR =		game/core/

PARS_DIR =			game/parser/

PARS_UTIL_DIR =		game/parser/parser_ulils/

PARS_ERRORS_DIR =	game/parser/errors_managment/

#SRC

CORE_SRC =			cub3d.c \
					inits.c \
					init_sprites.c \
					handler.c \
					render.c \
					utils.c \
					errors_managment.c \
					player.c \
					map.c \
					make_frame.c \
					ray_casting.c \
					texture.c \
					background.c \
					sprites.c

PARS_SRC =			parser.c

PARS_UTIL_SRC =		params.c \
					map_solve.c

PARS_ERRORS_SRC =	free_struct.c \
					errors_parser.c \
					errors_params.c \
					errors_map_solve.c \
					errors_map_solve_2.c

#OBJ DIRS

OBJ_CORE_DIR =		game/temp/game/core/

OBJ_PARS_DIR =		game/temp/game/parser/

OBJ_PARS_UTIL_DIR =	game/temp/game/parser/parser_utils/

OBJ_PARS_ERR_DIR =	game/temp/game/parser/errors_managment/

#OBJ

OBJ =				$(addprefix $(OBJ_CORE_DIR), $(CORE_SRC:.c=.o))

PARS_OBJ =			$(addprefix $(OBJ_PARS_DIR), $(PARS_SRC:.c=.o))

PARS_UTIL_OBJ =		$(addprefix $(OBJ_PARS_UTIL_DIR), $(PARS_UTIL_SRC:.c=.o))

PARS_ERRORS_OBJ =	$(addprefix $(OBJ_PARS_ERR_DIR), $(PARS_ERRORS_SRC:.c=.o))

###

LIBUTILS =			-Lgame/utils/ -lutils -Lminilibx/ -lmlx -lXext -lX11 -lm

MAIN =				game/main.c

all: libutil minlib $(NAME)

#add flags!
libutil:
	@$(MAKE) -C game/utils/

minlib:
	@$(MAKE) -C minilibx/

$(NAME): $(HEADER) $(OBJ) $(PARS_ERRORS_OBJ) $(PARS_UTIL_OBJ) $(PARS_OBJ)
	@$(COMP) $(^:$(HEADER)=) $(MAIN) $(LIBUTILS) -o $@

$(addprefix $(OBJ_CORE_DIR), %.o): $(addprefix $(CORE_SRC_DIR), %.c)
	@$(COMP) -c $< -o $@

$(addprefix $(OBJ_PARS_DIR), %.o): $(addprefix $(PARS_DIR), %.c)
	@$(COMP) -c $< -o $@

$(addprefix $(OBJ_PARS_UTIL_DIR), %.o): $(addprefix $(PARS_UTIL_DIR), %.c)
	@$(COMP) -c $< -o $@

$(addprefix $(OBJ_PARS_ERR_DIR), %.o): $(addprefix $(PARS_ERRORS_DIR), %.c)
	@$(COMP) -c $< -o $@

clean:
	@rm -rf $(OBJ)
	@rm -rf $(PARS_OBJ)
	@rm -rf $(PARS_UTIL_OBJ)
	@rm -rf $(PARS_ERRORS_OBJ)
	@$(MAKE) clean -C minilibx/
	@$(MAKE) clean -C game/utils/

fclean: clean
	@rm -rf $(NAME)
	@$(MAKE) fclean -C game/utils/

re: fclean all