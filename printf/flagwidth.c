/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flagwidth.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-azra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/08 11:31:15 by ael-azra          #+#    #+#             */
/*   Updated: 2019/12/13 11:31:30 by ael-azra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		flagwidth(const char *str, int *i, va_list args)
{
	int width;

	width = 0;
	if (str[*i] == '*')
	{
		width = va_arg(args, int);
		*i += 1;
		return (width);
	}
	else
		return (0);
}
