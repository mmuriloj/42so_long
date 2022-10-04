/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mumontei <mumontei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 21:06:26 by mumontei          #+#    #+#             */
/*   Updated: 2022/10/04 08:33:44 by mumontei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t len)
{
	char	*char_src;
	char	*char_dest;
	int		i;

	i = 0;
	if (!dest && !src)
		return (NULL);
	char_src = (const char *)src;
	char_dest = (char *)dest;
	while (i < len)
	{
		char_dest[i] = char_src[i];
		i++;
	}
	return (dest);
}
