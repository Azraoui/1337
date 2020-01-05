/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u_putnbr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-azra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 12:30:02 by ael-azra          #+#    #+#             */
/*   Updated: 2019/12/13 15:23:47 by ael-azra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	u_putnbr(unsigned int nb)
{
	unsigned int	i;
	unsigned int	x;

	i = nb;
	x = 1;
	while ((i / 10) != 0)
	{
		i /= 10;
		x = x * 10;
	}
	while (x > 0)
	{
		ft_putchar((nb / x) + 48, 1);
		nb %= x;
		x /= 10;
	}
	if (x)
		ft_putchar(nb + 48, 1);
}
