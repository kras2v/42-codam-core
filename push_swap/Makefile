# Colors
YELLOW := \033[1;33m
GREEN := \033[1;32m
CYAN := \033[1;36m
RED := \033[1;31m
RESET := \033[0m

#HEADERS
HEADERS := push_swap.h parser_utils.h

#SOURCES
SRCS := main.c \
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

BONUS_SRCS := _bonus_checker.c \
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
OBJS := $(SRCS:%.c=%.o)
BONUS_OBJS := $(BONUS_SRCS:%.c=%.o)

#FLAGS
CFLAGS := -Wall -Werror -Wextra
CC := cc
AR := ar rcs

#!DEBUG
DEBUG_NAME := push_swap_debug
LIBFT_DEBUG := $(LIBFT_DIR)/libft_debug.a
DEBUG_OBJS := $(BONUS_SRCS:%.c=debug_%.o)
DEBUG_FLAGS := $(CFLAGS) -g
#!--------------------------------

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

#!DEBUG RULES
debug: $(DEBUG_NAME)

$(DEBUG_NAME): $(LIBFT_DEBUG) $(DEBUG_OBJS) 
	@echo -e "$(CYAN)[DEBUG] Creating debug version of $(NAME)...$(RESET)"
	@$(CC) $(DEBUG_FLAGS) $(DEBUG_OBJS) -o $@ $(LIBFT_DEBUG)
	@echo -e "$(GREEN)Debug version of Push_swap has been created$(RESET)"

$(LIBFT_DEBUG) : 
	@echo -e "$(CYAN)[INFO] Compiling Libft debug library...$(RESET)"
	@$(MAKE) -C $(LIBFT_DIR) debug

debug_%.o: %.c
	@echo -e "$(YELLOW)[DEBUG BUILD] Compiling $< -> $@$(RESET)"
	@$(CC) -c $(DEBUG_FLAGS) $< -o $@

clean :
	@echo -e "$(RED)[CLEAN] Cleaning object files...$(RESET)"
	@rm -f $(OBJS) $(BONUS_OBJS) $(DEBUG_OBJS)
	@$(MAKE) -C $(LIBFT_DIR) --silent clean

fclean : clean
	@echo -e "$(RED)[FCLEAN] Removing $(NAME), $(DEBUG_NAME), $(BONUS), and other artifacts...$(RESET)"
	@rm -f $(NAME) $(DEBUG_NAME) $(BONUS)
	@$(MAKE) -C $(LIBFT_DIR) --silent fclean

re : fclean all

.PHONY : all clean fclean re
