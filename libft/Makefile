HEADERS := libft.h
SRCS := ft_isascii.c \
ft_strlcat.c \
ft_memchr.c \
ft_calloc.c \
ft_strrchr.c \
ft_isalpha.c \
ft_strlcpy.c \
ft_memset.c \
ft_memmove.c \
ft_strchr.c \
ft_strdup.c \
ft_strtrim.c \
ft_atoi.c \
ft_strlen.c \
ft_memcmp.c \
ft_toupper.c \
ft_memcpy.c \
ft_isprint.c \
ft_strnstr.c \
ft_substr.c \
ft_bzero.c \
ft_strncmp.c \
ft_tolower.c \
ft_strjoin.c \
ft_isalnum.c \
ft_isdigit.c \
ft_split.c \
ft_itoa.c \
ft_strmapi.c \
ft_striteri.c \
ft_putchar_fd.c \
ft_putstr_fd.c \
ft_putendl_fd.c \
ft_putnbr_fd.c


BONUS := ft_lstnew_bonus.c \
ft_lstadd_front_bonus.c \
ft_lstsize_bonus.c \
ft_lstlast_bonus.c \
ft_lstadd_back_bonus.c \
ft_lstdelone_bonus.c \
ft_lstclear_bonus.c \
ft_lstiter_bonus.c \
ft_lstmap_bonus.c

OBJS := $(SRCS:%.c=%.o)
BONUS_OBJS := $(BONUS:%.c=%.o)

NAME := libft.a
CFLAGS := -Wall -Wextra -Werror
ARFLAGS := -rsc
AR := ar
CC := cc

all : $(NAME)

$(NAME) : $(OBJS)
	$(AR) $(ARFLAGS) $@ $(OBJS)

bonus : $(BONUS_OBJS) $(OBJS)
	$(AR) $(ARFLAGS) $(NAME) $(OBJS) $(BONUS_OBJS)

%.o : %.c
	$(CC) -c $(CFLAGS) $< -o $@

clean :
	rm -f $(OBJS) $(BONUS_OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean $(NAME)

.PHONY : clean fclean all re bonus
