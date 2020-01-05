/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_hexa.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-azra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 10:00:47 by ael-azra          #+#    #+#             */
/*   Updated: 2019/12/13 14:34:14 by ael-azra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_itoa_hexa(char c, unsigned long nb,
		char (*dec_hex)(char, char, unsigned long))
{
	unsigned	long	tm;
	char				*str;
	int					i;
	int					x;

	tm = nb;
	i = 1;
	while ((tm / 16) != 0)
	{
		tm /= 16;
		i++;
	}
	str = (char *)malloc(sizeof(char) * i + 1);
	x = i;
	str[i--] = '\0';
	while (i >= 0)
	{
		str[i] = (*dec_hex)(str[i], c, (nb % 16));
		nb = nb / 16;
		i--;
	}
	return (str);
}
