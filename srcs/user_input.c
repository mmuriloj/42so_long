/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   user_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mumontei <mumontei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 17:19:03 by mumontei          #+#    #+#             */
/*   Updated: 2022/10/26 23:03:32 by mumontei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "../libft/libft.h"

int	key_hook(int usr_input, t_game *game)
{
	if (usr_input == KEY_A)
		move_player(game->map.player_coord.y, \
		game->map.player_coord.x - 1, game);
	if (usr_input == KEY_S)
		move_player(game->map.player_coord.y + 1, \
		game->map.player_coord.x, game);
	if (usr_input == KEY_D)
		move_player(game->map.player_coord.y, \
		game->map.player_coord.x + 1, game);
	if (usr_input == KEY_W)
		move_player(game->map.player_coord.y - 1, \
		game->map.player_coord.x, game);
	if (usr_input == KEY_ESC)
	{
		ft_printf("you have pressed ESC key. Quiting game...\n", game);
		free_game(game);
	}
	return (0);
}
