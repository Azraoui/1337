/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_space.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-azra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/08 14:58:59 by ael-azra          #+#    #+#             */
/*   Updated: 2019/12/13 21:29:39 by ael-azra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	print_space(int *x, long nb, char *s, char c)
{
	if (x[0] == 1)
	{
		if (x[1] == 1)
			ft_putchar(s[0], 1);
		else
			ft_putstr(s);
		nb -= x[1];
		while (nb--)
			ft_putchar(c, 1);
	}
	else
	{
		if (nb > x[1])
		{
			nb -= x[1];
			while (nb--)
				ft_putchar(c, 1);
		}
		if (x[1] == 1)
			ft_putchar(s[0], 1);
		else
			ft_putstr(s);
	}
}
