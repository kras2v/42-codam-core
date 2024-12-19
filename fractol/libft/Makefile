# Colors
YELLOW	:= \033[1;33m
GREEN	:= \033[1;32m
CYAN	:= \033[1;36m
RED		:= \033[1;31m
RESET	:= \033[0m

#HEADERS
HEADERS	:= libft.h

#SOURCES
SOURCES	:= ft_isascii.c \
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
			ft_putnbr_fd.c \
			ft_lstnew_bonus.c \
			ft_lstadd_front_bonus.c \
			ft_lstsize_bonus.c \
			ft_lstlast_bonus.c \
			ft_lstadd_back_bonus.c \
			ft_lstdelone_bonus.c \
			ft_lstclear_bonus.c \
			ft_lstiter_bonus.c \
			ft_lstmap_bonus.c

#TARGET
NAME		:= libft.a
PRINTF_DIR	:= ./ft_printf
PRINTF		:= libftprintf.a

#OBJECTS
OBJS		:= $(SOURCES:%.c=%.o)

#FLAGS
CFLAGS		:= -Wall -Wextra -Werror
AR			:= ar rsc
CC			:= cc -c

#RULES
all : $(NAME)

$(NAME) : $(OBJS)
	@echo -e "$(CYAN)[INFO] Compiling $(NAME)...$(RESET)"
	@$(MAKE) -C $(PRINTF_DIR)
	@mv $(PRINTF_DIR)/$(PRINTF) $@
	@$(AR) $@ $(OBJS)
	@echo -e "$(GREEN)Libft library has been created$(RESET)"

%.o : %.c
	@echo -e "$(YELLOW)[BUILD] $< -> $@$(RESET)"
	@$(CC) $(CFLAGS) $< -o $@

clean :
	@echo -e "$(RED)[CLEAN] Removing object files...$(RESET)"
	@rm -f $(OBJS)
	@$(MAKE) -C $(PRINTF_DIR) clean

fclean : clean
	@echo -e "$(RED)[FCLEAN] Removing libraries...$(RESET)"
	@rm -f $(NAME)
	@$(MAKE) -C $(PRINTF_DIR) fclean

re : fclean $(NAME)

.PHONY : clean fclean all re bonus
