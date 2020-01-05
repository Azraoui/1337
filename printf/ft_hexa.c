/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-azra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 11:10:17 by ael-azra          #+#    #+#             */
/*   Updated: 2019/12/11 14:57:02 by ael-azra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	print_hexa(int i, unsigned int *ptr, char c)
{
	int	j;
	int n;

	j = 0;
	n = (c == 'X') ? 55 : 87;
	while (i--)
	{
		if (ptr[j] < 10)
			ft_putchar(ptr[j++] + 48, 1);
		else
			ft_putchar(ptr[j++] + n, 1);
	}
}

int		ft_hexa(unsigned int nb, char c)
{
	unsigned int	*ptr;
	int				i;
	unsigned int	tm;
	int				x;

	i = 1;
	tm = nb;
	while ((tm / 16) != 0)
	{
		tm /= 16;
		i++;
	}
	if (!(ptr = (unsigned int *)malloc(sizeof(unsigned int) * i)))
		return (0);
	x = i;
	while (i--)
	{
		ptr[i] = nb % 16;
		nb = nb / 16;
	}
	print_hexa(x, ptr, c);
	free(ptr);
	return (0);
}
