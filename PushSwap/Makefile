
CC = cc
CFLAGS = -Wall -Werror -Wextra

TARGET = push_swap
SRC_FILES = main.c push_swap.c radix_sort.c swap.c push.c rotate.c rotatex2.c list.c ft_atoi.c

OBJ_FILES = $(SRC_FILES:%.c=%.o)
all: $(TARGET)

$(TARGET): $(OBJ_FILES)
	$(CC) $(CFLAGS) $(OBJ_FILES) -o $@
	@echo "Compiled $< to $@ successfully."

# Create each source file into an object file
%.o:%.c
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "Compiled $< to $@"

run: $(TARGET)
	./$(TARGET) 170 45 75 90 802 24 2 66 1234

clean:
	@rm -rf */*.o *.o
	@echo "Object files removed."

fclean: clean
	@rm -rf $(TARGET)
	@echo "$(TARGET) removed"

re: fclean all
