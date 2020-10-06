# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: torange <@student.42.fr>                   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/20 14:53:53 by torange           #+#    #+#              #
#    Updated: 2020/08/19 17:34:59 by torange          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = visio
CC = gcc
FLAGS = -ggdb
LIBRARIES = -lft -L$(LIBFT_DIR) -lft -L$(FT_PRINTF_DIR) -lft -L$(SDL)
INCLUDES = -I $(HEADERS_DIR) -I $(LIBFT_HEADERS) -I $(FT_PRINTF_HEADERS) -I $(SDL_HEADERS)

SDL = $(SDL_DIR)lib/
SDL_FLAGS = -w -lSDL2 -lSDL2_ttf -lSDL2_image
SDL_DIR = SDL/
SDL_HEADERS = $(SDL_DIR)includes/

LIBFT = $(LIBFT_DIR)libft.a
LIBFT_DIR = libft/
LIBFT_HEADERS = $(LIBFT_DIR)includes/

FT_PRINTF = $(FT_PRINTF_DIR)libftprintf.a
FT_PRINTF_DIR = ft_printf/
FT_PRINTF_HEADERS = $(FT_PRINTF_DIR)includes/

HEADERS_LIST = visio.h
HEADERS_DIR = includes/
HEADERS = $(addprefix $(HEADERS_DIR), $(HEADERS_LIST))

SOURCES_LIST =	main.c \
				init.c \
				repaint.c \
				button.c \
				events.c
SOURCES_DIR = srcs/
SOURCES = $(addprefix $(SOURCES_DIR), $(SOURCES_LIST))

OBJECTS_LIST = $(patsubst %.c, %.o, $(SOURCES_LIST))
OBJECTS_DIR = objects/
OBJECTS = $(addprefix $(OBJECTS_DIR), $(OBJECTS_LIST))


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

all: $(LIBFT) $(FT_PRINTF) $(NAME)

$(NAME): $(OBJECTS_DIR) $(OBJECTS) Makefile
	@$(CC) $(FLAGS) $(INCLUDES) $(OBJECTS) $(FT_PRINTF) $(LIBRARIES) $(SDL_FLAGS) -o $(NAME)
	@echo "$(NAME): $(GREEN)$(NAME) was created$(RESET)" & echo

$(OBJECTS_DIR):
	@mkdir -p $(OBJECTS_DIR)

$(OBJECTS_DIR)%.o : $(SOURCES_DIR)%.c $(HEADERS)
	@$(CC) $(FLAGS) -c $(INCLUDES) $< -o $@
	@echo $(BNW) "$(GREEN)$(DLD)$(RESET)$(BNM)"

$(FT_PRINTF):
	@echo "$(FT_PRINTF): $(GREEN)Creating $(FT_PRINTF)...$(RESET)"
	@$(MAKE) -sC $(FT_PRINTF_DIR)

$(LIBFT):
	@echo "$(LIBFT): $(GREEN)Creating $(LIBFT)...$(RESET)"
	@$(MAKE) -sC $(LIBFT_DIR)

clean:
	@$(MAKE) -sC $(LIBFT_DIR) clean
	@$(MAKE) -sC $(FT_PRINTF_DIR) clean
	@rm -rf $(OBJECTS_DIR)
	@echo "$(NAME): $(RED)object files were deleted$(RESET)"

fclean: clean
	@rm -f $(LIBFT)
	@echo "libft.a: $(RED)$(LIBFT) was deleted$(RESET)"
	@rm -f $(FT_PRINTF)
	@echo "libftprintf.a: $(RED)$(FT_PRINTF) was deleted$(RESET)"
	@rm -f $(NAME)$(EXE)
	@echo "$(NAME): $(RED)$(NAME) was deleted$(RESET)"
re:
	@$(MAKE) fclean
	@$(MAKE) all

.PHONY: all clean fclean re
