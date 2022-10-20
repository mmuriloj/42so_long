/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mumontei <mumontei@42.sp.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 20:01:51 by mumontei          #+#    #+#             */
/*   Updated: 2022/10/20 18:56:39 by mumontei         ###   ########.fr       */
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
	/*if (game->map.valid == 0)
	{
		free(game);
		game = NULL;
		return (0);
	}*/
	validate_map(argv[1], game);
	
	ft_printf("valid %d\n", game->map.valid);
	ft_printf("rows %d\n", game->map.rows);
	ft_printf("cols %d\n", game->map.cols);
	ft_printf("n_collects %d\n", game->map.n_collects);
	ft_printf("n_exits %d\n", game->map.n_exits);
	ft_printf("n_players %d\n", game->map.n_players);
	start_mlx(game);
//	free_allocated_memory(game);
}
