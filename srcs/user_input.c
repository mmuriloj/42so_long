/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   user_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mumontei <mumontei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 17:19:03 by mumontei          #+#    #+#             */
/*   Updated: 2022/10/25 23:24:53 by mumontei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "../libft/libft.h"

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
