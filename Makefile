NAME = so_long
CC = clang -g ./srcs/so_long.c ./libft/libft.a -lX11 -lXext -lmlx -o so_long

LIBFT_DIR = ./libft
SRCS_DIR = ./srcs/

HEADER = ./srcs/so_long.h
SRCS =	$(addprefix $(SRCS_DIR),\
		check_args.c		\
		create_window.c		\
		init_game_vars.c	\
		so_long.c			\
		validate_map.c		\
		check_boundaries.c	\
		error_handling.c	\
		move_player.c		\
		check_map.c			\
		floodfill.c			\
		render_game.c		\
		user_input.c		\


MAKE_LIBFT = cd libft/ && make
CLEAN_LIBFT = cd libft/ && make clean
FCLEAN_LIBFT = cd libft/ && make fclean && cd ..

all: libft
	$(CC)

libft:
	$(MAKE_LIBFT)
	cd ..

clean:
	$(CLEAN_LIBFT)
	cd ..
	rm -rf so_long

fclean: clean
	$(FCLEAN_LIBFT)
	cd ..

re: fclean libft all

.PHONY: re fclean clean libft all


