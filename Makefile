NAME		= so_long

CC			= cc
CFLAGS		= -Wall -Wextra -Werror -Iincludes -Ilibft

SRC_DIR		= srcs
OBJ_DIR		= objs

SRCS		= main.c map_read.c map_read_fill.c map_validate.c \
			  map_validate_logic.c free_map.c

OBJS		= $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))

LIBFT_DIR	= libft
LIBFT_LIB	= $(LIBFT_DIR)/libft.a

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT_LIB)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT_LIB)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT_LIB):
	make -C $(LIBFT_DIR)

clean:
	rm -rf $(OBJ_DIR)
	make -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean

re: fclean all