#HEADERS
HEADERS := libft.h

#SOURCES
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
ft_atol.c \
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

#TARGET
NAME := libft.a

#OBJECTS
OBJS := $(SRCS:%.c=%.o)
BONUS_OBJS := $(BONUS:%.c=%.o)

#FLAGS
CFLAGS := -Wall -Wextra -Werror
AR := ar rsc
CC := cc -c

#!DEBUG
DEBUG_NAME := libft_debug.a
DEBUG_OBJS := $(SRCS:%.c=debug_%.o)
DEBUG_FLAGS := $(CFLAGS) -g

#RULES
all : $(NAME)

$(NAME) : $(OBJS)
	@$(AR) $@ $(OBJS)
#	@echo "Libft library has been created"

bonus : $(BONUS_OBJS) $(OBJS)
	@$(AR) $(NAME) $(OBJS) $(BONUS_OBJS)
#	@echo "Libft with bonus part has been created"

%.o : %.c
	@$(CC) $(CFLAGS) $< -o $@

#!DEBUG RULES
debug: $(DEBUG_NAME)

$(DEBUG_NAME) : $(DEBUG_OBJS)
	@$(AR) $@ $(DEBUG_OBJS)
#	@echo "Debug version of libft.a has been created"

debug_%.o: %.c
	@$(CC) $(DEBUG_FLAGS) $< -o $@
#!------------

clean :
	@rm -f $(OBJS) $(BONUS_OBJS) $(DEBUG_OBJS)

fclean : clean
	@rm -f $(NAME) $(DEBUG_NAME)

re : fclean $(NAME)

.PHONY : clean fclean all re bonus
