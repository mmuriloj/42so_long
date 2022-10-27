/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mumontei <mumontei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 09:34:34 by mumontei          #+#    #+#             */
/*   Updated: 2022/10/27 18:04:27 by mumontei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "../libft/libft.h"

void	check_args(int argc, char *argv, t_game *game, size_t len)
{
	int	fd;

	if (argc > 2)
	{
		ft_printf("Too many arguments\n");
		free(game);
		exit(0);
	}
	if (len < 5 || argv[len - 4] != '.' || argv[len - 3] != 'b' \
	|| argv[len - 2] != 'e' || argv[len - 1] != 'r')
	{
		ft_printf("Error. Map file extension must be .ber\n");
		free(game);
		exit(0);
	}
	fd = open(argv, O_RDONLY);
	if (fd == -1)
	{
		ft_printf("Error. File not found\n");
		free(game);
		exit(0);
	}
	else
		game->map.valid = 1;
	close(fd);
}

void	init_game_vars(t_game *game)
{
	game->map.valid = 0;
	game->map.rows = 0;
	game->map.cols = 0;
	game->map.n_collects = 0;
	game->map.n_exits = 0;
	game->map.n_players = 0;
	game->map.loaded = NULL;
	game->map.floodfill = NULL;
	game->map.player_coord.x = 0;
	game->map.player_coord.y = 0;
	game->mlx = 0;
	game->mlx_win = 0;
	game->n_moves = 0;
}
