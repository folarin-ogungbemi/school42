# Compiler and Flags

CC = cc
CFLAGS = -Wall -Werror -Wextra

# Files
NAME = libftprintf.a
SRC_FILES = main.c ft_printf.c utils/ft_hexdec_high.c utils/ft_hexdec_low.c utils/ft_putchar.c utils/ft_putstr.c utils/ft_strlen.c utils/ft_strcpy.c utils/ft_putnbr.c utils/ft_pointer.c utils/ft_unsigned_int.c
OBJ_FILES = $(SRC_FILES: %.c=%.o)
TARGET = program

all: $(NAME)

# Create the static library from the files
$(NAME): $(OBJ_FILES)
	@ar rcs $@ $^
	@echo "LIbrary $(NAME) created successfully."

# Create an executable file
$(TARGET): $(OBJ_FILES)
	$(CC) $(CFLAGS) $(OBJ_FILES) -o $@
	@echo "$(TARGET) Successfully created"

# Compile each source file into an object file
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@
	@echo "Compiled $< to $@ successfully."

run: $(TARGET)
	./$(TARGET)

clean:
	@rm -rf *.o
	@echo "Object files removed successfully"

fclean:
	@rm -rf $(NAME) $(TARGET)
	@echo "$(NAME)  & $(TARGET) removed."

# Rebuild everything from scratch
re: fclean all

.PHONY: all clean fclean re
