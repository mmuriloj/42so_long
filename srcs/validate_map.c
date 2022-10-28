/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mumontei <mumontei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 17:07:53 by mumontei          #+#    #+#             */
/*   Updated: 2022/10/28 01:12:49 by mumontei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "../libft/libft.h"

void	validate_map(char *argv, t_game *game)
{
	parse_map(argv, game);
	check_shape(game);
	check_boundaries(game);
	initial_position(game);
	verify_floodfill(game);
	if (game->map.valid == 1)
		ft_printf("Map sucessfully loaded!\n");
	else
		error_msg("Error. Map couldn't be loaded.\n", game);
}

void	parse_map(char *argv, t_game *game)
{
	int		fd;
	char	*row;
	char	*tmp_map;

	tmp_map = ft_strdup("");
	fd = open(argv, O_RDONLY);
	if (fd == -1)
	{
		free(tmp_map);
		free(game);
		exit(0);
	}
	while (1)
	{
		row = get_next_line(fd);
		if (row == NULL)
			break ;
		tmp_map = one_line_map(&tmp_map, row);
		free(row);
		game->map.rows++;
	}
	close(fd);
	check_map(tmp_map, game);
	free(tmp_map);
}

char	*one_line_map(char **s1, const char *s2)
{
	char	*s;

	if (!s1 || !s2)
		return (NULL);
	s = (char *)ft_calloc(ft_strlen(*s1) + ft_strlen(s2) + 1, sizeof(char));
	if (!s)
		return (NULL);
	ft_strlcpy(s, *s1, ft_strlen(*s1) + 1);
	ft_strlcat(s, s2, ft_strlen(*s1) + ft_strlen(s2) + 1);
	free(*s1);
	return (s);
}
