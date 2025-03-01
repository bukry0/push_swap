NAME = push_swap

CC = cc
CFLAGS = -Wall -Werror -Wextra

SRC =	error_checks.c \
		ft_atoi.c \
		ft_free.c \
		ft_split.c \
		listing_process.c \
		push_operations.c \
		push_swap.c \
		reverse_rotate_operations.c \
		rotate_operations.c \
		sorting.c \
		swap_operations.c \
		turkish_algorithm.c \
		turkish_algorithm_utils.c \
		turkish_algorithm_utils_a.c \
		turkish_algorithm_utils_b.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re