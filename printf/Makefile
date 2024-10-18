NAME := libftprintf.a
LIBFT := libft/libft.a
ARFLAGS := -r -s -c
SRCS := ft_printf.c 
OBJS := $(SRCS:%.c=%.o)
CFLAGS := -Wall -Werror -Wextra

all : $(NAME)

$(NAME) : $(LIBFT) $(OBJS)
	ar $(ARFLAGS) $(NAME) $(OBJS)

#! to remove
ft_printf : $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $^ -L./libft -lft -o ft_printf 

$(LIBFT) :
	$(MAKE) -C ./libft

%.o : %.c
	$(CC) -c $(CFLAGS) $< -o $@

clean :
	rm -f $(OBJS)
	$(MAKE) -C ./libft clean

fclean : clean
	rm -f $(NAME) $(LIBFT)

re : fclean all

.PHONY : all clean fclean re