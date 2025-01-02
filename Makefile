NAME = client server
CC = cc
CFLAGS = -Wall -Wextra -Werror -I./printf -I./libft

SRCS_CLIENT = client.c
SRCS_SERVER = server.c

OBJS_CLIENT = $(SRCS_CLIENT:.c=.o)
OBJS_SERVER = $(SRCS_SERVER:.c=.o)

LIBFT = ./libft/libft.a
PRINTF = ./printf/libftprintf.a

all: $(NAME)

client: $(OBJS_CLIENT) $(LIBFT) $(PRINTF)
	$(CC) $(CFLAGS) $(OBJS_CLIENT) $(LIBFT) $(PRINTF) -o client

server: $(OBJS_SERVER) $(LIBFT) $(PRINTF)
	$(CC) $(CFLAGS) $(OBJS_SERVER) $(LIBFT) $(PRINTF) -o server

$(LIBFT):
	make -C ./libft

$(PRINTF):
	make -C ./printf

clean:
	make -C ./libft clean
	make -C ./printf clean
	rm -f $(OBJS_CLIENT) $(OBJS_SERVER)

fclean: clean
	make -C ./libft fclean
	make -C ./printf fclean
	rm -f client server

re: fclean all

.PHONY: all clean fclean re
