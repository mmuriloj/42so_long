/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   concat_rows.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mumontei <mumontei@42.sp.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 16:35:19 by mumontei          #+#    #+#             */
/*   Updated: 2022/10/13 17:06:53 by mumontei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "../libft/libft.h"

char *concat_rows(char **l1, char *l2)
{
	char *str;

	if (!l1 || !l2)
		return (NULL);
	str = ft_calloc((ft_strlen(*l1) + ft_strlen(l2)) + 1, sizeof(char));
	if (!str)
		return (NULL);
	ft_strlcat(str, *l1, ft_strlen(*l1));
	ft_strlcat(str, l2, ft_strlen(*l1) + ft_strlen(l2) + 1);
	free(*l1);
	return (str);
}