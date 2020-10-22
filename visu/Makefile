# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: blinnea <blinnea@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/20 14:53:53 by torange           #+#    #+#              #
#    Updated: 2020/10/22 16:39:54 by blinnea          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = visio
LFT = libft

CC = clang
CF = -ggdb

INCLUDES = -I include -I ../$(LFT)/include  -I Frameworks/SDL2_image.framework/Headers -I Frameworks/SDL2_ttf.framework/Headers -I Frameworks/SDL2.framework/Headers

VISIO_H = include/visio.h

SOURCES_LIST =	main.c \
				init.c \
				repaint.c \
				button.c \
				events.c

VISIO_C = $(addprefix src/, $(SOURCES_LIST))
ALL_O = $(VISIO_C:src/%.c=obj/%.o)


# COLORS

# ********************************* #
#          WIN/MAC OPTIONS          #
# ********************************* #

ifdef COMSPEC
  GREEN =
  RED =
  RESET =
  BNW = -n
  BNM =
  EXE = .exe
  DLD = *
else
  GREEN = \033[0;32m
  RED =  \033[0;31m
  RESET = \033[0m
  BNW =
  BNM = \c
  EXE =
  DLD = ▋
endif

all: $(LFT) $(NAME)

$(NAME): $(ALL_O) Makefile
	@$(CC) $(CF) $(ALL_O) -L../$(LFT) -lft -F"./Frameworks" -framework "SDL2" -framework "SDL2_ttf" -framework "SDL2_image" -o $(NAME)
	@echo "$(NAME): $(GREEN)$(NAME) was created$(RESET)" & echo

obj/%.o: src/%.c $(VISIO_H) | obj
	@$(CC) $(CF) -c $< -o $@ $(INCLUDES)
	@echo $(BNW) "$(GREEN)$(DLD)$(RESET)$(BNM)"

$(LFT):
	@make -C ../$(LFT)

obj:
	@mkdir -p obj

clean:
	@make -C ../$(LFT) fclean
	@rm -rf obj
	@echo "$(NAME): $(RED)object files were deleted$(RESET)"

fclean: clean
	@rm -f $(NAME)$(EXE)
	@echo "$(NAME): $(RED)$(NAME) was deleted$(RESET)"

re: fclean all

.PHONY: all clean fclean re $(LFT)
