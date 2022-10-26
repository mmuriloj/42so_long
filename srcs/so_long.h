/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mumontei <mumontei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 10:54:43 by mumontei          #+#    #+#             */
/*   Updated: 2022/10/26 22:25:26 by mumontei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <X11/X.h>
# include <stdlib.h>
# include <X11/keysym.h>
# include <fcntl.h>

# define XPM_WIDTH 32
# define XPM_HEIGHT 32

# define COLLECT_XPM	"img/collectable.xpm"
# define BGROUND_XPM	"img/back-ground.xpm"
# define EXIT_XPM		"img/exit.xpm"
# define OPEN_XPM		"img/open-exit.xpm"
# define PLAYER_XPM		"img/player-front.xpm"
# define WALL_XPM		"img/wall.xpm"

# define KEY_A			97
# define KEY_S			115
# define KEY_D			100
# define KEY_W			119
# define KEY_ESC		65307

# define X		game->map.player_coord.x
# define Y		game->map.player_coord.y
typedef struct s_position
{
	int	x;
	int	y;
}	t_position;

typedef struct t_map
{
	int			valid;
	int			rows;
	int			cols;
	int			n_collects;
	int			n_exits;
	int			n_players;
	t_position	player_coord;
	char		**loaded;
	char		**floodfill;
}	t_map;

typedef struct s_img
{
	void	*img_ptr;
	int		x;
	int		y;
}	t_img;

typedef struct s_game
{
	void	*mlx;
	void	*mlx_win;
	int		n_moves;
	t_map	map;
	t_img	wall;
	t_img	collectable;
	t_img	background;
	t_img	exit;
	t_img	open_exit;
	t_img	player;
}	t_game;

void	check_args(int argc, char *argv, t_game *game, size_t len);
void	check_boundaries(t_game *game);
void	check_empty_line(char *map, t_game *game);
void	check_map_chars(char *tmp_map, t_game *game);
void	count_map_elems(char *map, t_game *game);
void	check_map_shape(t_game *game);
void	count_moves(t_game *game);
void	create_window(t_game *game);
void	error_msg(char *msg, t_game *game);
void	floodfill(int x, int y, t_game *game);
void	free_game(t_game *game);
void	free_map(t_game *game);
void	get_sprite(t_game *game, int x, int y);
void	init_game_vars(t_game *game);
void	init_map(t_game *game, char *argv);
void	init_sprites(t_game *game);
int		invalid_boundary(char *row);
int		key_hook(int usr_input, t_game *game);
t_img	load_sprite(void *ptr, t_game *game, char *xpm);
void	initial_position(t_game *game);
char	*map_concat(char **s1, const char *s2);
void	move_player(int new_y, int new_x,t_game *game);
void	parse_map(char *map, t_game *game);
int		render_game(t_game *game);
void	render_sprite(t_game *game, t_img sprite, int x, int y);
void	validate_map(char *map, t_game *game);
void	verify_floodfill(t_game *game);
#endif