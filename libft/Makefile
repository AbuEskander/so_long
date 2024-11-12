include Includes.mk 
SRC_DIR = src
OBJ_DIR = build
CC = cc
CFLAGS = -Wall -Werror -Wextra -I./includes
NAME = libft.a
SRCSDIR=$(addprefix src/,$(SRCS))

OBJS = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRCSDIR))


all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME)  $(OBJS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@
clean: 
	rm -f  $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re