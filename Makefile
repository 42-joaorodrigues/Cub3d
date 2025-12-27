# cub3D
# by fsilva-p & joao-alm

NAME			= cub3D
CC				= cc
CFLAGS			= -Wall -Werror -Wextra -Ofast -march=native -Wno-incompatible-pointer-types
O_DIR			= obj
HEADER			= $(O_DIR)/.header

all: $(NAME)

SRC_MAIN		= src/main/main.c \
				  src/main/init.c \
				  src/main/free.c
SRC_INPUT		= src/input/input.c \
				  src/input/filename.c \
				  src/input/read/read.c \
				  src/input/read/texture.c \
				  src/input/read/map.c \
				  src/input/read/color_helper.c\
				  src/input/check_map.c \
				  src/input/format_map.c \
				  src/input/flood_fill.c
SRC_GRAPHIC		= src/graphic/raycast.c \
				  src/graphic/raycast_utils.c \
				  src/graphic/draw.c \
				  src/graphic/minimap_bonus.c
SRC_KEYHOOK		= src/keyhook/keyhook.c \
				  src/keyhook/keyhook_rotate.c \
				  src/keyhook/keyhook_walk_bonus.c
SRC				= $(SRC_MAIN) $(SRC_INPUT) $(SRC_GRAPHIC) $(SRC_KEYHOOK)
OBJ				= $(SRC:%.c=$(O_DIR)/%.o)

libft:
	@git clone https://github.com/42-joaorodrigues/mylib.git libft > /dev/null 2>&1
	@echo "Libft downloaded successfully"

mlx:
	@git clone https://github.com/42-joaorodrigues/compiled_mlx.git mlx > /dev/null 2>&1
	@echo "Mlx downloaded successfully"

$(O_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@ -Iinc -Imlx -Ilibft/inc

$(NAME): $(HEADER) libft mlx $(OBJ)
	@make -C libft --no-print-directory > /dev/null 2>&1
	@echo "Libft compiled successfully"
#	@make -C mlx --no-print-directory > /dev/null 2>&1
#	@echo "Mlx compiled successfully"
	@$(CC) $(CFLAGS) $(OBJ) -o $@ -Llibft -lft -Lmlx -lmlx -lXext -lX11 -lm
	@echo "cub3D compiled successfully"

bonus: $(NAME)

clean:
	@rm -rf $(O_DIR)
	@echo "MiniRT objects removed successfully"

fclean: libft mlx
	@rm -rf $(O_DIR)
	@rm -rf $(NAME)
	@echo "cub3D objects & executable removed successfully"
	@make -C libft fclean --no-print-directory > /dev/null 2>&1
	@echo "Libft objects & executable removed successfully"
#	@make -C mlx clean --no-print-directory > /dev/null 2>&1
#	@echo "Mlx objects & executable removed successfully"

re: fclean all

$(HEADER):
	@mkdir -p $(O_DIR)
	@printf "\n"
	@printf "                  888       .d8888b.  8888888b.       \n"
	@printf "                  888      d88P  Y88b 888  \"Y88b     \n"
	@printf "                  888           .d88P 888    888      \n"
	@printf " .d8888b 888  888 88888b.      8888\"  888    888     \n"
	@printf "d88P\"    888  888 888\"88b     \"Y8b.   888    888   \n"
	@printf "888      888  888 888  888 888    888 888    888      \n"
	@printf "Y88b.    Y88b 888 888 d88P Y88b  d88P 888  .d88P      \n"
	@printf " \"Y8888P \"Y88888  88888P\"  \"Y8888P\"   8888888P\" \n"
	@printf "                                                      \n"
	@printf "                 by fsilva-p, joao-alm & ChatGPT      \n"
	@printf "\n"
	@touch $(HEADER)

.PHONY: all clean fclean re
