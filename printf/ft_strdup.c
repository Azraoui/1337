/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-azra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 14:28:07 by ael-azra          #+#    #+#             */
/*   Updated: 2019/12/14 09:38:32 by ael-azra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_strdup(const char *s1)
{
	char	*s2;
	int		len;
	int		i;

	i = 0;
	if (s1)
	{
		len = ft_strlen((char *)s1);
		s2 = (char *)malloc(sizeof(char) * (1 + len));
		if (s2 == NULL)
			return (0);
		while (i < len)
		{
			s2[i] = s1[i];
			i++;
		}
		s2[i] = '\0';
	}
	else
		s2 = ft_strdup("(null)\0");
	return (s2);
}
