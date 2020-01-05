/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_space_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-azra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 11:08:59 by ael-azra          #+#    #+#             */
/*   Updated: 2019/12/13 21:38:32 by ael-azra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	print_space_2(struct s_flags flag, long i, char *s, char c)
{
	long	nb;
	int		x[2];

	x[0] = (flag.width < -i) ? 1 : flag.align;
	x[1] = i;
	if (flag.digits > i)
	{
		nb = flag.digits;
		print_space(x, nb, s, c);
	}
	else if (flag.width != 0)
	{
		nb = flag.width;
		if (nb < 0 && nb < -i)
		{
			nb *= -1;
			print_space(x, nb, s, ' ');
		}
		else if (nb > i)
			print_space(x, nb, s, c);
		else
			ft_putstr(s);
	}
	else
		ft_putstr(s);
}
