/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floodfill.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mumontei <mumontei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 18:04:08 by mumontei          #+#    #+#             */
/*   Updated: 2022/10/25 23:23:23 by mumontei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "../libft/libft.h"

void	floodfill(int x, int y, t_game *game)
{
	if (game->map.floodfill[y][x] == 'P' || \
		game->map.floodfill[y][x] == 'E' || \
		game->map.floodfill[y][x] == 'C' || \
		game->map.floodfill[y][x] == '0')
	{
		game->map.floodfill[y][x] = 'V';
		floodfill(x + 1, y, game);
		floodfill(x - 1, y, game);
		floodfill(x, y + 1, game);
		floodfill(x, y - 1, game);
	}
}

void	verify_floodfill(t_game *game)
{
	int	i;
	int	j;

	floodfill(X, Y, game);
	i = 0;
	while (i < game->map.rows)
	{
		j = 0;
		while (j < game->map.cols)
		{
			if (game->map.floodfill[i][j] == 'C' \
			|| game->map.floodfill[i][j] == 'E')
			{
				game->map.valid = 0;
				error_msg("Error. Path is not valid.", game);
			}
			j++;
		}
		i++;
	}
}
