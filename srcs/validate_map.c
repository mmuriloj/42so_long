/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mumontei <mumontei@42.sp.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 17:07:53 by mumontei          #+#    #+#             */
/*   Updated: 2022/10/07 11:33:19 by mumontei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "../libft/libft.h"

void	validate_map(t_game *game, char *map)
{
	int	empt_l;
	int	params;

	empt_l = check_empty_line(map);
	params = check_game_params(map);
}

int		check_empty_line(char *map, t_game *game)
{
	int		i;
	int		map_fd;
	char	*row;

	map_fd = open(map, O_RDONLY);
	if (map_fd == -1)
	{
		error_msg("Error. Map could not be loaded.", game);
		return (0);
	}
	i = 0;
	row = get_next_line(map_fd);
	if(row[0] == '\n')
	{
		error_msg("Error. Map file begins with an empty line.", game);
		free(row);
		close(map_fd);
		return (0);
	}
	while (row != NULL)
	{
		i = 0;
		while (i < ft_strlen(row) - 1)
		if (row[i] == '\n' && row [i + 1] == '\n')
		{
			error_msg("Error. There is an empty line on map.", game);
			free(row);
			close(map_fd);
		}
		row = get_next_line(map_fd);
		free(row);
		i++;
	}
}
