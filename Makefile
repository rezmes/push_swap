NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS = main.c \
       stack_utils.c \
       swap_operations.c \
       target_utils.c \
       execute_moves.c \
       tiny_sort.c \
       turk_algorithm.c \
       parser.c \
       ft_split.c \
       ft_atol.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
