/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-azra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 12:45:11 by ael-azra          #+#    #+#             */
/*   Updated: 2019/07/22 12:45:14 by ael-azra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_strcat(char *dest, char *src)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (!dest)
		return (0);
	if ((dest[i] && src[j]) != '\0')
	{
		while (dest[i] != '\0')
			i++;
		while (src[j] != '\0')
			dest[i++] = src[j++];
		dest[i] = '\0';
	}
	return (dest);
}
