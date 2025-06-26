# Automate compilation and linking file process.

CC = cc
CFLAGS = -Wall -Werror -Wextra

CLIENT = client
SERVER = server

SRC_CLIENT = client.c
SRC_SERVER = server.c

OBJ_CLIENT = $(SRC_CLIENT:%.c=%.o)
OBJ_SERVER = $(SRC_SERVER:%.c=%.o)

all: $(CLIENT) $(SERVER)

$(CLIENT): $(OBJ_CLIENT)
	$(CC) $(CFLAGS) $(OBJ_CLIENT) -o $@
	@echo "Linked $@ successfully"

$(SERVER): $(OBJ_SERVER)
	$(CC) $(CFLAGS) $(OBJ_SERVER) -o $@
	@echo "Linked $@ successfully"

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@
	@echo "Compiled $< to $@"

clean: 
	@rm -f *.o
	@echo "Successfully removed object files"

fclean: clean
	@rm -f $(CLIENT) $(SERVER)
	@echo "Removed $(CLIENT) $(SERVER) program successfully"

re: fclean all

.PHONY: all re clean fclean run_client run_server
