# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: blinnea <blinnea@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/08/08 19:44:46 by blinnea           #+#    #+#              #
#    Updated: 2020/08/08 20:15:48 by blinnea          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# This is example. Customize it yourself.

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

CC = clang
CF = -Wall -Wextra -Werror -m64 -O3

NAME = corewar

# **************************************************************************** #
#                               ABBREVIATIONS                                  #
# **************************************************************************** #
LFT =		libft

# **************************************************************************** #
#                                 HEADERS                                      #
# **************************************************************************** #
LFT_H =		../$(LFT)/include/$(LFT).h
EX_H	=	include/example.h
# add your headers here

# **************************************************************************** #
#                                 FILENAMES                                    #
# **************************************************************************** #
EX_C	=	$(shell find src/example -name '*.c')
# add your source-files here

EX_O	=	$(addprefix obj/, $(EX_C:src/example/%.c=%.o))
# add your object-files here

# add YOUR_O here
ALLO = $(EX_O)

.PHONY: dir $(LFT) clean fclean re all

all: example # replace by your rule

# create obj directory
dir:
	@mkdir -p obj

# this is reference
example: $(LFT) $(EX_O)
	@$(CC) $(EX_O) -L../$(LFT) -lft -o $@
	@echo "\n> $(GREEN)example was created$(DEFAULT)"

# this is reference
obj/%.o: src/example/%.c $(EX_H) $(LFT_H) | dir
	@$(CC) $(CF) -c $< -o $@ -I ../$(LFT)/include -I include
	@echo "$(GREENB) $(DEFAULT)\c"

$(LFT):
	@make all -C ../libft

# Do not change it. It should work properly.
clean:
	@make fclean -C ../$(LFT)
	@rm -f $(ALLO)
	@rm -rf obj
	@echo "> $(YELLOW)$(NAME) clean$(DEFAULT)"

# Remove "@rm -f example" later
fclean: clean
	@rm -f example
	@rm -f $(NAME)
	@echo "> $(RED)$(NAME) fclean$(DEFAULT)"

re: fclean all
