NAME = gekans.filler

# compiler
CC = gcc
FLAGS = -Wall -Wextra -Werror

# directories
SRC_DIR = sources/
INC_DIR = includes/

# files
# SRC_FILES = ft_printf.c
SRC_FILES = $(notdir $(wildcard $(SRC_DIR)*.c))
OBJ_FILES = $(SRC_FILES:%.c=%.o)
PRINTF = ft_printf/libftprintf.a

# full path
SRC = $(addprefix $(SRC_DIR), $(SRC_FILES))
OBJ = $(addprefix obj/, $(OBJ_FILES))
INCLUDES =	-I ft_printf/includes/ -I ft_printf/libft/includes \
			-I includes/

all: $(NAME)

$(NAME): $(OBJ)
	@$(MAKE) -C ft_printf/
	@$(CC) $(FLAGS) -o $(NAME) $(OBJ) $(PRINTF)
	@cp $(NAME) players/
	@echo "[INFO] Player gekans created."

$(OBJ): $(SRC)
	@mkdir -p obj/
	@$(CC) $(FLAGS) $(INCLUDES) -c $^
	@mv -f *.o obj/

clean:
	@$(MAKE) -C ft_printf/ clean
	@rm -rf obj
	@echo "[INFO] Objects removed."

fclean: clean
	@$(MAKE) -C ft_printf/ fclean
	@rm $(NAME)
	@echo "[INFO] Player gekans removed"

re: fclean all

.PHONY: all $(NAME) clean fclean re
