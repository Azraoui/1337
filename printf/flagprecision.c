/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flagprecision.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-azra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/08 11:44:01 by ael-azra          #+#    #+#             */
/*   Updated: 2019/12/13 11:35:52 by ael-azra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		flagprecision(const char *str, int *i, va_list args)
{
	int width;

	if (str[*i] == '.')
	{
		*i += 1;
		if (str[*i] == ft_isdigit(str[*i]))
		{
			width = flagdigits(str, i);
			return (width);
		}
		else if (str[*i] == '*')
		{
			width = flagwidth(str, i, args);
			return (width);
		}
		else
			return (0);
	}
	else
		return (-1);
}
