NAME = push_swap

CC = cc
CFLAGS = -Wall -Werror -Wextra -g

SRC =	error_checks.c \
		ft_free.c \
		ft_split.c \
		listing_process.c \
		new_node_operations.c\
		push_swap.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME) : $(OBJ)
		$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean:
		rm -rf $(OBJ)

fclean: clean
		rm -rf $(NAME)

re: fclean all