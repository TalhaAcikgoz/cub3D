NAME = cub3d
CC = gcc

SOURCES = $(wildcard src/*.c)
OBJECTS = $(patsubst %.c, %.o, $(SOURCES))
CFLAGS =  -I ./inc -I ./mlx/mlx.h 
MLX = -framework OpenGL -framework AppKit libmlx.a

#-Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJECTS) run_mlx
	$(CC) $(OBJECTS) $(MLX) -o $(NAME)
	rm -rf $(OBJECTS)

run_mlx:
	cd mlx && $(MAKE) all
	mv mlx/libmlx.a ./

clean:
	rm -f *.o program
	cd mlx && $(MAKE) clean

re: clean all