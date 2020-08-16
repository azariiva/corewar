
NAME = libft.a

CC = gcc
FLAGS = -Wall -Wextra -Werror
INCLUDES = -I$(HEADERS_DIR)

HEADERS_LIST = libft.h
HEADERS_DIR = includes/
HEADERS = $(addprefix $(HEADERS_DIR), $(HEADERS_LIST))

SOURCES_LIST = ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c \
               ft_memmove.c ft_memchr.c ft_memcmp.c ft_memalloc.c \
               ft_memdel.c \
               ft_strlen.c ft_strdup.c ft_strcpy.c ft_strncpy.c ft_strcat.c ft_strncat.c \
               ft_strlcat.c ft_strchr.c ft_strrchr.c ft_strstr.c ft_strnstr.c \
               ft_strcmp.c ft_strncmp.c ft_atoi.c \
               ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
               ft_toupper.c ft_tolower.c \
               ft_strnew.c ft_strdel.c ft_strclr.c ft_striter.c ft_striteri.c \
               ft_strmap.c ft_strmapi.c ft_strequ.c ft_strnequ.c ft_strsub.c ft_strjoin.c \
               ft_strsplit.c \
               ft_itoa.c \
               ft_putchar.c ft_putstr.c ft_putendl.c ft_putnbr.c ft_putchar_fd.c \
               ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
               ft_lstadd.c ft_lstdel.c ft_lstdelone.c ft_lstiter.c ft_lstmap.c ft_lstnew.c \
               ft_isupper.c ft_min.c ft_max.c ft_swap.c ft_abs.c ft_lltoa.c ft_llabs.c \
               ft_strup.c ft_ulltoa_base.c ft_cap_lftoa.c ft_cap_lftoa2.c get_next_line.c \
               ft_isint.c ft_isspace.c ft_isnbr.c ft_atol.c ft_numlen.c ft_arrlen.c \
			   ft_strrev.c
SOURCES_DIR = srcs/
SOURCES = $(addprefix $(SOURCES_DIR), $(SOURCES_LIST))

OBJECTS_LIST = $(patsubst %.c, %.o, $(SOURCES_LIST))
OBJECTS_DIR = objects/
OBJECTS = $(addprefix $(OBJECTS_DIR), $(OBJECTS_LIST))

# COLORS

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

all: $(NAME)

$(NAME): $(OBJECTS_DIR) $(OBJECTS)
	@ar rc $(NAME) $(OBJECTS)
	@echo "$(NAME): $(GREEN)object files were created$(RESET)" & echo
	@echo "$(NAME): $(GREEN)$(NAME) was created$(RESET)"

$(OBJECTS_DIR):
	@mkdir -p $(OBJECTS_DIR)

$(OBJECTS_DIR)%.o : $(SOURCES_DIR)%.c $(HEADERS)
	@$(CC) $(FLAGS) -c $(INCLUDES) $< -o $@
	@echo $(BNW) "$(GREEN)$(DLD)$(RESET)$(BNM)"

clean:
	@rm -rf $(OBJECTS_DIR)
	@echo "$(NAME): $(RED)object files were deleted$(RESET)"

fclean: clean
	@echo "$(NAME): $(RED)$(NAME) was deleted$(RESET)"
	@rm -rf $(NAME)$(EXE)

re:
	@$(MAKE) fclean
	@$(MAKE) all

.PHONY: all clean fclean re
