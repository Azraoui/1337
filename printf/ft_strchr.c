/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-azra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 18:08:29 by ael-azra          #+#    #+#             */
/*   Updated: 2019/11/23 18:12:15 by ael-azra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	ft_strchr(const char *s, int c)
{
	int	i;

	i = ft_strlen((char*)s);
	if (c == '\0')
		return ((char)s + i);
	while (*s && *s != c)
		s++;
	if (*s == '\0')
		return (0);
	return ((char)*s);
}
