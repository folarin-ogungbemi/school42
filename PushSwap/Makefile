
CC = cc
CFLAGS = -Wall -Werror -Wextra

TARGET = program
SRC_FILES = main.c

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
	./$(TARGET)

clean:
	@rm -rf *.o
	@echo "Object files removed."

fclean: clean
	@rm -rf $(TARGET)
	@echo "$(TARGET) removed"

re: fclean all
