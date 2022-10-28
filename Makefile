NAME = so_long
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g
MLX_FLAGS = -lmlx -lXext -lX11 -lm -lz

LIBFT = ./libft/libft.a
LIBFT_DIR = ./libft/
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
		user_input.c)


MAKE_LIBFT = cd $(LIBFT_DIR) && make
CLEAN_LIBFT = cd $(LIBFT_DIR) && make clean
FCLEAN_LIBFT = cd $(LIBFT_DIR) && make fclean

all: ${LIBFT} ${NAME}
	

${LIBFT}:
	$(MAKE_LIBFT)
	cd ..

clean:
	clear
	$(CLEAN_LIBFT)
	cd ..

${NAME}: 		
		${CC} ${SRCS} ${LIBFT} ${CFLAGS} ${MLX_FLAGS} -o ${NAME}
		@echo "\033[1;92mso_long created successfully!\033[0m"

fclean: clean
	cd ..
	$(FCLEAN_LIBFT)
	rm -rf so_long
	@echo "\033[1;92mso_long removed successfully!\033[0m"


re: fclean libft all

.PHONY: re fclean clean libft all