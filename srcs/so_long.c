/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mumontei <mumontei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 20:01:51 by mumontei          #+#    #+#             */
/*   Updated: 2022/10/25 23:24:19 by mumontei         ###   ########.fr       */
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
	validate_map(argv[1], game);
	create_window(game);
	init_sprites(game);
	render_game(game);
	mlx_key_hook(game->mlx_win, &key_hook, game);
	mlx_hook(game->mlx_win, Expose, ExposureMask, render_game, game);
	mlx_loop(game->mlx);
	free_game(game);
}
