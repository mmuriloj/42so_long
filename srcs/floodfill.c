/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floodfill.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mumontei <mumontei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 18:04:08 by mumontei          #+#    #+#             */
/*   Updated: 2022/10/29 02:38:37 by mumontei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "../libft/libft.h"

void	floodfill(int new_x, int new_y, t_game *game)
{
	if (game->map.floodfill[new_y][new_x] == 'P' || \
		game->map.floodfill[new_y][new_x] == 'C' || \
		game->map.floodfill[new_y][new_x] == '0')
	{
		game->map.floodfill[new_y][new_x] = 'V';
		floodfill(new_x + 1, new_y, game);
		floodfill(new_x - 1, new_y, game);
		floodfill(new_x, new_y + 1, game);
		floodfill(new_x, new_y - 1, game);
	}
}

void	verify_floodfill(t_game *game)
{
	int	i;
	int	j;

	floodfill(game->map.player_coord.x, game->map.player_coord.y, game);
	i = 0;
	while (i < game->map.rows)
	{
		j = 0;
		while (j < game->map.cols)
		{
			if (game->map.floodfill[i][j] == 'C')
			{
				game->map.valid = 0;
				ft_printf("Error. Path is not valid.\n");
				free_map(game);
				free(game);
				exit(0);
			}
			j++;
		}
		i++;
	}
}
