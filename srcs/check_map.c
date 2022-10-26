/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mumontei <mumontei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 15:58:54 by mumontei          #+#    #+#             */
/*   Updated: 2022/10/26 16:35:19 by mumontei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "../libft/libft.h"

void	check_map_shape(t_game *game)
{
	int	i;
	int	cols;
	int	len1;
	int	len2;

	cols = ft_strlen((char *) game->map.loaded[0]);
	i = 0;
	while ((char *)game->map.loaded[i + 1] && (char *)game->map.loaded[i])
	{
		len1 = ft_strlen((char *) game->map.loaded[i]);
		len2 = ft_strlen((char *) game->map.loaded[i +1]);
		if (len1 != len2)
			error_msg("Error. Map is not rectangular", game);
		i++;
	}
	game->map.cols = cols;
}

void	check_map_chars(char *map, t_game *game)
{
	int	i;

	i = 0;
	while (map[i])
	{
		if (!(map[i] == 48 || map[i] == 49 || map[i] == '\n' \
		|| map[i] == 67 || map[i] == 69 || map[i] == 80))
		{
			ft_printf("Mapfile error: char '%c' ", (char) map[i]);
			error_msg("forbidden", game);
		}	
		i++;
	}
}

void	count_map_elems(char *map, t_game *game)
{
	int	i;

	i = 0;
	game->map.n_players = 0;
	game->map.n_collects = 0;
	game->map.n_exits = 0;
	game->map.n_collects = 0;
	while (map[i] != '\0')
	{
		if (map[i] == 'C')
			game->map.n_collects++;
		else if (map[i] == 'E')
			game->map.n_exits++;
		else if (map[i] == 'P')
			game->map.n_players++;
		i++;
	}
	if (game->map.n_collects < 1 || game->map.n_exits != 1 \
	|| game->map.n_players != 1)
		error_msg("Map must contain 1 starting \
position, 1 exit and, at least, 1 collectible", game);
}
