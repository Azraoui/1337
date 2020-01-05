/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-azra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 20:55:14 by ael-azra          #+#    #+#             */
/*   Updated: 2019/10/29 22:07:54 by ael-azra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_len(long n)
{
	unsigned long	nb;
	int				j;

	j = 1;
	if (n < 0)
	{
		j++;
		nb = -n;
	}
	else
		nb = n;
	while (nb > 9)
	{
		nb /= 10;
		j++;
	}
	return (j);
}

char	*ft_itoa(long n)
{
	unsigned long	len;
	char			*str;
	unsigned long	nb;

	len = ft_len(n);
	str = (char*)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len--] = '\0';
	if (n < 0)
		nb = -n;
	else
		nb = n;
	while (nb != 0)
	{
		str[len--] = (nb % 10 + 48);
		nb = nb / 10;
	}
	if (n < 0)
		str[0] = '-';
	if (n == 0)
		str[0] = '0';
	return (str);
}
