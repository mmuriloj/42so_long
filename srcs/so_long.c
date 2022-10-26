/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mumontei <mumontei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 20:01:51 by mumontei          #+#    #+#             */
/*   Updated: 2022/10/27 00:13:28 by mumontei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "../libft/libft.h"

int	main(int argc, char **argv)
{
	t_game	*game;

	game = malloc(sizeof(t_game));
	if (!argv[1])
	{
		ft_printf("Map file is missing.");
		free(game);
		exit(0);
	}
	init_game_vars(game);
	check_args(argc, argv[1], game, ft_strlen(argv[1]));
	validate_map(argv[1], game);
	create_window(game);
	init_sprites(game);
	mlx_key_hook(game->mlx_win, &key_hook, game);
	mlx_hook(game->mlx_win, Expose, ExposureMask, render_game, game);
	mlx_loop(game->mlx);
	free_game(game);
}
