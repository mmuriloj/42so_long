/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mumontei <mumontei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 21:06:26 by mumontei          #+#    #+#             */
/*   Updated: 2022/05/10 03:27:02 by mumontei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char	*char_src;
	char	*char_dest;

	if (!dest && !src)
		return (NULL);
	char_src = (char *)src;
	char_dest = (char *)dest;
	while (n-- > 0)
		*char_dest++ = *char_src++;
	return (dest);
}
