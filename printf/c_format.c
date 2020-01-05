/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_format.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-azra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/08 14:31:35 by ael-azra          #+#    #+#             */
/*   Updated: 2019/12/13 21:57:36 by ael-azra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		flag_width(long nb, char *s, int *i)
{
	if (nb != 0)
	{
		if (nb < 0 && nb < -1)
		{
			nb *= -1;
			if (nb > 1)
				print_space(i, nb, s, ' ');
			return (1);
		}
		else
		{
			print_space(i, nb, s, ' ');
			return (1);
		}
	}
	return (0);
}

int		c_format(struct s_flags flag, va_list args)
{
	long	nb;
	char	*s;
	int		i[2];

	i[0] = (flag.width < -1) ? 1 : flag.align;
	i[1] = 1;
	if (!(s = (char *)malloc(sizeof(char) + 1)))
		return (-7);
	s[0] = va_arg(args, int);
	s[1] = '\0';
	if (flag.digits > 1)
	{
		nb = flag.digits;
		print_space(i, nb, s, ' ');
	}
	else if (flag_width(flag.width, s, i))
	{
		free(s);
		return (0);
	}
	else
		ft_putchar(s[0], 1);
	free(s);
	return (0);
}
