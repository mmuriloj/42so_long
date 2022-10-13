/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mumontei <mumontei@42.sp.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 17:07:53 by mumontei          #+#    #+#             */
/*   Updated: 2022/10/13 17:51:49 by mumontei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "../libft/libft.h"

void	validate_map(t_game *game, char *map)
{
	parse_map(map, game);
	check_game_params(map);
}

void	parse_map(char *map, t_game *game)
{
	int		map_fd;
	char	*row;
	char	tmp_map;

	tmp_map = ft_strdup("");
	game->map.rows = 0;
	map_fd = open(map, O_RDONLY);
	if (map_fd == -1)
	{
		error_msg("Error. Map could not be loaded.", game);
		return (0);
	}
	while(1)
	{
		row = get_next_line(map_fd);
		if (row == NULL)
			break ;
		tmp_map = map_concat(&tmp_map, row);
		game->map.rows++;
		free(row);
	}
	check_empty_line(map, game);
	game->map_alloc = 1;
}

void check_empty_line(char *map, t_game *game)
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
			error_msg("Error. Map starts/ends with an empty line.", game);
		i++;
	}