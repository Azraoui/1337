/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-azra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 14:14:04 by ael-azra          #+#    #+#             */
/*   Updated: 2019/12/13 15:48:47 by ael-azra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_printf(const char *str, ...)
{
	int		i;
	va_list args;

	va_start(args, str);
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			i += 1;
			i = ft_printconversion(str, args, i);
			if (i == -7)
				return (-1);
		}
		else
			ft_putchar(str[i++], 1);
	}
	va_end(args);
	return (ft_putchar(' ', 0));
}
