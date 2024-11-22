# Project name
NAME = libftprintf.a

# Compiler and flags
CC = cc
CFLAGS = -Wall -Wextra -Werror

# Source and object files
SRCS = ft_printf.c ft_printf_utils.c
OBJS = $(SRCS:.c=.o)

# Archive command
AR = ar rcs

# Default rule
all: $(NAME)

# Create the library
$(NAME): $(OBJS)
	@$(AR) $(NAME) $(OBJS)
	@echo "$(GREEN)$(NAME) created successfully!$(RESET)"

# Compile source files
%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "Compiled: $<"

# Clean object files
clean:
	@rm -f $(OBJS)
	@echo "$(RED)Object files removed!$(RESET)"

# Clean everything
fclean: clean
	@rm -f $(NAME)
	@echo "$(RED)$(NAME) removed!$(RESET)"

# Rebuild everything
re: fclean all

# Phony rules
.PHONY: all clean fclean re
