/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flagdigits.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-azra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 16:05:25 by ael-azra          #+#    #+#             */
/*   Updated: 2019/12/13 15:47:28 by ael-azra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		flagdigits(const char *str, int *i)
{
	int				j;
	int				x;
	int				k;
	long			out;
	char			*ptr;

	j = 0;
	x = *i;
	while (str[*i] == ft_isdigit(str[*i]))
		j = (*i += 1) ? j += 1 : 0;
	if (str[*i - 1] == ft_isdigit(str[*i - 1]))
	{
		if (!(ptr = (char *)malloc(sizeof(char) * (j + 1))))
			return (-7);
		k = 0;
		while (j--)
			ptr[k++] = str[x++];
		ptr[k] = '\0';
		out = ft_atoi(ptr);
		free(ptr);
		return (out);
	}
	else
		return (0);
}
