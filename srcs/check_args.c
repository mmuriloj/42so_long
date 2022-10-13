/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mumontei <mumontei@42.sp.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 09:34:34 by mumontei          #+#    #+#             */
/*   Updated: 2022/10/07 09:34:47 by mumontei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "../libft/libft.h"

void	check_args(int argc, char *argv, t_game *game)
{
	int	i;

	game->map_alloc = 1;
	if (argc < 2)
	{
		write(1, "Invalid number of arguments.\nMap file is missing\n", 49);
		game->map_alloc = 0;
	}
	else if (argc > 2)
	{
		write(1, "Too many arguments.\n", 20);
		game->map_alloc = 0;
	}
	i = ft_strlen(argv) - 1;
	if (i < 4)
		game->map_alloc = 0;
	if (argv[i - 3] != '.')
		game->map_alloc = 0;
	if (argv[i - 2] != 'b')
		game->map_alloc = 0;
	if (argv[i - 1] != 'e')
		game->map_alloc = 0;
	if (argv[i] != 'r')
		game->map_alloc = 0;
}