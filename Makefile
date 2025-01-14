SRC = b_format_handler.c \
		ft_negative_utils_bonus.c \
		ft_util1_bonus.c  \
		ft_util3_bonus.c  \
		ft_util5_bonus.c  \
		ft_util_bonus.c  \
		ft_negative_bonus.c \
		ft_printf.c \
		ft_util2_bonus.c \
		ft_util4_bonus.c \
		ft_util6_bonus.c \
		ft_zero_paddding_bonus.c

NAME = libftprintf.a
OBJ = $(SRC:.c=.o)
INCLUDE = ft_printf.h 
CFLAGS = -Wall -Wextra -Werror
CC = cc

all : $(NAME)

$(NAME) : $(OBJ)
	ar -rc $(NAME) $(OBJ)

%.o: %.c $(INCLUDE)
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

bonus : fclean all

re : fclean all
