/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u_format.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-azra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 15:21:01 by ael-azra          #+#    #+#             */
/*   Updated: 2019/12/13 17:36:40 by ael-azra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		u_format(struct s_flags flag, va_list args)
{
	unsigned		int	nb;
	int					i;

	i = -2;
	nb = va_arg(args, unsigned int);
	if (flag.precision >= 0)
		i = print_precision_2(nb, flag.precision);
	if (i == -7)
		return (i);
	if (i != -2 || ((flag.digits != 0 || flag.width > 1) && i != -2))
		return (cheack_flag(i, flag, nb, 0));
	else if (flag.digits > 1 || flag.width != 0)
		return (cheack_flag_1(flag, nb, 0));
	else
		u_putnbr(nb);
	return (0);
}
