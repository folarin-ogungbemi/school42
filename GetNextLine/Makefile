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

CC = gcc
VALUE = 5 
CFLAGS = -g -Wall -Werror -Wextra -D BUFFER_SIZE=$(VALUE)
SCR_FILES = get_next_line.c get_next_line_utils.c main.c
BONUS_SRC_FILES = get_next_line_bonus.c get_next_line_utils_bonus.c main.c
OBJ_FILES = $(SRC_FILES:%.c=%.o)
BONUS_OBJ_FILES = $(BONUS_SRC_FILES:%.c=%.o)
TARGET = program

# Default target name
all: $(TARGET)

# Build main Program
$(TARGET): $(OBJ_FILES)
	@$(CC) $(CFLAGS) $(OBJ_FILES) -o $@
	@echo "Compiled $@ Successfully."

bonus: $(BONUS_OBJ_FILES)
	@$(CC) $(CFLAGS) $(BONUS_OBJ_FILES) -o $(TARGET)
	@echo "Compiled bonus $(TARGET) Successfully."

# Compile each source file into an object file
%.o: %.c
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
