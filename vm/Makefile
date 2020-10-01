# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: blinnea <blinnea@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/08/15 19:50:55 by blinnea           #+#    #+#              #
#    Updated: 2020/08/25 15:03:55 by blinnea          ###   ########.fr        #
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

CC = clang
CF = -Wall -Wextra -Werror -m64 -ggdb

NAME = corewar

# **************************************************************************** #
#                               ABBREVIATIONS                                  #
# **************************************************************************** #
LFT =		../libft/libft.a

# **************************************************************************** #
#                                 HEADERS                                      #
# **************************************************************************** #
LFT_H =		../libft/include/libft.h
OP_H =		include/op.h
VM_H =		include/vm.h

# **************************************************************************** #
#                                 FILENAMES                                    #
# **************************************************************************** #
# Someone told me that we can't use "shell find".
# TODO: Ask this in Slack.
VM_C	=	$(shell find src/vm -name '*.c')

VM_O	=	$(VM_C:src/vm/%.c=obj/%.o)

ALLO	=	$(VM_O)

.PHONY: dir $(LFT) clean fclean re all

all: $(NAME)

dir:
	@mkdir -p obj

$(NAME): obj/vm.o $(LFT) $(VM_O)
	@$(CC) $< $(VM_O) -L../libft -lft -o $@

obj/vm.o: src/vm.c $(VM_H) $(OP_H) $(LFT_H) | dir
	@$(CC) $(CF) -c $< -o $@ -I ../libft/include -I include
	@echo "$(GREENB) $(DEFAULT)\c"

obj/%.o: src/vm/%.c $(VM_H) $(OP_H) $(LFT_H) | dir
	@$(CC) $(CF) -c $< -o $@ -I ../libft/include -I include
	@echo "$(GREENB) $(DEFAULT)\c"

$(LFT):
	@make all -C ../libft

# Do not change it. It should work properly.
clean:
	@make fclean -C ../libft
	@rm -f $(ALLO)
	@rm -rf obj
	@echo "> $(YELLOW)$(NAME) clean$(DEFAULT)"

fclean: clean
	@rm -f $(NAME)
	@echo "> $(RED)$(NAME) fclean$(DEFAULT)"

re: fclean all
