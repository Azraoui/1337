/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cheack_flag1_hexa.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-azra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 11:15:03 by ael-azra          #+#    #+#             */
/*   Updated: 2019/12/13 18:06:09 by ael-azra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		cheack_flag1_hexa(struct s_flags flag, unsigned long nb, char c)
{
	char	*s;
	size_t	len;

	if (!(s = ft_itoa_hexa(c, nb, dec_hex)))
		return (-7);
	len = ft_strlen(s);
	if (flag.zero == 1)
		print_space_2(flag, len, s, '0');
	else
		print_space_2(flag, len, s, ' ');
	free(s);
	return (0);
}
