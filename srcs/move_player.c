/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mumontei <mumontei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 18:22:23 by mumontei          #+#    #+#             */
/*   Updated: 2022/10/24 22:28:16 by mumontei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "../libft/libft.h"

void	initial_position(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	while (x < game->map.cols)
	{
		y = 0;
		while (y < game->map.rows)
		{
			if (game->map.loaded[y][x] == 'P')
			{
				X = x;
				Y = y;
			}
			y++;
		}
		x++;
	}
}

void	move_player(int new_y, int new_x, t_game *game)
{
	int	old_x;
	int	old_y;

	old_x = X;
	old_y = Y;
	if (game->map.loaded[new_y][new_x] == 'E' && game->map.n_collects == 0)
		free_game(game);
	else if ((game->map.loaded[new_y][new_x] == '0')
	|| (game->map.loaded[new_y][new_x] == 'C'))
	{
		game->map.loaded[old_y][old_x] = '0';
		if (game->map.loaded[new_y][new_x] == 'C')
			game->map.n_collects--;
		X = new_x;
		Y = new_y;
		game->map.loaded[new_y][new_x] = 'P';
		game->n_moves++;
		ft_printf("number of moves: %d\n", game->n_moves);
		render_game(game);
	}
}
