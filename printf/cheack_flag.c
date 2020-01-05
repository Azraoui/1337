/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cheack_flag.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-azra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 08:38:57 by ael-azra          #+#    #+#             */
/*   Updated: 2019/12/13 22:08:13 by ael-azra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		out_space(struct s_flags flag)
{
	if (flag.digits > 0)
		while (flag.digits--)
			ft_putchar(' ', 1);
	else if (flag.width != 0)
	{
		if (flag.width < 0)
			flag.width *= -1;
		while (flag.width--)
			ft_putchar(' ', 1);
	}
	return (0);
}

int		out_space_1(struct s_flags flag, int sign, unsigned long nb)
{
	char	*s;
	size_t	len;

	s = (sign) ? ft_itoa(-nb) : ft_itoa(nb);
	if (!s)
		return (-7);
	len = ft_strlen(s);
	print_space_2(flag, len, s, ' ');
	free(s);
	return (0);
}

char	*print_pre(int sign, int out_pre, unsigned long nb, size_t len)
{
	char	*s;
	char	*ns;
	int		i;

	i = 0;
	if (!(ns = ft_itoa(nb)))
		return (0);
	if (!(s = (char *)malloc(sizeof(char) * (len + out_pre + 1))))
		return (0);
	if (sign)
	{
		s[i++] = '-';
		while (out_pre--)
			s[i++] = '0';
	}
	else
	{
		while (out_pre--)
			s[i++] = '0';
	}
	s[i] = '\0';
	s = ft_strcat(s, ns);
	free(ns);
	return (s);
}

int		out_space_2(struct s_flags flag, int sign,
		unsigned long nb, int out_pre)
{
	char	*s;
	char	*st;
	size_t	len;

	st = (sign) ? ft_itoa(-nb) : ft_itoa(nb);
	if (!st)
		return (-7);
	len = ft_strlen(st);
	free(st);
	if (!(s = print_pre(sign, out_pre, nb, len)))
		return (-7);
	print_space_2(flag, len + out_pre, s, ' ');
	free(s);
	return (0);
}

int		cheack_flag(int i, struct s_flags flag, unsigned long nb, int sign)
{
	if (i == -1)
		return (out_space(flag));
	else if (i == 0)
		return (out_space_1(flag, sign, nb));
	else if (i > 0)
		return (out_space_2(flag, sign, nb, i));
	return (0);
}
