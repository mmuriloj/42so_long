/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mumontei <mumontei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 18:41:31 by mumontei          #+#    #+#             */
/*   Updated: 2022/10/14 23:54:27 by mumontei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "../libft/libft.h"

void	error_msg(char *msg, t_game *game)
{
	if (game->map_alloc == 1)
		free_map(game);
	ft_printf("%s\n", msg);
	free(game);
	exit(EXIT_FAILURE);
}

void	free_map(t_game *game)
{
	int	row;

	game->map_alloc = 0;
	row = 0;
	while (row < game->map.rows)
	{
		free(game->map.loaded[row]);
		row++;
	}
	free(game->map.loaded);
}
