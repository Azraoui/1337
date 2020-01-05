/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_format.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-azra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/08 14:31:46 by ael-azra          #+#    #+#             */
/*   Updated: 2019/12/13 16:05:43 by ael-azra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		s_format(struct s_flags flag, va_list args)
{
	char	*s;
	size_t	len;
	long	i;

	if (!(s = ft_strdup(va_arg(args, char *))))
		return (-7);
	len = ft_strlen(s);
	i = len;
	if (flag.precision >= 0)
		i = print_precision(&s, flag.precision, len);
	if (flag.digits > i || flag.width != 0)
		print_space_2(flag, i, s, ' ');
	else
		ft_putstr(s);
	free(s);
	s = NULL;
	return (0);
}
