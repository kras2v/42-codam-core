# Colors
YELLOW := \033[1;33m
GREEN := \033[1;32m
CYAN := \033[1;36m
RED := \033[1;31m
RESET := \033[0m

#HEADERS
HEADERS :=

#SOURCES
SERVER_SOURCES :=	server.c
CLIENT_SOURCES :=	client.c

BONUS_SOURCES :=

#TARGET
NAME := server
CLIENT := client
BONUS := 
LIBFT_DIR := ./libft
LIBFT := $(LIBFT_DIR)/libft.a

#OBJECTS
SERVER_OBJECTS := $(SERVER_SOURCES:%.c=%.o)
CLIENT_OBJECTS := $(CLIENT_SOURCES:%.c=%.o)

#FLAGS
CFLAGS := -Wall -Werror -Wextra
CC := cc

all : $(NAME)

$(NAME) : $(SERVER_OBJECTS) $(LIBFT) $(CLIENT)
	@echo -e "$(CYAN)[INFO] Creating $(NAME)...$(RESET)"
	@$(CC) $(CFLAGS) $(SERVER_OBJECTS) $(LIBFT) -o $@
	@echo -e "$(GREEN)Server has been created$(RESET)"

$(CLIENT) : $(CLIENT_OBJECTS) $(LIBFT)
	@echo -e "$(CYAN)[INFO] Creating $(NAME)...$(RESET)"
	@$(CC) $(CFLAGS) $(CLIENT_OBJECTS) $(LIBFT) -o $@
	@echo -e "$(GREEN)Client has been created$(RESET)"

%.o : %.c
	@echo -e "$(YELLOW)[BUILD] Compiling $< -> $@$(RESET)"
	@$(CC) -c $(CFLAGS) $< -o $@

$(LIBFT) :
	@echo -e "$(CYAN)[INFO] Building Libft library...$(RESET)"
	@$(MAKE) -C $(LIBFT_DIR)

clean :
	@echo -e "$(RED)[CLEAN] Cleaning object files...$(RESET)"
	@rm -f $(SERVER_OBJECTS) $(CLIENT_OBJECTS)
	@$(MAKE) -C $(LIBFT_DIR) --silent clean

fclean : clean
	@echo -e "$(RED)[FCLEAN] Removing $(NAME), $(BONUS), and other artifacts...$(RESET)"
	@rm -f $(NAME) $(CLIENT) $(BONUS)
	@$(MAKE) -C $(LIBFT_DIR) --silent fclean

re : fclean all

.PHONY : all clean fclean re
