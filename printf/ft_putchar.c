/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-azra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 21:37:10 by ael-azra          #+#    #+#             */
/*   Updated: 2019/12/14 16:03:20 by ael-azra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_putchar(char c, int d)
{
	static	int	i;
	int			j;

	if (d == 1)
	{
		i++;
		write(1, &c, 1);
		return (i);
	}
	else if (d == 7)
		return (i);
	else
	{
		j = i;
		j = 0;
		return (i);
	}
}
