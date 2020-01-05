/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_format.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-azra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 12:54:49 by ael-azra          #+#    #+#             */
/*   Updated: 2019/12/14 09:51:20 by ael-azra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		p_format(struct s_flags flag, va_list args)
{
	unsigned long	nb;
	char			*s;
	char			*str;
	size_t			len;

	nb = va_arg(args, unsigned long);
	if (!(str = ft_strdup("0x\0")))
		return (-7);
	if (flag.precision == 0 && nb == 0)
		s = ft_strdup("0x\0");
	else
		s = ft_strjoin(str, ft_itoa_hexa('p', nb, dec_hex));
	if (!s)
	{
		free(str);
		return (-7);
	}
	len = ft_strlen(s);
	if (flag.digits > (long)len || flag.width != 0)
		print_space_2(flag, len, s, ' ');
	else
		ft_putstr(s);
	free(s);
	free(str);
	return (0);
}
