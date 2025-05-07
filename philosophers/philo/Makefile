SRCS =		\
main.c \
validation.c \
helpers.c \
number_validation_utils.c \
string_utils.c \
philo_utils.c \
cleanup_utils.c \
fork_utils.c \
print_action_utils.c \
routine_helpers.c \
routine.c \
routine_utils.c \
routine_checker.c \
monitor_utils.c 

OBJS =		$(SRCS:.c=.o)

CC =		cc -g
CFLAGS =	-Wall -Wextra -Werror

NAME =		philo

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re