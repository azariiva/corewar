# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: blinnea <blinnea@student.42.fr>            +#+  +:+       +#+         #
#           1                                      +#+#+#+#+#+   +#+            #
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

NAME = asm

# **************************************************************************** #
#                               ABBREVIATIONS                                  #
# **************************************************************************** #
LFT =		libft

# **************************************************************************** #
#                                 HEADERS                                      #
# **************************************************************************** #
LFT_H =		../$(LFT)/include/$(LFT).h
ASM_H	=	include/asm.h
# add your headers here

# **************************************************************************** #
#                                 FILENAMES                                    #
# **************************************************************************** #
ASM_C	=	$(shell find src/parser -name '*.c')
# add your source-files here

ASM_O	=	$(addprefix obj/, $(ASM_C:src/parser/%.c=%.o))
# add your object-files here

# add YOUR_O here
ALLO = $(ASM_O)

.PHONY: dir $(LFT) clean fclean re all

all: $(NAME) # replace by your rule

# create obj directory
dir:
	@mkdir -p obj

# this is reference
$(NAME): $(LFT) $(ASM_O) obj/asm.o
	@$(CC) $(ASM_O) obj/asm.o -L../$(LFT) -lft -o $@
	@echo "\n> $(GREEN)asm was created$(DEFAULT)"

obj/asm.o: src/asm.c $(ASM_H) $(LFT_H)
	@$(CC) $(CF) -c $< -o $@ -I ../$(LFT)/include -I include
	@echo "$(GREENB) $(DEFAULT)\c"

# this is reference
obj/%.o: src/parser/%.c $(ASM_H) $(LFT_H) | dir
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

# Remove "@rm -f asm" later
fclean: clean
	@rm -f asm
	@rm -f $(NAME)
	@echo "> $(RED)$(NAME) fclean$(DEFAULT)"

re: fclean all
