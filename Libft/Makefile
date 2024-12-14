# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: foogungb <foogungb@student.42berlin.d      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/14 16:50:36 by foogungb          #+#    #+#              #
#    Updated: 2024/12/09 16:16:03 by foogungb         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# _*_Makefile to automate the compilation process.

# Define variables
CC = cc
CFLAGS = -Wall -Werror -Wextra
NAME = libft.a
TARGET = program

# dir
OBJ = objs
BONUS_OBJ = bonus_objs

# Files
SRC_FILES = \
	    ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
	    ft_strlen.c ft_memset.c ft_bzero.c main.c ft_memcpy.c ft_itoa.c\
	    ft_memmove.c ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c \
	    ft_strchr.c ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c \
	    ft_strnstr.c ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c \
	    ft_strjoin.c ft_strtrim.c ft_split.c ft_strmapi.c ft_striteri.c \
	    ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c
BONUS_FILES = \
	     ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c \
	     ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c
OBJ_FILES = $(SRC_FILES:%.c=$(OBJ)/%.o)
BONUS_OBJ_FILES = $(BONUS_FILES:%.c=$(OBJ)/%.o)

# Set default target
all: $(NAME)

# Create the static library from the obj files
$(NAME): $(OBJ_FILES)
	@ar rcs $@ $(OBJ_FILES)
	@echo "Compiled $@ Successfully."

$(TARGET): $(OBJ_FILES) $(BONUS_OBJ_FILES)
	$(CC) $(CFLAGS) $(OBJ_FILES) $(BONUS_OBJ_FILES) -o $@
	@echo "Compiled $@ Successfully."

# Compile each source file into object file
$(OBJ)/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@
	@echo "Compiled $< to $@ Successfully."

# Bonus rule to add the bonus files to the library
bonus: $(BONUS_OBJ_FILES)
	@ar rcs $(NAME) $(BONUS_OBJ_FILES)
	@echo "Added bonus functions to $(NAME) Successfully."

print:
	@echo "SRC_FILES: $(SRC_FILES)"
	@echo "OBJ_FILES: $(OBJ_FILES)"
	@echo "BONUS_OBJ_FILES: $(BONUS_OBJ_FILES)"
	@echo "TARGET: $(TARGET)"
	@echo "NAME: $(NAME)"

run: $(TARGET)
	./$(TARGET)

clean:
	@rm -rf $(OBJ)
	@echo "$(OBJ) files removed."

fclean: clean
	@rm -f $(NAME) $(TARGET)
	@echo "$(NAME) & $(TARGET) files removed."

# Rebuild everything from scratch
re: fclean all

# Phony targets to avoid conflicts with filenames
.PHONY: all clean fclean re
