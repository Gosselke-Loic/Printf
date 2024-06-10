/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgosselk <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 09:50:03 by lgosselk          #+#    #+#             */
/*   Updated: 2023/10/31 13:26:36 by lgosselk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static unsigned int	ft_check_type(const char c, void *arg)
{
	unsigned int	i;

	i = 0;
	if (c == 'c')
		i += ft_print_char((char)arg);
	if (c == 's')
		i += ft_print_string((char *)arg);
	if (c == 'p')
		i += ft_print_pointer((void *)arg);
	if (c == 'd' || c == 'i')
		i += ft_print_int((int)arg);
	if (c == 'u')
		i += ft_print_unsigned((unsigned int)arg);
	if (c == 'x')
		i += ft_print_hex((unsigned int)arg, 87);
	if (c == 'X')
		i += ft_print_hex((unsigned int)arg, 55);
	return (i);
}

int	ft_printf(const char *str, ...)
{
	va_list			args;
	unsigned int	count;

	count = 0;
	va_start(args, str);
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			if (ft_strchr("cspdiuxX", *str))
				count += ft_check_type(*str, va_arg(args, void *));
			else if (*str == '%')
				count += ft_print_char('%');
		}
		else
			count += ft_print_char(*str);
		str++;
	}
	va_end(args);
	return (count);
}
