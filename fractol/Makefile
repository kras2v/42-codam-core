# Colors
YELLOW := \033[1;33m
GREEN := \033[1;32m
CYAN := \033[1;36m
RED := \033[1;31m
RESET := \033[0m

#HEADERS
HEADERS := fractol.h

#SOURCES
SOURCES :=	utils_atof.c \
			complex_operations.c \
			main.c \
			utils_display_img.c \
			utils_scale.c \
			calculations_julia_mandelbrot.c \
			newton.c \
			fractal_coloring.c \
			utils_coloring.c \
			fractal_selector.c \
			fractal_rendering.c \
			events_initialization.c \
			events_utils.c \
			key_press_events.c \
			mouse_events.c \
			utils_program.c

#TARGET
NAME := fractol
LIBFT_DIR := ./libft
LIBFT := $(LIBFT_DIR)/libft.a

#OBJECTS
OBJS := $(SOURCES:%.c=%.o)

#FLAGS
CFLAGS := -Wall -Werror -Wextra
CC := cc

all : $(NAME)

$(NAME) : $(OBJS) $(LIBFT)
	@echo -e "$(CYAN)[INFO] Creating $(NAME)...$(RESET)"
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)
	@echo -e "$(GREEN)Fractol has been created$(RESET)"

%.o : %.c
	@echo -e "$(YELLOW)[BUILD] Compiling $< -> $@$(RESET)"
	@$(CC) -c $(CFLAGS) -I/usr/include -Imlx_linux -O3 -c $< -o $@

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
