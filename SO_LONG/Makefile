CC := cc
CFLAGS := -g -Wall -Werror -Wextra

NAME := so_long
GNL_DIR := GetNextLine
MLX_DIR := ./minilibx-linux
MLX_REPO := https://github.com/42paris/minilibx-linux.git
MLX_LIB := $(MLX_DIR)/libmlx.a

SRC_FILES := main.c read_map.c validate_map.c \
            load_textures.c render_tile.c \
            keypress.c utils.c utils2.c clean_exit.c \
            $(GNL_DIR)/get_next_line.c \
            $(GNL_DIR)/get_next_line_utils.c
OBJ_FILES = $(SRC_FILES:%.c=%.o)

all: $(MLX_LIB) $(NAME)

$(NAME): $(OBJ_FILES) $(MLX_LIB)
	$(CC) $(CFLAGS) $(OBJ_FILES) -L$(MLX_DIR) -lmlx \
		-L/usr/lib -lXext -lX11 -lm -lz -o $@

$(MLX_LIB):
	@if [ ! -d "$(MLX_DIR)" ]; then \
		echo "Cloning minilibx"; \
		git clone $(MLX_REPO) $(MLX_DIR); \
	fi
	@echo "Building minilibx"
	@make -C $(MLX_DIR)

%.o: %.c
	$(CC) $(CFLAGS) -I/usr/include -I$(MLX_DIR) -O3 -c $< -o $@

clean:
	@rm -f $(OBJ_FILES)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: clean fclean re all
