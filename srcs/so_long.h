/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mumontei <mumontei@42.sp.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 10:54:43 by mumontei          #+#    #+#             */
/*   Updated: 2022/10/14 15:51:44 by mumontei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <X11/X.h>
# include <stdlib.h>
# include <X11/keysym.h>
# include <fcntl.h>

# define WIN_WIDTH 640
# define WIN_HEIGHT 480

# define COLLECT_XPM	"imgs/collectable"
# define BGROUND_XPM	"imgs/back-ground.xpm"
# define EXIT_XPM		"imgs/exit.xpm"
# define OPEN_XPM		"imgs/open-exit.xpm"
# define PLAYER_XPM		"imgs/player-front.xpm"
# define WALL_XPM		"imgs/wall.xpm"

typedef struct s_position
{
	int	x;
	int	y;
}	t_position;

typedef struct t_map
{
	int			alloc;
	int			rows;
	int			cols;
	int			n_collects;
	int			n_exits;
	int			n_players;
	t_position	player_coord;
	char		**loaded;
}	t_map;

typedef struct s_img
{
	void	*xpm_ptr;
	int		x;
	int		y;
}	t_img;

typedef struct s_game
{
	void	*mlx;
	void	*mlx_win;
	int		n_moves;
	int		map_alloc;
	t_map	map;
	t_img	wall;
	t_img	collectable;
	t_img	background;
	t_img	exit;
	t_img	open_exit;
	t_img	player;
}	t_game;

void	init_map(t_game *game, char *argv);
void	validate_map(char *map, t_game *game);
char	*map_concat(char **s1, const char *s2);
void	check_map_shape(t_game *game);
void	check_args(int argc, char *argv, t_game *game, size_t len);
void	check_map_chars(char *tmp_map, t_game *game);
void	check_empty_line(char *map, t_game *game);
void	count_map_elems(char *map, t_game *game);
void	free_allocated_memory(t_game *game);
void	free_map(t_game *game);
void	error_msg(char *msg, t_game *game);
void	parse_map(char *map, t_game *game);
#endif