/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x_format.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-azra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 09:48:35 by ael-azra          #+#    #+#             */
/*   Updated: 2019/12/13 18:07:27 by ael-azra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		x_format(struct s_flags flag, va_list args)
{
	unsigned	int	nb;
	int				i;

	i = -2;
	nb = va_arg(args, unsigned int);
	if (flag.precision >= 0)
		i = print_precision_hexa(nb, flag.precision, flag.conversion);
	if (i == -7)
		return (i);
	if (i != -2 || ((flag.digits != 0 || flag.width > 1) && i != -2))
		return (cheack_flag_hexa(i, flag, nb, flag.conversion));
	else if (flag.digits > 1 || flag.width != 0)
		return (cheack_flag1_hexa(flag, nb, flag.conversion));
	else
		ft_hexa(nb, flag.conversion);
	return (0);
}
