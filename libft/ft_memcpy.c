/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgosselk <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 15:18:25 by lgosselk          #+#    #+#             */
/*   Updated: 2023/10/26 14:07:03 by lgosselk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char	*cp_dest;
	char	*cp_src;

	if (!dest && !src)
		return (dest);
	cp_dest = (char *) dest;
	cp_src = (char *) src;
	while (n > 0)
	{
		*cp_dest = *cp_src;
		n--;
		cp_src++;
		cp_dest++;
	}
	return (dest);
}
