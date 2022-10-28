/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mumontei <mumontei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 09:34:34 by mumontei          #+#    #+#             */
/*   Updated: 2022/10/28 02:44:56 by mumontei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "../libft/libft.h"

void	check_args(int argc, char *argv, t_game *game, size_t len)
{
	int	fd;

	if (argc > 2)
	{
		ft_printf("Error. Too many arguments\n");
		free(game);
		exit(0);
	}
	if (len < 5 || argv[len - 4] != '.' || argv[len - 3] != 'b' \
	|| argv[len - 2] != 'e' || argv[len - 1] != 'r')
	{
		ft_printf("Error. Map file extension must be .ber\n");
		free(game);
		exit(0);
	}
	fd = open(argv, O_RDONLY);
	if (fd == -1)
	{
		ft_printf("Error. File not found\n");
		free(game);
		exit(0);
	}
	else
		game->map.valid = 1;
	close(fd);
}
