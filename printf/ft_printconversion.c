/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printconversion.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-azra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 14:56:47 by ael-azra          #+#    #+#             */
/*   Updated: 2019/12/13 15:54:51 by ael-azra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_printconversion(const char *str, va_list args, int i)
{
	struct s_flags	flag;
	int				j;

	if (str[i] == '%')
	{
		ft_putchar('%', 1);
		return (i + 1);
	}
	flag = ft_findflagsandconversion(str, &i, args);
	if (flag.digits == -7)
		return (-7);
	j = (print_format(flag, args) == -7) ? -7 : i;
	return (j);
}
