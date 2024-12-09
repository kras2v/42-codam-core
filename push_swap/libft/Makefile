# Colors
YELLOW := \033[1;33m
GREEN := \033[1;32m
CYAN := \033[1;36m
RED := \033[1;31m
RESET := \033[0m

#HEADERS
HEADERS := libft.h

#SOURCES
SOURCES := ft_isascii.c \
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
	ft_strndup.c \
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
	ft_strcmp.c \
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

BONUS_SOURCES := ft_lstnew_bonus.c \
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
PRINTF_DIR := ./ft_printf
PRINTF := libftprintf.a

#OBJECTS
OBJS := $(SOURCES:%.c=%.o)
BONUS_OBJS := $(BONUS_SOURCES:%.c=%.o)

#FLAGS
CFLAGS := -Wall -Wextra -Werror
AR := ar rsc
CC := cc -c

#!DEBUG
DEBUG_NAME := libft_debug.a
DEBUG_OBJS := $(SOURCES:%.c=debug_%.o)
PRINTF_DEBUG := libftprintf_debug.a
DEBUG_FLAGS := $(CFLAGS) -g

#RULES
all : $(NAME)

$(NAME) : $(OBJS)
	@echo -e "$(CYAN)[INFO] Compiling $(NAME)...$(RESET)"
	@$(MAKE) -C $(PRINTF_DIR)
	@mv $(PRINTF_DIR)/$(PRINTF) $@
	@$(AR) $@ $(OBJS)
	@echo -e "$(GREEN)Libft library has been created$(RESET)"

bonus : $(BONUS_OBJS) $(OBJS)
	@echo -e "$(CYAN)[INFO] Adding bonus objects...$(RESET)"
	@$(AR) $(NAME) $(OBJS) $(BONUS_OBJS)
	@echo -e "$(GREEN)Libft with bonus part has been created$(RESET)"

%.o : %.c
	@echo -e "$(YELLOW)[BUILD] $< -> $@$(RESET)"
	@$(CC) $(CFLAGS) $< -o $@

#!DEBUG RULES
debug: $(DEBUG_NAME)

$(DEBUG_NAME) : $(DEBUG_OBJS)
	@echo -e "$(CYAN)[DEBUG] Compiling debug version...$(RESET)"
	@$(MAKE) -C $(PRINTF_DIR) debug
	@mv $(PRINTF_DIR)/$(PRINTF_DEBUG) $@
	@$(AR) $@ $(DEBUG_OBJS)
	@echo -e "$(GREEN)Debug version of libft.a has been created$(RESET)"

debug_%.o: %.c
	@echo -e "$(YELLOW)[DEBUG BUILD] $< -> $@$(RESET)"
	@$(CC) $(DEBUG_FLAGS) $< -o $@
#!------------

clean :
	@echo -e "$(RED)[CLEAN] Removing object files...$(RESET)"
	@rm -f $(OBJS) $(BONUS_OBJS) $(DEBUG_OBJS)
	@$(MAKE) -C $(PRINTF_DIR) clean

fclean : clean
	@echo -e "$(RED)[FCLEAN] Removing libraries...$(RESET)"
	@rm -f $(NAME) $(DEBUG_NAME)
	@$(MAKE) -C $(PRINTF_DIR) fclean

re : fclean $(NAME)

.PHONY : clean fclean all re bonus
