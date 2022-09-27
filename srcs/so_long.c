/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mumontei <mumontei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 20:01:51 by mumontei          #+#    #+#             */
/*   Updated: 2022/09/27 19:07:46 by mumontei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

int	main(void)
{
	t_game *game;

	game = malloc(sizeof(t_game));
	printf("t_game: %lu bytes\n", sizeof(t_game));
	free(game);
	
}

/*{
	t_game	game;

	data.mlx = mlx_init();
	data.mlx_win = mlx_new_window(data.mlx, WIN_WIDTH, WIN_HEIGHT, "mumontei's 42so_long");
	mlx_xpm_file_to_image(data.mlx,  "img/collectable.xpm", data.xpm_size, data.xpm_size);
	//img.img = mlx_new_image(vars.mlx, WIN_WIDTH, WIN_HEIGHT);
	//img.addr = mlx_get_data_addr(img.img, &img.bpp, &img.line_length,
	//							&img.endian);
	//my_mlx_pixel_put(&img, 400, 300, 0x00FF0000);
	//mlx_put_image_to_window(vars.mlx, vars.mlx_win, img.img, 0, 0);
	mlx_hook(data.mlx_win, 2, 1L<<0, destroy_game, &data);
	mlx_loop(data.mlx);
}*/
