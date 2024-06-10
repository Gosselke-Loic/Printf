/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgosselk <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 15:38:39 by lgosselk          #+#    #+#             */
/*   Updated: 2023/10/24 15:57:21 by lgosselk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	int		i;
	int		j;
	char	*result;
	int		total_len;

	i = ft_strlen(s1);
	total_len = (i + ft_strlen(s2));
	result = (char *) malloc((total_len + 1) * sizeof(char));
	if (result == NULL)
		return (NULL);
	j = -1;
	while (s1[++j])
		result[j] = (char) s1[j];
	j = -1;
	while (s2[++j])
		result[i + j] = (char) s2[j];
	result[i + j] = '\0';
	return (result);
}
