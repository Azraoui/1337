/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cheack_flag_hexa.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-azra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 11:14:50 by ael-azra          #+#    #+#             */
/*   Updated: 2019/12/13 18:18:10 by ael-azra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		out_space_hexa(struct s_flags flag)
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

int		out_space_1_hexa(struct s_flags flag, unsigned long nb, char c)
{
	char	*s;
	size_t	len;

	if (!(s = ft_itoa_hexa(c, nb, dec_hex)))
		return (-7);
	len = ft_strlen(s);
	print_space_2(flag, len, s, ' ');
	free(s);
	return (0);
}

char	*print_pre_hexa(char c, int out_pre, unsigned long nb, size_t len)
{
	char	*s;
	char	*ns;
	int		i;

	i = 0;
	if (!(ns = ft_itoa_hexa(c, nb, dec_hex)))
		return (0);
	if (!(s = (char *)malloc(sizeof(char) * (len + out_pre + 1))))
		return (0);
	while (out_pre--)
		s[i++] = '0';
	s[i] = '\0';
	s = ft_strcat(s, ns);
	free(ns);
	return (s);
}

int		out_space_2_h(struct s_flags flag, char c,
		unsigned long nb, int out_pre)
{
	char	*s;
	char	*st;
	size_t	len;

	if (!(st = ft_itoa_hexa(c, nb, dec_hex)))
		return (-7);
	len = ft_strlen(st);
	free(st);
	if (!(s = print_pre_hexa(c, out_pre, nb, len)))
		return (-7);
	print_space_2(flag, len + out_pre, s, ' ');
	free(s);
	return (0);
}

int		cheack_flag_hexa(int i, struct s_flags flag, unsigned long nb, char c)
{
	if (i == -1)
		return (out_space_hexa(flag));
	else if (i == 0)
		return (out_space_1_hexa(flag, nb, c));
	else if (i > 0)
		return (out_space_2_h(flag, c, nb, i));
	return (0);
}
