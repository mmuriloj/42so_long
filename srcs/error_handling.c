/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mumontei <mumontei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 18:41:31 by mumontei          #+#    #+#             */
/*   Updated: 2022/10/25 05:53:34 by mumontei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "../libft/libft.h"

void	error_msg(char *msg, t_game *game)
{
	if (game->map.valid == 1)
		free_map(game);
	ft_printf("%s\n", msg);
	free(game);
	exit(EXIT_FAILURE);
}

void	free_map(t_game *game)
{
	int	row;

	game->map.valid = 0;
	row = 0;
	while (row < game->map.rows)
	{
		free(game->map.loaded[row]);
		row++;
	}
	free(game->map.loaded);
}

void	free_game(t_game *game)
{
	mlx_destroy_image(game->mlx, game->wall.img_ptr);
	mlx_destroy_image(game->mlx, game->collectable.img_ptr);
	mlx_destroy_image(game->mlx, game->background.img_ptr);
	mlx_destroy_image(game->mlx, game->exit.img_ptr);
	mlx_destroy_image(game->mlx, game->open_exit.img_ptr);
	mlx_destroy_image(game->mlx, game->player.img_ptr);	
	mlx_destroy_window(game->mlx, game->mlx_win);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	free(game);
	exit(0);
}
