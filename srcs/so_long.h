
#ifndef SO_LONG_H

# include <mlx.h>
# include <X11/X.h>
# include <stdlib.h>
# include <X11/keysym.h>


# define SO_LONG_H
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
	int			rows;
	int			cols;
	int			n_collects;
	int			n_exits;
	int			n_players;
	t_position	player_coord;
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
	t_map	map;
	t_img	wall;
	t_img	collectable;
	t_img	background;
	t_img	exit;
	t_img	open_exit;
	t_img	player;
}	t_game;

#endif