SRCS = main.c key_strokes.c checks.c check_components.c display_error.c solvablemap.c renders.c put.c check_movement.c
SRC_DIR = src
OBJ_DIR = build
CC = cc
NAME = so_long
MINIX = minilibx-linux
LIBS = -L./minilibx-linux/ -L./libft -lft -lmlx_Linux -lmlx -lXext -lX11
CFLAGS = -Wall -Werror -Wextra -I./includes $(LIBS)
SRCSDIR=$(addprefix src/,$(SRCS))
OBJS = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRCSDIR))
LIBFT = libft

all: $(NAME)

$(NAME): $(OBJS)
	@make -C $(LIBFT)
	@make -C $(MINIX)
	$(CC) $(OBJS) $(CFLAGS)  -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@
clean: 
	@make -C $(MINIX) clean
	@make -C $(LIBFT) fclean
	rm -f  $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re