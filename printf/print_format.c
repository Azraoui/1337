/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-azra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/08 13:58:38 by ael-azra          #+#    #+#             */
/*   Updated: 2019/12/15 20:30:14 by ael-azra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		print_format(struct s_flags flag, va_list args)
{
	char	c;

	c = flag.conversion;
	if (c == 'c')
		return (c_format(flag, args));
	else if (c == 's')
		return (s_format(flag, args));
	else if (c == 'd')
		return (d_format(flag, args));
	else if (c == 'i')
		return (i_format(flag, args));
	else if (c == 'u')
		return (u_format(flag, args));
	else if (c == '%')
		return (percent_format(flag));
	else if (c == 'x' || c == 'X')
		return (x_format(flag, args));
	else if (c == 'p')
		return (p_format(flag, args));
	return (0);
}
