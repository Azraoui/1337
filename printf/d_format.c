/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d_format.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-azra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 14:42:55 by ael-azra          #+#    #+#             */
/*   Updated: 2019/12/13 17:22:19 by ael-azra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		d_format(struct s_flags flag, va_list args)
{
	int		nb;
	int		i;
	int		sign;

	i = -2;
	nb = va_arg(args, int);
	sign = (nb < 0) ? 1 : 0;
	nb *= (sign == 1) ? -1 : 1;
	if (flag.precision >= 0)
		i = print_precision_2(nb, flag.precision);
	if (i == -7)
		return (i);
	if (i != -2 || ((flag.digits != 0 || flag.width > 1) && i != -2))
		return (cheack_flag(i, flag, nb, sign));
	else if (flag.digits > 1 || flag.width != 0)
		return (cheack_flag_1(flag, nb, sign));
	else
	{
		if (sign)
			ft_putnbr(-nb);
		else
			ft_putnbr(nb);
	}
	return (0);
}
