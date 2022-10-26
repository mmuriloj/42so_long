/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mumontei <mumontei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 09:34:34 by mumontei          #+#    #+#             */
/*   Updated: 2022/10/26 22:24:58 by mumontei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "../libft/libft.h"

void	check_args(int argc, char *argv, t_game *game, size_t len)
{
	if (argc > 2)
		error_msg("Too many arguments", game);
	if (len < 5 || argv[len - 4] != '.' || argv[len - 3] != 'b' \
	|| argv[len - 2] != 'e' || argv[len - 1] != 'r')
		error_msg("Error. Map file extension must be .ber", game);
	else
		game->map.valid = 1;
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
