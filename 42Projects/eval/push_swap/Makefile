NAME = push_swap

CFLAGS = -c -Werror -Wall -Wextra

SRCS = main_sort.c errors.c check_input.c helper.c push_swap.c sorting.c sorting_big.c operations/push.c operations/rotate.c operations/swap.c operations/reverse_rotate.c

OBJ = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	cc -o $(NAME) $(OBJ) libft/libft.a

%.o: %.c
	@make -C libft
	cc $(CFLAGS) -o $@ $<

clean:
	@make -C libft clean
	rm -f $(OBJ)

fclean: clean
	@make -C libft fclean
	rm -f $(NAME)

re: fclean all