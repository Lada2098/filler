NAME = gekans.filler

# compiler
CC = gcc
FLAGS = -Wall -Wextra -Werror

# directories
SRC_DIR = ./sources
INC_DIR = ./includes
OBJ_DIR = ./obj

PRINTF_INC_DIR = ./ft_printf/includes/
LIBFT_INC_DIR = ./ft_printf/libft/includes/

# files
# SRC_FILES = ft_printf.c
SRC_FILES = $(notdir $(wildcard $(SRC_DIR)*.c))
OBJ_FILES = $(SRC_FILES:%.c=%.o)
PRINTF = ./ft_printf/libftprintf.a

SRC				=	check.c \
					initializers.c \
					main.c \
					make_move.c
SRCS			=	$(addprefix $(SRC_DIR)/, $(SRC))
OBJ				=	$(SRC:.c=.o)
OBJS			=	$(addprefix $(OBJ_DIR)/, $(OBJ))

INCS = $(INC_DIR)/filler.h

all: $(NAME)

$(NAME): $(PRINTF) $(INCS) $(OBJ_DIR) $(OBJS)
	$(CC) $(FLAGS) -o $(NAME) $(OBJS) $(PRINTF)
	cp $(NAME) players/
	@echo "[INFO] Player gekans created."

$(PRINTF):
	$(MAKE) -C ft_printf/

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o:	$(SRC_DIR)/%.c
	$(CC) $(FLAGS) -I $(INC_DIR) -I $(PRINTF_INC_DIR) -I $(LIBFT_INC_DIR) -o $@ -c $<

clean:
	$(MAKE) -C ft_printf/ clean
	rm -rf $(OBJ_DIR)
	@echo "[INFO] Objects removed."

fclean: clean
	$(MAKE) -C ft_printf/ fclean
	rm -f $(NAME)
	@echo "[INFO] Player gekans removed"

re: fclean all

.PHONY: all clean fclean re
