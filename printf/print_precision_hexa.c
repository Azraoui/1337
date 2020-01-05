/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_precision_hexa.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-azra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 11:14:18 by ael-azra          #+#    #+#             */
/*   Updated: 2019/12/13 17:53:15 by ael-azra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		print_precision_hexa(unsigned long nb, int pr, char c)
{
	char	*s;
	size_t	len;

	if (nb == 0 && pr == 0)
		return (-1);
	s = ft_itoa_hexa(c, nb, dec_hex);
	if (!s)
		return (-7);
	len = ft_strlen(s);
	if ((pr <= (long)len))
	{
		free(s);
		return (0);
	}
	else
	{
		free(s);
		return (pr - len);
	}
}
