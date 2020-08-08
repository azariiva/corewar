# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lhitmonc <lhitmonc@42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/08/03 14:31:49 by lhitmonc          #+#    #+#              #
#    Updated: 2020/08/08 22:37:30 by lhitmonc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SHELL=/bin/zsh
# **************************************************************************** #
#                                 COLOURS                                      #
# **************************************************************************** #

DEFAULT = \033[0m
YELLOW = \033[1;33m
GREEN = \033[1;32m
RED = \033[1;31m
GREENB = \033[42m

# **************************************************************************** #
#                               COMPILER OPTIONS                               #
# **************************************************************************** #

CC = gcc
CF = #-Wall -Wextra -Werror -m64

NAME = visu_corewar
LFT = libft
SDL_LIB = ./SDL2/lib
SDL_INC = ./SDL2/include/SDL2

# **************************************************************************** #
#                                 HEADERS                                      #
# **************************************************************************** #

LFT_H =		$(LFT)/include/$(LFT).h
CRW_H =		include/visu_corewar.h

# **************************************************************************** #
#                                 FILENAMES                                    #
# **************************************************************************** #

FILES =		$(shell find src -name '*.c')
OFILES =	$(addprefix obj/, $(FILES:src/%.c=%.o))

.PHONY: $(LFT) clean fclean re all

all: $(NAME)
	@echo "\n> $(GREEN)$(NAME) created$(DEFAULT)"

obj:
	@mkdir -p obj

$(NAME): $(LFT) $(OFILES) $(LFT_H)
	@$(CC) $(CF) $(OFILES) -L$(LFT) -lft -L$(SDL_LIB) -lSDL2 -L$(SDL_LIB) -lSDL_TTF -o $(NAME)

obj/%.o: src/%.c $(LFT_H) $(CRW_H) | obj
	@$(CC) $(CF) -c $< -o $@ -I include -I $(LFT)/include -I $(SDL_INC)
	@echo "$(GREENB) $(DEFAULT)\c"

$(LFT):
	@make -C $(LFT)

clean:
	@make fclean -C libft
	@rm -f $(OFILES)
	@rm -fd obj
	@echo "> $(YELLOW)$(NAME) clean$(DEFAULT)"

fclean: clean
	@rm -f $(NAME)
	@echo "> $(RED)$(NAME) fclean$(DEFAULT)"

re: fclean all
