/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game_vars.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mumontei <mumontei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 01:06:25 by mumontei          #+#    #+#             */
/*   Updated: 2022/10/28 01:07:11 by mumontei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "../libft/libft.h"

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
