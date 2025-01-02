NAME = libftprintf.a
SRC = ft_printf.c ft_process.c ft_output.c ft_convert.c
OBJ = $(SRC:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror
INCLUDES = -I./includes

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

all: $(NAME)

test_program: $(NAME) main.c
	$(CC) $(CFLAGS) main.c -L. -lftprintf -o test_program

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME) test_program

re: fclean all

.PHONY: all clean fclean re
