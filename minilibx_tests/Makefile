# Colors
YELLOW := \033[1;33m
GREEN := \033[1;32m
CYAN := \033[1;36m
RED := \033[1;31m
RESET := \033[0m

#HEADERS
HEADERS := square.h

#SOURCES
SOURCES :=	main.c

#TARGET
NAME := square

#OBJECTS
OBJS := $(SOURCES:%.c=%.o)

#FLAGS
CC := cc
CFLAGS := -Wall -Werror -Wextra

all : $(NAME)

$(NAME) : $(OBJS) $(LIBFT)
	@echo -e "$(CYAN)[INFO] Creating $(NAME)...$(RESET)"
	$(CC) $(OBJS) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)
	@echo -e "$(GREEN)square has been created$(RESET)"

%.o : %.c
	@echo -e "$(YELLOW)[BUILD] Compiling $< -> $@$(RESET)"
	$(CC) -Wall -Wextra -Werror -I/usr/include -Imlx_linux -O3 -c $< -o $@

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
