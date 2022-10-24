/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   user_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mumontei <mumontei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 17:19:03 by mumontei          #+#    #+#             */
/*   Updated: 2022/10/24 21:33:51 by mumontei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "../libft/libft.h"

void count_moves(t_game *game)
{
	game->n_moves = 32;

	ft_printf("%d", game->n_moves);
}

int	key_hook(int usr_input, t_game *game)
{
	if (usr_input == KEY_A)
		move_player(Y, X - 1, game);
	if (usr_input == KEY_S)
		move_player(Y + 1, X, game);
	if (usr_input == KEY_D)
		move_player(Y, X + 1, game);
	if (usr_input == KEY_W)
		move_player(Y - 1, X, game);
	if (usr_input == KEY_ESC)
		error_msg("you have pressed ESC key", game);
	return (0);
}


