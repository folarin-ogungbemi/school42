# Compiler and Flags

CC = cc
CFLAGS = -Wall -Werror -Wextra

# Files
NAME = libftprintf.a
SRC_FILES = \
	    ft_printf.c ft_print_char.c ft_print_str.c ft_print_dec.c \
	    ft_print_hexx.c ft_print_hexl.c ft_print_u.c ft_print_ptr.c ft_print_percent.c \
	    utils/ft_hexdec_high.c utils/ft_hexdec_low.c utils/ft_putchar.c \
	    utils/ft_putstr.c utils/ft_strlen.c utils/ft_strcpy.c utils/ft_putnbr.c \
	    utils/ft_pointer.c utils/ft_unsigned_int.c

OBJ_FILES = $(SRC_FILES:%.c=%.o)
TARGET = program

all: $(NAME)

# Create the static library from the files
$(NAME): $(OBJ_FILES)
	@ar rcs $@ $^
	@echo "LIbrary $(NAME) created successfully."

# Compile each source file into an object file
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@
	@echo "Compiled $< to $@ successfully."

# Create an executable file
$(TARGET): $(NAME)
	$(CC) $(CFLAGS) $(OBJ_FILES) -L. -lftprintf -o $@
	@echo "$(TARGET) Successfully created"

run: $(TARGET)
	./$(TARGET)

clean:
	@rm -rf *.o */*.o
	@echo "Object files removed successfully"

fclean: clean
	@rm -rf $(NAME) $(TARGET)
	@echo "$(NAME)  & $(TARGET) removed."

# Rebuild everything from scratch
re: fclean all

.PHONY: all clean fclean re
