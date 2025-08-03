CC = cc
CFLAGS = -Wall -Werror -Wextra 

NAME = so_long
GNL_DIR = GetNextLine
SRC_FILES = main.c map.c render.c utils.c keypress.c checker.c\
	    $(GNL_DIR)/get_next_line.c \
	    $(GNL_DIR)/get_next_line_utils.c
OBJ_FILES = $(SRC_FILES:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJ_FILES)
	$(CC) $(CFLAGS) $(OBJ_FILES) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $@

%.o: %.c
	$(CC) $(CFLAGS) -I/ust/include -Imlx_linux -O3 -c $< -o $@

clean:
	@rm -f ./*.o

fclean: clean
	@rm -f ./$(NAME)

re: fclean all

.PHONY: clean fclean re all
