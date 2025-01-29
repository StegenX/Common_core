SERVER_SRC = server.c

CLIENT_SRC = client.c


SERVER_OBJ = $(SERVER_SRC:.c=.o)

CLIENT_OBJ = $(CLIENT_SRC:.c=.o)

%.o: %.c
	cc -Wall -Wextra -Werror -c $< -o $@

all : server client

server : $(SERVER_OBJ)
	cc -Wall -Wextra -Werror $(SERVER_OBJ) -o server

client : $(CLIENT_OBJ)
	cc -Wall -Wextra -Werror $(CLIENT_OBJ) -o client

clean :
	rm -f $(SERVER_OBJ)

fclean : clean
	rm -f server client

re : fclean all

.PHONY : all re clean fclean



