/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mumontei <mumontei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 16:46:58 by mumontei          #+#    #+#             */
/*   Updated: 2022/10/04 23:52:37 by mumontei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "../libft/libft.h"

void	init_map(t_game *game, char *mapfile)
{
	int		map_fd;
	char	*line_temp;
	char	*map_temp;

	map_fd = open(mapfile, O_RDONLY);
	if (map_fd == -1)
	{
		write(1, "Error. Map couldn't be loaded.\n", 31);
		return ;
	}
	map_temp = ft_strdup("");
	game->map.rows = 0;
	while (1)
	{
		line_temp = get_next_line(map_fd);
		if (line_temp == NULL)
			break ;
		map_temp = map_concat(&map_temp, line_temp);
		game->map.rows++;
	}
	close(map_fd);
	free(map_temp);
}

char	*map_concat(char **s1, const char *s2)
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
