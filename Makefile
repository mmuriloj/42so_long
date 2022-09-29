NAME = so_long
CC = clang ./srcs/so_long.c ./libft/libft.a -lX11 -lXext -lmlx -o so_long

LIBFT_DIR = ./libft

HEADER = ./srcs/so_long.h
SRCS = srcs/main.c \
		srcs/init_map.c \
		so_long.c

MAKE_LIBFT = cd libft/ && make && cd ..
CLEAN_LIBFT = cd libft/ && make clean && cd ..


all: libft
	$(CC)

libft:
	$(MAKE_LIBFT)

clean:
	cd libft/ && make clean && cd ..

fclean: clean
	cd libft/ && make fclean && cd ..

re: fclean libft all

.PHONY: re fclean clean libft all


