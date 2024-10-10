HEADERS := libft.h
SRCS := ft_isascii.c ft_strlcat.c ft_memchr.c ft_calloc.c ft_strrchr.c ft_isalpha.c ft_itoa.c ft_strlcpy.c ft_memset.c ft_memmove.c ft_strchr.c ft_strdup.c ft_strmapi.c ft_strtrim.c ft_atoi.c ft_strlen.c ft_memcmp.c ft_toupper.c ft_memcpy.c ft_isprint.c ft_strnstr.c ft_substr.c ft_bzero.c ft_strncmp.c ft_tolower.c ft_strjoin.c ft_isalnum.c ft_isdigit.c ft_split.c
OBJC := $(SRCS:%.c=%.o)
TARGET := libft.a
CFLAGS := -Wall -Wextra -Werror
ARFLAGS := -r -s -c

all : $(TARGET)

$(TARGET) : $(OBJC)
	ar $(ARFLAGS) $(TARGET) $(OBJC)

%.o : %.c
	cc -c $(CFLAGS) $< -o $@

clean:
	rm -f $(OBJC)

fclean: clean
	rm -f $(TARGET)

re: fclean $(TARGET)