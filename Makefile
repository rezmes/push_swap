NAME = push_swap
BONUS = checker
CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS = main.c \
	stack_utils_1.c \
	stack_utils_2.c \
	swap_a.c \
	swap_b.c \
	swap_both.c \
	target_utils.c \
	execute_moves.c \
	tiny_sort.c \
	turk_algorithm.c \
	parser.c \
	ft_split.c \
	ft_atol.c

BONUS_SRCS = checker.c \
	execute_instruction.c \
	stack_utils_1.c \
	stack_utils_2.c \
	swap_a.c \
	swap_b.c \
	swap_both.c \
	parser.c \
	ft_split.c \
	ft_atol.c \
	get_next_line_bonus.c \
	get_next_line_utils_bonus.c

OBJS = $(SRCS:.c=.o)
BONUS_OBJS = $(BONUS_SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

bonus: $(BONUS_OBJS)
	$(CC) $(CFLAGS) $(BONUS_OBJS) -o $(BONUS)

clean:
	rm -f $(OBJS) $(BONUS_OBJS)

fclean: clean
	rm -f $(NAME) $(BONUS)

re: fclean all

.PHONY: all clean fclean re bonus