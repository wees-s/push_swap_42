NAME = push_swap.a

PROGRAM_NAME = push_swap

CC = cc

CFLAGS = -Wall -Wextra -Werror

SRCS =	push_swap.c 	\
		list_utils.c	\
		error_free_all.c		\
		swap.c			\
		push.c			\
		rotate.c		\
		reverse_rotate.c	\
		stack_index.c	\
		order_list.c	\
		organizer.c

OBJS = $(SRCS:.c=.o)

RMAKE = make re

all: $(NAME)

$(NAME): $(OBJS)
	cd ./libft && $(RMAKE)
	@echo "============================="
	@echo "Copying libft.a --> push_swap.a"
	cp ./libft/libft.a $(NAME)
	@echo "============================="
	@echo "All $(OBJS) --> $@"
	ar rcs $@ $(OBJS)
	cc push_swap.c $(NAME) -o push_swap

%.o: %.c
	@echo "============================="
	$(CC) $(CFLAGS) -c $^

clean:
	@echo "============================="
	@echo "Cleaning all $(OBJS)"
	rm -f $(OBJS)
	cd ./libft && make clean

fclean: clean
	rm -f $(NAME)
	rm -f $(PROGRAM_NAME)
	cd ./libft && make fclean

re: fclean all

.PHONY: all clean fclean re

