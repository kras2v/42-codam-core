# Colors
YELLOW := \033[1;33m
GREEN := \033[1;32m
CYAN := \033[1;36m
RED := \033[1;31m
RESET := \033[0m

#HEADERS
HEADERS := push_swap.h

#SOURCES
SOURCES :=	main.c \
			push_swap.c \
			push_swap_utils.c \
			parser.c \
			parser_utils.c \
			push.c \
			swap.c \
			rotate.c \
			reverse_rotate.c \
			instructions_utils.c \
			initialization.c \
			sort_three_elements.c \
			sort_utils.c \

BONUS_SOURCES :=_bonus_main.c \
				_bonus_parser_utils.c \
				_bonus_proceed_standart_input.c \
				_bonus_parser.c \
				_bonus_checker_utils.c \
				_bonus_instructions_utils.c \
				_bonus_push.c \
				_bonus_rotate.c \
				_bonus_reverse_rotate.c \
				_bonus_instruction_parcer.c \
				_bonus_swap.c

#TARGET
NAME := push_swap
BONUS := checker
LIBFT_DIR := ./libft
LIBFT := $(LIBFT_DIR)/libft.a

#OBJECTS
OBJS := $(SOURCES:%.c=%.o)
BONUS_OBJS := $(BONUS_SOURCES:%.c=%.o)

#FLAGS
CFLAGS := -Wall -Werror -Wextra
CC := cc

all : $(NAME)

$(NAME) : $(OBJS) $(LIBFT)
	@echo -e "$(CYAN)[INFO] Creating $(NAME)...$(RESET)"
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $@
	@echo -e "$(GREEN)Push_swap has been created$(RESET)"

bonus : $(BONUS_OBJS) $(LIBFT)
	@echo -e "$(CYAN)[INFO] Creating $(BONUS)...$(RESET)"
	@$(CC) $(CFLAGS) $(BONUS_OBJS) $(LIBFT) -o $(BONUS)
	@echo -e "$(GREEN)Checker bonus has been created$(RESET)"

%.o : %.c
	@echo -e "$(YELLOW)[BUILD] Compiling $< -> $@$(RESET)"
	@$(CC) -c $(CFLAGS) $< -o $@

$(LIBFT) :
	@echo -e "$(CYAN)[INFO] Building Libft library...$(RESET)"
	@$(MAKE) -C $(LIBFT_DIR)

clean :
	@echo -e "$(RED)[CLEAN] Cleaning object files...$(RESET)"
	@rm -f $(OBJS) $(BONUS_OBJS)
	@$(MAKE) -C $(LIBFT_DIR) --silent clean

fclean : clean
	@echo -e "$(RED)[FCLEAN] Removing $(NAME), $(BONUS), and other artifacts...$(RESET)"
	@rm -f $(NAME)  $(BONUS)
	@$(MAKE) -C $(LIBFT_DIR) --silent fclean

re : fclean all

.PHONY : all clean fclean re
