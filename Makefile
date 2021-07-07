NAME = SOLONG
LIBFT = libft/libft.a
FLAGS = -Wall -Wextra -Werror
SRC =   src/so_long.c               \
        src/map_errors.c            \
        src/draw_map.c              \
        src/utils.c                 \
        src/key_hook.c              \
        gnl/get_next_line.c         \
        gnl/get_next_line_utils.c   \

INC =   inc/so_long.h           \
        gnl/get_next_line.h     \

LIB = -L ./libft -lft -L ./mlx -lmlx -lXext -lX11

all: $(NAME)

$(NAME):
	gcc $(FLAGS) -o $(NAME) $(SRC) $(LIB)

skiperror:
	gcc -o $(NAME) $(SRC) -g $(LIB)

clean:
	@rm -rf *.o
	@echo "cleaning .o files"

fclean: clean
	@rm -rf $(NAME)

re: fclean all
