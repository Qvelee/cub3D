# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nelisabe <nelisabe@student.21-school.ru    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/05/20 23:10:45 by nelisabe          #+#    #+#              #
#    Updated: 2020/09/03 15:28:31 by nelisabe         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

FLAGS = -Wall -Wextra -Werror

HEADER = libft.h

SRC =	ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c \
		ft_memmove.c ft_memchr.c ft_memcmp.c ft_strlen.c \
		ft_strlcpy.c ft_strlcat.c ft_strchr.c ft_strrchr.c \
		ft_strnstr.c ft_strncmp.c ft_atoi.c ft_isalpha.c \
		ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
		ft_toupper.c ft_tolower.c ft_calloc.c ft_strdup.c \
		ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c \
		ft_itoa.c ft_strmapi.c ft_putchar_fd.c ft_putstr_fd.c \
		ft_putendl_fd.c ft_putnbr_fd.c

BNSRC = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c \
		ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c

OBJDIR = ../../temp/libft/

OBJECTS = $(addprefix $(OBJDIR), $(SRC:.c=.o))

BNSRCOBJ = $(addprefix $(OBJDIR), $(BNSRC:.c=.o))

ifdef ADD_BONUS
OBJECTS += $(BNSRCOBJ)
endif

all: $(NAME)

$(NAME): $(OBJECTS) $(HEADER)
	@ar rc $(NAME) $(HEADER) $(OBJECTS)
	@ar -s $(NAME)

bonus:
	@$(MAKE) ADD_BONUS=1 all

$(addprefix $(OBJDIR), %.o): %.c
	@gcc $(FLAGS) -c $< -o $@

clean:
	@/bin/rm -f $(OBJECTS) $(BNSRCOBJ)

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all

.PHONY: all, re, clean, fclean, bonus