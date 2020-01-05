/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cheack_flag_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-azra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 10:25:07 by ael-azra          #+#    #+#             */
/*   Updated: 2019/12/13 18:20:36 by ael-azra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		print_zero(long nb, struct s_flags flag, size_t len)
{
	char	*s;

	if (!(s = ft_itoa(nb)))
		return (-7);
	ft_putchar('-', 1);
	print_space_2(flag, len, s, '0');
	free(s);
	return (0);
}

int		cheack_flag_1(struct s_flags flag, long nb, int sign)
{
	char	*s;
	size_t	len;
	int		x;

	x = 0;
	s = (sign) ? ft_itoa(-nb) : ft_itoa(nb);
	if (!s)
		return (-7);
	len = ft_strlen(s);
	if (flag.zero == 1)
	{
		if (sign)
			x = print_zero(nb, flag, len);
		else
			print_space_2(flag, len, s, '0');
	}
	else
		print_space_2(flag, len, s, ' ');
	free(s);
	return (x = (x == -7) ? x : 0);
}
