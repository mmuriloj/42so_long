/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mumontei <mumontei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 17:07:53 by mumontei          #+#    #+#             */
/*   Updated: 2022/10/14 23:57:27 by mumontei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "../libft/libft.h"

void	validate_map(char *map, t_game *game)
{
	parse_map(map, game);
	check_map_shape(game);
}

void	parse_map(char *map, t_game *game)
{
	int		fd;
	char	*row;
	char	*tmp_map;

	tmp_map = ft_strdup("");
	game->map.rows = 0;
	fd = open(map, O_RDONLY);
	if (fd == -1)
		error_msg("Error. Map could not be loaded.", game);
	while (1)
	{
		row = get_next_line(fd);
		if (row == NULL)
			break ;
		tmp_map = map_concat(&tmp_map, row);
		free(row);
		game->map.rows++;
	}
	close(fd);
	game->map.loaded = ft_split(tmp_map, '\n');
	game->map_alloc = 1;
	check_empty_line(tmp_map, game);
	check_map_chars(tmp_map, game);
	count_map_elems(tmp_map, game);
	free(tmp_map);
}

void	check_empty_line(char *map, t_game *game)
{
	int	i;
	int	len;

	len = ft_strlen(map);
	if (map[0] == '\n' || map[len - 1] == '\n')
		error_msg("Error. Map starts/ends with an empty line.", game);
	i = 0;
	while (map[i + 1] != '\0')
	{
		if (map[i] == '\n' && map[i + 1] == '\n')
			error_msg("Map has an empty line somewhere in between.", game);
		i++;
	}
}
