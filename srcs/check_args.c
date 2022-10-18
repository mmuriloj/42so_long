/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mumontei <mumontei@42.sp.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 09:34:34 by mumontei          #+#    #+#             */
/*   Updated: 2022/10/18 10:39:56 by mumontei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "../libft/libft.h"

void	check_args(int argc, char *argv, t_game *game, size_t len)
{
	game->map.valid = 0;
	if (argc > 2)
		error_msg("Too many arguments", game);
	else if (len < 5 || argv[len - 4] != '.' && argv[len - 3] != 'b' \
	&& argv[len - 2] != 'e' && argv[len - 1] != 'r')
		game->map.valid = 0;
	else
		game->map.valid = 1;
}
