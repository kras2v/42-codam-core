NAME := libftprintf.a
LIBFT := ./libft/libft.a

SRCS := ft_printf.c \
		ft_printf_c.c \
		ft_printf_s.c \
		ft_printf_d.c \
		ft_printf_x.c \
		ft_printf_ux.c \
		ft_printf_p.c \
		ft_printf_u.c \
		ft_printf_i.c \
		ft_printf_percent.c \
		ft_convert_to_base.c \

OBJS := $(SRCS:%.c=%.o)
CFLAGS := -Wall -Werror -Wextra
CC := cc
AR := ar rcs

all : $(NAME)

$(NAME) : $(OBJS) $(LIBFT)
	mv $(LIBFT) $@
	$(AR) $@ $(OBJS)

$(LIBFT) :
	$(MAKE) -C ./libft

%.o : %.c
	$(CC) -c $(CFLAGS) $< -o $@

clean :
	rm -f $(OBJS)
	$(MAKE) -C ./libft clean

fclean : clean
	rm -f $(NAME)
	$(MAKE) -C ./libft fclean

re : fclean all

.PHONY : all clean fclean re