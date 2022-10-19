/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mumontei <mumontei@42.sp.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 18:41:31 by mumontei          #+#    #+#             */
/*   Updated: 2022/10/19 16:16:16 by mumontei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "../libft/libft.h"

void	error_msg(char *msg, t_game *game)
{
	if (game->map.valid == 1)
		free_map(game);
	ft_printf("%s\n", msg);
	free(game);
	exit(EXIT_FAILURE);
}

void	free_map(t_game *game)
{
	int	row;

	game->map.valid = 0;
	row = 0;
	while (row < game->map.rows)
	{
		free(game->map.loaded[row]);
		row++;
	}
	free(game->map.loaded);
}

void	free_allocated_memory(t_game *game)
{
	free(game);
}
