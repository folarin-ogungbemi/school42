# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: foogungb <foogungb@student.42berlin.d      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/17 20:12:13 by foogungb          #+#    #+#              #
#    Updated: 2025/01/17 20:23:56 by foogungb         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
VALUE = 1 
CFLAGS = -Wall -Werror -Wextra -D BUFFER_SIZE=$(VALUE)
SCR_FILES = get_next_line.c get_next_line_utils.c main.c
OBJ_FILES = $(SCR_FILES:%.c=%.o)
TARGET = program

# Default target name
all: $(TARGET)

# Build Project to executable
$(TARGET): $(OBJ_FILES)
	@$(CC) $(CFLAGS) $(OBJ_FILES) -o $@
	@echo "Compiled $@ Successfully."

# Compile each source file into an object file
%.c: %.o
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "Compiled $< to $@"

run: $(TARGET)
	./$(TARGET)

# CLean object files
clean:
	@rm -rf ./*.o
	@echo "Object files removed"

fclean: clean
	@rm -rf $(TARGET)
	@echo "$(TARGET) removed"

# Rebuild everything
re: fclean all
