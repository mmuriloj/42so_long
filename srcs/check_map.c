/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mumontei <mumontei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 15:58:54 by mumontei          #+#    #+#             */
/*   Updated: 2022/10/28 00:35:31 by mumontei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "../libft/libft.h"

void	check_map(char *map, t_game *game)
{
	check_empty_line(map, game);
	check_chars(map, game);
	count_elems(map, game);
	game->map.loaded = ft_split(map, '\n');
	game->map.floodfill = ft_split(map, '\n');
	game->map.valid = 1;
}

void	check_shape(t_game *game)
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
		{
			ft_printf("Error. Map is not rectangular");
			free_map(game);
			free(game);
			exit(0);
		}
		i++;
	}
	game->map.cols = cols;
}

void	check_chars(char *map, t_game *game)
{
	int	i;

	i = 0;
	while (map[i])
	{
		if (!(map[i] == 48 || map[i] == 49 || map[i] == '\n' \
		|| map[i] == 67 || map[i] == 69 || map[i] == 80))
		{
			ft_printf("Mapfile error: char '%c' forbidden", (char) map[i]);
			free(map);
			free(game);
			exit(0);
		}	
		i++;
	}
}

void	count_elems(char *map, t_game *game)
{
	int	i;

	i = 0;
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
	{
		ft_printf("Map must contain\n1 starting position\n1 exit \
		\nat least, 1 collectible\n");
		free(map);
		free(game);
		exit(0);
	}
}

void	check_empty_line(char *map, t_game *game)
{
	int	i;
	int	len;

	len = ft_strlen(map);
	if (map[0] == '\n' || map[len - 1] == '\n')
	{
		ft_printf("Error. Map starts/ends with an empty line.");
		free(map);
		free(game);
		exit(0);
	}	
	i = 0;
	while (map[i + 1] != '\0')
	{
		if (map[i] == '\n' && map[i + 1] == '\n')
		{
			ft_printf("Map has an empty line somewhere in between.\n");
			free(map);
			free(game);
			exit(0);
		}
		i++;
	}
}
