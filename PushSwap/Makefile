
CC = cc
CFLAGS = -Wall -Werror -Wextra

TARGET = push_swap
SRC_FILES = main.c push_swap.c \
	    swap.c push.c rotate.c rotatex2.c \
	    sort_2.c sort_3.c sort_4.c sort_5.c \
	    chunk_sort.c utils.c utils1.c utils2.c

OBJ_FILES = $(SRC_FILES:%.c=%.o)

all: $(TARGET)

$(TARGET): $(OBJ_FILES)
	$(CC) $(CFLAGS) $(OBJ_FILES) -o $@
	@echo "Linked $(TARGET) successfully."

# Create each source file into an object file
%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "Compiled $<"

run: $(TARGET)
	./$(TARGET) 170 45 75 90 802 24 2 66 1234

clean:
	@rm -f *.o
	@echo "Object files removed."

fclean: clean
	@rm -f $(TARGET)
	@echo "$(TARGET) removed"

re: fclean all

.PHONY: all clean fclean re run
