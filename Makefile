# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nelisabe <nelisabe@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/08/27 16:48:02 by nelisabe          #+#    #+#              #
#    Updated: 2020/10/24 16:07:46 by nelisabe         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MAKEFLAGS =			--no-print-directory

NAME =				cub3D

COMP =				clang

FLAGS =				-Wall -Wextra -Werror

HEADER = 			./game/core/cub3d.h

PARS_HEADER = 		parser.h

#SRC DIRS

CORE_SRC_DIR =		./game/core/

CORE_INIT_DIR =		./game/core/init_functions/

CORE_ERR_DIR =		./game/core/errors_managment/

PARS_DIR =			./game/parser/

PARS_UTIL_DIR =		./game/parser/parser_ulils/

PARS_ERRORS_DIR =	./game/parser/errors_managment/

#SRC

CORE_SRC =			cub3d.c \
					handler.c \
					render.c \
					utils.c \
					player.c \
					minimap.c \
					map_treatment.c \
					make_frame.c \
					walls_treatment.c \
					sprites_treatment.c \
					ray_casting.c \
					texture.c \
					background.c \
					standart_background.c \
					draw_sprite.c

CORE_INIT =			inits.c \
					init_pointers.c \
					init_sprites.c \
					init_utils.c \
					init_basic.c \
					init_ghost.c \
					init_devil.c \
					init_fire.c \
					init_barrel.c \
					init_pedestal.c \
					init_skull.c

CORE_ERR =			errors_managment.c \
					errors_inits.c \
					errors_memory.c

PARS_SRC =			parser.c

PARS_UTIL_SRC =		params.c \
					map_solve.c

PARS_ERRORS_SRC =	errors_utils.c \
					errors_parser.c \
					errors_params.c \
					errors_map_solve.c \
					errors_map_solve_2.c

#OBJ DIRS

OBJ_CORE_DIR =		./game/temp/game/core/

OBJ_CORE_INIT_DIR =	./game/temp/game/core/init_functions/

OBJ_CORE_ERR_DIR =	./game/temp/game/core/errors_managment/

OBJ_PARS_DIR =		./game/temp/game/parser/

OBJ_PARS_UTIL_DIR =	./game/temp/game/parser/parser_utils/

OBJ_PARS_ERR_DIR =	./game/temp/game/parser/errors_managment/

#OBJ

OBJ =				$(addprefix $(OBJ_CORE_DIR), $(CORE_SRC:.c=.o))

INIT_OBJ =			$(addprefix $(OBJ_CORE_INIT_DIR), $(CORE_INIT:.c=.o))

ERR_OBJ =			$(addprefix $(OBJ_CORE_ERR_DIR), $(CORE_ERR:.c=.o))

PARS_OBJ =			$(addprefix $(OBJ_PARS_DIR), $(PARS_SRC:.c=.o))

PARS_UTIL_OBJ =		$(addprefix $(OBJ_PARS_UTIL_DIR), $(PARS_UTIL_SRC:.c=.o))

PARS_ERRORS_OBJ =	$(addprefix $(OBJ_PARS_ERR_DIR), $(PARS_ERRORS_SRC:.c=.o))

###

LIBUTILS =			-Lgame/utils/ -lutils -Lmlx/ -lmlx -lXext -lX11 -lm

MAIN =				./game/main.c

BONUS_OFF =			./scripts/bonus_off.sh

BONUS_ON =			./scripts/bonus_on.sh

all: run_script crtmpdirs libutil minlib $(NAME)

ifdef ADD_BONUS
SCRIPT = $(BONUS_ON)
endif

ifndef ADD_BONUS
SCRIPT = $(BONUS_OFF)
endif

run_script:
	@$(SCRIPT)

crtmpdirs:
	@mkdir -p $(OBJ_CORE_DIR) $(OBJ_PARS_DIR) $(OBJ_PARS_UTIL_DIR) $(OBJ_PARS_ERR_DIR) \
		$(OBJ_CORE_INIT_DIR) $(OBJ_CORE_ERR_DIR)

libutil:
	@$(MAKE) -C game/utils/

minlib:
	@$(MAKE) -C mlx/

$(NAME): $(OBJ) $(INIT_OBJ) $(ERR_OBJ) $(PARS_ERRORS_OBJ) $(PARS_UTIL_OBJ) $(PARS_OBJ) $(MAIN)
	@$(COMP) $^ $(LIBUTILS) -g $(FLAGS) -o $@
	@echo -e "\033[1m\033[32m$(NAME) created!\033[0m"

$(addprefix $(OBJ_CORE_DIR), %.o): $(addprefix $(CORE_SRC_DIR), %.c) $(HEADER)
	@echo -e "\033[36mCompiling $< ..."
	@$(COMP) $(FLAGS) -c $< -o $@

$(addprefix $(OBJ_CORE_INIT_DIR), %.o): $(addprefix $(CORE_INIT_DIR), %.c) $(HEADER)
	@echo -e "\033[36mCompiling $< ..."
	@$(COMP) $(FLAGS) -c $< -o $@

$(addprefix $(OBJ_CORE_ERR_DIR), %.o): $(addprefix $(CORE_ERR_DIR), %.c) $(HEADER)
	@echo -e "\033[36mCompiling $< ..."
	@$(COMP) $(FLAGS) -c $< -o $@

$(addprefix $(OBJ_PARS_DIR), %.o): $(addprefix $(PARS_DIR), %.c) $(HEADER)
	@echo -e "\033[36mCompiling $< ..."
	@$(COMP) $(FLAGS) -c $< -o $@

$(addprefix $(OBJ_PARS_UTIL_DIR), %.o): $(addprefix $(PARS_UTIL_DIR), %.c) $(HEADER)
	@echo -e "\033[36mCompiling $< ..."
	@$(COMP) $(FLAGS) -c $< -o $@

$(addprefix $(OBJ_PARS_ERR_DIR), %.o): $(addprefix $(PARS_ERRORS_DIR), %.c) $(HEADER)
	@echo -e "\033[36mCompiling $< ..."
	@$(COMP) $(FLAGS) -c $< -o $@

bonus:
	@$(MAKE) ADD_BONUS=1 all;

clean:
	@echo -e "\033[31mDeleting...\033[0m"
	@rm -rf $(OBJ)
	@rm -rf $(PARS_OBJ)
	@rm -rf $(PARS_UTIL_OBJ)
	@rm -rf $(PARS_ERRORS_OBJ)
	@rm -rf $(INIT_OBJ)	
	@rm -rf $(ERR_OBJ)
	@rm	-rf sshot.bmp
	@$(MAKE) clean -C mlx/
	@$(MAKE) clean -C game/utils/
	@echo -e "\033[31m\033[1mObject files deleted!\033[0m\033[31m\033[0m"

fclean: clean
	@rm -rf $(NAME)
	@$(MAKE) fclean -C game/utils/
	@echo -e "\033[31m\033[1m$(NAME), libutils.a, etc. files deleted!\033[0m"

re: fclean all

.PHONY: all, re, clean, fclean, bonus, run_script, crtmpdirs, libutil, minlib
	