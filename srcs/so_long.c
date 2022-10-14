/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mumontei <mumontei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 20:01:51 by mumontei          #+#    #+#             */
/*   Updated: 2022/10/14 23:56:13 by mumontei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "../libft/libft.h"

int	main(int argc, char **argv)
{
	t_game	*game;

	game = malloc(sizeof(t_game));
	if (!argv[1])
		error_msg("Map file is missing.", game);
	check_args(argc, argv[1], game, ft_strlen(argv[1]));
	/*if (game->map_alloc == 0)
	{
		free(game);
		game = NULL;
		return (0);
	}*/
	validate_map(argv[1], game);
//	init_map(game, argv[1]);
//	free_allocated_memory(game);
}
