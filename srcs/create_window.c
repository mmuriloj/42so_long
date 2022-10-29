/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_window.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mumontei <mumontei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 18:28:54 by mumontei          #+#    #+#             */
/*   Updated: 2022/10/29 00:49:44 by mumontei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "../libft/libft.h"

void	create_window(t_game *game)
{
	int	w;
	int	h;

	w = game->map.cols * XPM_WIDTH;
	h = game->map.rows * XPM_HEIGHT;
	game->mlx = mlx_init();
	if (game->mlx == NULL)
	{
		ft_printf("Error.\nCouldn't start Minilibx.", game);
		free_map(game);
		free(game);
		exit(0);
	}
	game->mlx_win = mlx_new_window(game->mlx, w, h, "@mumontei's So Long");
	if (game->mlx_win == NULL)
	{
		free_map(game);
		free(game);
		free(game->mlx);
		error_msg("Error.\nCouldn't start window.", game);
	}
}

t_img	load_sprite(void *ptr, t_game *game, char *xpm)
{
	t_img	spr;

	spr.img_ptr = mlx_xpm_file_to_image(ptr, xpm, &spr.x, &spr.y);
	if (spr.img_ptr == NULL)
		error_msg("Error.\nSprite couldn't be found.", game);
	return (spr);
}

void	init_sprites(t_game *game)
{
	void	*ptr;

	ptr = game->mlx;
	game->background = load_sprite(ptr, game, BGROUND_XPM);
	game->collectable = load_sprite(ptr, game, COLLECT_XPM);
	game->wall = load_sprite(ptr, game, WALL_XPM);
	game->player = load_sprite(ptr, game, PLAYER_XPM);
	game->exit = load_sprite(ptr, game, EXIT_XPM);
	game->open_exit = load_sprite(ptr, game, OPEN_XPM);
}
