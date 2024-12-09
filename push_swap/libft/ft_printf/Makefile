# Colors
YELLOW := \033[1;33m
GREEN := \033[1;32m
CYAN := \033[1;36m
RED := \033[1;31m
RESET := \033[0m

#HEADERS
HEADERS := ft_printf.h

#SOURCES
SRCS := ft_printf.c \
		ft_printf_c.c \
		ft_printf_s.c \
		ft_printf_d.c \
		ft_printf_x.c \
		ft_printf_ux.c \
		ft_printf_p.c \
		ft_printf_u.c \
		ft_printf_i.c \
		ft_printf_percent.c \
		ft_convert_to_base.c \

#TARGET
NAME := libftprintf.a

#OBJECTS
OBJS := $(SRCS:%.c=%.o)

#FLAGS
CFLAGS := -Wall -Werror -Wextra
AR := ar rcs
CC := cc -c

#!DEBUG
DEBUG_OBJS := $(SRCS:%.c=debug_%.o)
DEBUG_FLAGS := $(CFLAGS) -g
DEBUG_NAME := libftprintf_debug.a

all : $(NAME)

$(NAME) : $(OBJS)
	@echo -e "$(CYAN)[INFO] Creating $(NAME)...$(RESET)"
	@$(AR) $@ $(OBJS)
	@echo -e "$(GREEN)Printf library has been created$(RESET)"

%.o : %.c
	@echo -e "$(YELLOW)[BUILD] $< -> $@$(RESET)"
	@$(CC) $(CFLAGS) $< -o $@

#!DEBUG RULES
debug: $(DEBUG_NAME)

$(DEBUG_NAME): $(DEBUG_OBJS) 
	@echo -e "$(CYAN)[DEBUG] Creating debug version of $(NAME)...$(RESET)"
	@$(AR) $@ $(DEBUG_OBJS)
	@echo -e "$(GREEN)Debug version of libftprintf.a has been created$(RESET)"

debug_%.o: %.c
	@echo -e "$(YELLOW)[DEBUG BUILD] $< -> $@$(RESET)"
	@$(CC) $(DEBUG_FLAGS) $< -o $@
#!--------------------------------

clean :
	@echo -e "$(RED)[CLEAN] Removing object files...$(RESET)"
	@rm -f $(OBJS) $(DEBUG_OBJS)

fclean : clean
	@echo -e "$(RED)[FCLEAN] Removing $(NAME) and debug libraries...$(RESET)"
	@rm -f $(NAME) $(DEBUG_NAME)

re : fclean all

.PHONY : all clean fclean re
