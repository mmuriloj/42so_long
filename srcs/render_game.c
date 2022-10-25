/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mumontei <mumontei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 20:27:30 by mumontei          #+#    #+#             */
/*   Updated: 2022/10/24 21:44:42 by mumontei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "../libft/libft.h"

int	render_game(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->map.rows)
	{
		x = 0;
		while (x < game->map.cols)
		{
			get_sprite(game, y, x);
			x++;
		}
		y++;
	}
	initial_position(game);
	return (0);
}

void	get_sprite(t_game *game, int y, int x)
{
	char	c;

	c = game->map.loaded[y][x];
	if (c == '1')
		render_sprite(game, game->wall, x, y);
	else if (c == '0')
		render_sprite(game, game->background, x, y);
	else if (c == 'P')
		render_sprite(game, game->player, x, y);
	else if (c == 'C')
		render_sprite(game, game->collectable, x, y);
	else
	{
		if (game->map.n_collects > 0)
			render_sprite(game, game->exit, x, y);
		else
			render_sprite(game, game->open_exit, x, y);
	}
}

void	render_sprite(t_game *game, t_img sprite, int col, int row)
{
	mlx_put_image_to_window(game->mlx, game->mlx_win, \
	sprite.img_ptr, col * sprite.x, row * sprite.y);
}
