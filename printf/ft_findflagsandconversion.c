/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_findflagsandconversion.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-azra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 15:37:41 by ael-azra          #+#    #+#             */
/*   Updated: 2019/12/13 15:28:23 by ael-azra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

struct s_flags	ft_findflagsandconversion(const char *str, int *i, va_list args)
{
	struct s_flags flag;

	flag.align = flagalign(str, i);
	flag.zero = flagzero(str, i);
	if (str[*i] == '-')
	{
		while (str[*i] == '-' || str[*i] == '0')
		{
			flag.align = flagalign(str, i);
			flag.zero = flagzero(str, i);
		}
	}
	flag.digits = flagdigits(str, i);
	flag.width = flagwidth(str, i, args);
	flag.precision = flagprecision(str, i, args);
	flag.conversion = find_conversion(str, i);
	return (flag);
}
