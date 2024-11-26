HEADERS := push_swap.h
SRCS := push_swap.c

#TARGET
NAME := push_swap.a
PRINTF_DIR := ./libft/printf
PRINTF := $(PRINTF_DIR)/libftprintf.a

#OBJECTS
OBJS := $(SRCS:%.c=%.o)

#FLAGS
CFLAGS := -Wall -Werror -Wextra
CC := cc
AR := ar rcs

#!DEBUG
DEBUG_NAME := push_swap_debug
LIBFT_DIR = ./libft
PRINTF_DEBUG := $(PRINTF_DIR)/libftprintf_debug.a
LIBFT_DEBUG := $(LIBFT_DIR)/libft_debug.a
DEBUG_OBJS := $(SRCS:%.c=debug_%.o)
DEBUG_FLAGS := $(CFLAGS) -g

all : $(NAME)

$(NAME) : $(OBJS) $(PRINTF)
	@cp $(PRINTF) $@
	@$(AR) $@ $(OBJS)
#	@echo "Push_swap library has been created"

%.o : %.c
	@$(CC) -c $(CFLAGS) $< -o $@
#	@echo "Objects have been created"

$(PRINTF) :
	@$(MAKE) -C $(PRINTF_DIR) --silent

#!DEBUG RULES
debug: $(DEBUG_NAME)

$(DEBUG_NAME): $(LIBFT_DEBUG) $(PRINTF_DEBUG) $(DEBUG_OBJS) 
	@$(CC) $(DEBUG_FLAGS) $(DEBUG_OBJS) -o $@ $(LIBFT_DEBUG) $(PRINTF_DEBUG)
#	@echo "Debug version of Push_swap.a has been created"

$(PRINTF_DEBUG) : 
	@$(MAKE) -C $(PRINTF_DIR) --silent debug

$(LIBFT_DEBUG):
	@$(MAKE) -C $(LIBFT_DIR) --silent debug

debug_%.o: %.c
	@$(CC) -c $(DEBUG_FLAGS) $< -o $@
#!--------------------------------

clean :
	@rm -f $(OBJS) $(DEBUG_OBJS)
	@$(MAKE) -C $(PRINTF_DIR) --silent clean
#	@echo "Objects have been cleaned"

fclean : clean
	@rm -f $(NAME) $(DEBUG_NAME)
	@$(MAKE) -C $(PRINTF_DIR) --silent fclean
#	@echo "Fully clean build artifacts."

re : fclean all

.PHONY : all clean fclean re