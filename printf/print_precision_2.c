/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_precision_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-azra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 18:22:30 by ael-azra          #+#    #+#             */
/*   Updated: 2019/12/13 16:55:53 by ael-azra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		print_precision_2(long nb, int pr)
{
	char	*s;
	size_t	len;

	if (nb == 0 && pr == 0)
		return (-1);
	if (!(s = ft_itoa(nb)))
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
