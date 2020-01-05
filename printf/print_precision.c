/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_precision.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-azra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 10:45:31 by ael-azra          #+#    #+#             */
/*   Updated: 2019/12/13 12:24:08 by ael-azra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		print_precision(char **s, int p, size_t len)
{
	int		i;

	i = 0;
	if (p == 0)
	{
		*(*s) = '\0';
		return (0);
	}
	else if ((size_t)p < len)
	{
		i = p;
		*(*s + i) = '\0';
		return (i);
	}
	else
		return (len);
}
