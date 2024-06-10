/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgosselk <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 10:21:36 by lgosselk          #+#    #+#             */
/*   Updated: 2023/10/30 16:59:35 by lgosselk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_int(int nbr)
{
	int				cp_nbr;
	unsigned int	i;

	cp_nbr = nbr;
	i = 1;
	if (nbr < 0 && nbr != -2147483648)
	{
		cp_nbr *= -1;
		i++;
	}
	while (cp_nbr > 9)
	{
		cp_nbr = cp_nbr / 10;
		i++;
	}
	ft_putnbr_fd(nbr, 1);
	if (nbr == -2147483648)
		return (11);
	return (i);
}
