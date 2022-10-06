/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mumontei <mumontei@42.sp.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 18:41:31 by mumontei          #+#    #+#             */
/*   Updated: 2022/10/05 19:07:03 by mumontei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "../libft/libft.h"

void	error_msg(char *msg, t_game *game)
{
	if (game->map_alloc == 1)
		game->map_alloc = 0;
	ft_printf("%s\n", msg);
	free(game);
	exit(EXIT_FAILURE);
}
