# **************************************************************************** #
#                                   Makefile                                   #
# **************************************************************************** #

NAME = libftprintf.a

# Compiler and flags
CC = cc
CFLAGS = -Wall -Wextra -Werror

# Directories
MANDATORY_DIR = ft_printf
BONUS_DIR = ft_printf_bonus

# Source files
MANDATORY_SRCS = $(wildcard $(MANDATORY_DIR)/*.c)
BONUS_SRCS = $(wildcard $(BONUS_DIR)/*.c)

# Object files
MANDATORY_OBJS = $(MANDATORY_SRCS:.c=.o)
BONUS_OBJS = $(BONUS_SRCS:.c=.o)

# Rules
all: $(NAME)

$(NAME): $(MANDATORY_OBJS)
	ar rcs $(NAME) $(MANDATORY_OBJS)

bonus: $(BONUS_OBJS)
	ar rcs $(NAME) $(BONUS_OBJS)

clean:
	rm -f $(MANDATORY_OBJS) $(BONUS_OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

# Include dependency files
-include $(MANDATORY_OBJS:.o=.d) $(BONUS_OBJS:.o=.d)

# Pattern rule for object files with dependencies
%.o: %.c
	$(CC) $(CFLAGS) -MMD -c $< -o $@

.PHONY: all bonus clean fclean re
