/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_boundaries.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mumontei <mumontei@42.sp.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 12:03:39 by mumontei          #+#    #+#             */
/*   Updated: 2022/10/18 16:22:07 by mumontei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "../libft/libft.h"

void check_boundaries(t_game *game)
{
	int	row;
	int	col;

	row = 1;
	if (invalid_boundary(game->map.loaded[0]) || \
	invalid_boundary(game->map.loaded[game->map.rows-1]))
		error_msg("Map must be surrounded by walls", game);
	else
	{
		while (row < game->map.rows - 1)
		{
			if (game->map.loaded[row][0] != '1' || \
			game->map.loaded[row][game->map.cols - 1] != '1')
				error_msg("Map must be surrounded by walls", game);
			row++;
		}
	}
}

int		invalid_boundary(char *row)
{
	int	i;
	int	invalid_char;
	
	i = 0;
	while (row[i] != '\0')
	{
		if (row[i] == '1')
			invalid_char = 0;
		else
		{
			invalid_char = 1;
			break ;
		}
		i++;
	}
	return (invalid_char);
}