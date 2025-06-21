NAME		= so_long

CC			= cc
CFLAGS		= -Wall -Wextra -Werror -Iincludes -Ilibft -Imlx

SRC_DIR		= srcs
OBJ_DIR		= objs
LIBFT_DIR	= libft
MLX_DIR		= mlx

SRCS		= main.c map_read.c map_read_fill.c map_validate.c \
			free_map.c game_init.c render_map.c map_solvable.c \
			exit_hook.c free_game.c key_hook.c \

OBJS		= $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))

LIBFT_LIB	= $(LIBFT_DIR)/libft.a
MLX_LIB		= $(MLX_DIR)/libmlx.a

MLX_LIBS	= -L$(MLX_DIR) -lmlx -lXext -lX11 -lm

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT_LIB) $(MLX_LIB)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT_LIB) $(MLX_LIBS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT_LIB):
	make -C $(LIBFT_DIR)

$(MLX_LIB):
	make -C $(MLX_DIR)

clean:
	rm -rf $(OBJ_DIR)
	make -C $(LIBFT_DIR) clean
	make -C $(MLX_DIR) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re