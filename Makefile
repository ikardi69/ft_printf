# Variables
NAME := libftprintf.a
SRCS := ft_print_adress.c ft_put_unsigned.c ft_putchar.c ft_putnbr_hex_lower.c \
        ft_putnbr_hex_upper.c ft_putnbr.c ft_putstr.c
OBJS := $(SRCS:.c=.o)
CC := gcc
CFLAGS := -Wall -Wextra -Werror

# Build the library
all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)  # Use object files to create the library

%.o: %.c libftprintf.h
	$(CC) $(CFLAGS) -c $< -o $@  # Compile source files into object files

# Clean up object files
clean:
	rm -f $(OBJS)

# Clean up all generated files
fclean: clean
	rm -f $(NAME)

# Rebuild everything
re: fclean all

.PHONY: all clean fclean re
