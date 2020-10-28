NAME		= libftprintf.a

INC_DIR		= ./includes
SRC_DIR		= ./src
OBJ_DIR		= ./obj

HEADERS		= ft_printf.h
SOURCES		= ft_printf.c \
	pr_putchar.c \
	pr_while.c \
	pr_read_specific.c \
	pr_read_flags.c \
	pr_output.c \
	pr_output_type_d.c \
	pr_putstr_reverse.c \
	pr_putstr_repeat.c \
	pr_output_type_u.c \
	pr_output_type_char.c \
	pr_output_type_s.c \
	pr_output_type_o.c \
	pr_output_type_x.c \
	pr_output_type_percent.c \
	pr_putstr.c \
	pr_putstr_precision.c \
	pr_output_type_f.c \
	pr_pow10.c \


LIBFT		= ./libft

CC			= gcc
WFLAGS		= -Wall -Wextra -Werror
IFLAGS		= -I$(INC_DIR) -I$(LIBFT)

INCS		= $(addprefix $(INC_DIR)/, $(HEADERS))
SRCS		= $(addprefix $(SRC_DIR)/, $(SOURCES))
OBJS		= $(addprefix $(OBJ_DIR)/, $(SOURCES:.c=.o))

all: $(NAME)

$(NAME): $(OBJS)
	$(MAKE) -C $(LIBFT)/
	cp $(LIBFT)/libft.a ./$(NAME)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(INCS) Makefile
	@mkdir -p ${@D}
	$(CC) $(WFLAGS) $(IFLAGS) -c $< -o $@

clean:
	$(MAKE) -C $(LIBFT)/ clean
	rm -rf $(OBJ_DIR)

fclean:
	$(MAKE) -C $(LIBFT)/ fclean
	rm -rf $(OBJ_DIR)
	rm -rf $(NAME)
	rm -rf test

re: fclean all

test: test.c $(NAME)
	$(CC) $(IFLAGS) $^ -L. -lftprintf -o $@

.PHONY: all clean fclean re
