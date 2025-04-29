SRCS =		\
main.c \
validation.c \
utils.c \
helpers.c \

OBJS =		$(SRCS:.c=.o)

CC =		cc -g
CFLAGS =	-Wall -Wextra -Werror

NAME =		philo

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $@

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -rf $(OBJS)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re