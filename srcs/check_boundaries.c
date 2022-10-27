/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_boundaries.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mumontei <mumontei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 12:03:39 by mumontei          #+#    #+#             */
/*   Updated: 2022/10/27 01:33:04 by mumontei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "../libft/libft.h"

void	check_boundaries(t_game *game)
{
	int	row;
	int	col;

	row = 1;
	if (invalid_boundary(game->map.loaded[0]) || \
	invalid_boundary(game->map.loaded[game->map.rows - 1]))
	{
		free_map(game);
		free(game);
		ft_printf("Map must be surrounded by walls");
		exit(EXIT_FAILURE);
	}
	else
	{
		while (row < game->map.rows - 1)
		{
			if (game->map.loaded[row][0] != '1' || \
			game->map.loaded[row][game->map.cols - 1] != '1')
			{
				free_map(game);
				free(game);
				ft_printf("Map must be surrounded by walls");
				exit(EXIT_FAILURE);
			}
			row++;
		}
	}
}

int	invalid_boundary(char *row)
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
