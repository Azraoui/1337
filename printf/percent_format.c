/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   percent_format.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-azra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 08:56:09 by ael-azra          #+#    #+#             */
/*   Updated: 2019/12/13 17:50:09 by ael-azra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		percent_format(struct s_flags flag)
{
	if (flag.digits > 1)
	{
		if (flag.align == 1 && flag.zero == 1)
			print_space_2(flag, 1, "%", ' ');
		else if (flag.zero == 1)
			print_space_2(flag, 1, "%", '0');
		else
			print_space_2(flag, 1, "%", ' ');
	}
	else if (flag.width != 0)
	{
		if (flag.width < -1 && flag.zero == 1)
			print_space_2(flag, 1, "%", ' ');
		else if (flag.zero == 1)
			print_space_2(flag, 1, "%", '0');
		else
			print_space_2(flag, 1, "%", ' ');
	}
	else
		ft_putchar('%', 1);
	return (0);
}
