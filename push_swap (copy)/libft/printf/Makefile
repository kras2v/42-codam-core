#HEADERS
HEADERS := ft_printf.h

#SOURCES
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

#TARGET
NAME := libftprintf.a
LIBFT_DIR = ../
LIBFT := $(LIBFT_DIR)/libft.a

#OBJECTS
OBJS := $(SRCS:%.c=%.o)

#FLAGS
CFLAGS := -Wall -Werror -Wextra
AR := ar rcs
CC := cc -c

#!DEBUG
DEBUG_NAME := libftprintf_debug.a
LIBFT_DEBUG := $(LIBFT_DIR)/libft_debug.a
DEBUG_OBJS := $(SRCS:%.c=debug_%.o)
DEBUG_FLAGS := $(CFLAGS) -g

all : $(NAME)

$(NAME) : $(OBJS) $(LIBFT)
	cp $(LIBFT) $@
	$(AR) $@ $(OBJS)
#	echo "Printf library has been created"

%.o : %.c
	$(CC) $(CFLAGS) $< -o $@

$(LIBFT) :
	$(MAKE) -C $(LIBFT_DIR)

#!DEBUG RULES
debug: $(DEBUG_NAME)

$(DEBUG_NAME): $(DEBUG_OBJS) $(LIBFT_DEBUG)
	cp $(LIBFT_DEBUG) $@
	$(AR) $@ $(DEBUG_OBJS)
#	echo "Debug version of libftprintf.a has been created"

$(LIBFT_DEBUG) : 
	$(MAKE) -C $(LIBFT_DIR) debug

debug_%.o: %.c
	$(CC) $(DEBUG_FLAGS) $< -o $@
#!--------------------------------

clean :
	rm -f $(OBJS) $(DEBUG_OBJS) 
	$(MAKE) -C $(LIBFT_DIR) clean 

fclean : clean
	rm -f $(NAME) $(DEBUG_NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean 

re : fclean all

.PHONY : all clean fclean re