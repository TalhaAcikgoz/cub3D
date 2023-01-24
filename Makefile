NAME = cub3d
CC = gcc

SOURCES = $(wildcard src/*.c)
OBJECTS = $(patsubst %.c, %.o, $(SOURCES))
CFLAGS =  -Iinc -Imlx
MLX = libmlx.a

#-Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJECTS)
	$(CC) $(OBJECTS) $(MLX) -L/usr/lib -Imlx -lXext -lX11 -lm -lz -o $(NAME)

run_mlx:
	cd mlx && $(MAKE) all
	mv mlx/libmlx.a ./

clean:
	rm -f $(OBJECTS) program
	cd mlx && $(MAKE) clean

re: clean all