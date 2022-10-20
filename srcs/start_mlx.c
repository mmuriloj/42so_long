/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_mlx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mumontei <mumontei@42.sp.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 18:28:54 by mumontei          #+#    #+#             */
/*   Updated: 2022/10/20 18:55:03 by mumontei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "../libft/libft.h"

void	start_mlx(t_game *game)
{
	game->mlx = mlx_init();
	game->mlx_win = mlx_new_window(game->mlx, game->map.cols * XPM_WIDTH,\
	game->map.rows * XPM_HEIGHT, "@mumontei's So Long");
	if(game->mlx == NULL || game->mlx_win)
		error_msg("Error. Couldn't start Minilibx.", game);
}