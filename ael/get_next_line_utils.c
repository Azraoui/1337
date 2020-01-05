/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-azra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 13:14:13 by ael-azra          #+#    #+#             */
/*   Updated: 2019/11/15 09:35:33 by ael-azra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strdup(const char *s1)
{
	char	*s2;
	int		len;
	int		i;

	i = 0;
	len = ft_strlen((char*)s1);
	s2 = (char*)malloc(sizeof(char) * len + 1);
	if (s2 == NULL)
		return (0);
	while (i < len)
	{
		s2[i] = s1[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}

char	*ft_strchr(const char *s, int c)
{
	int i;

	i = ft_strlen((char*)s);
	if (c == '\0')
		return ((char*)s + i);
	while (*s && *s != c)
		s++;
	if (*s == '\0')
		return (NULL);
	return ((char*)s);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	size_t	s1l;
	size_t	s2l;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	s1l = ft_strlen((char*)s1);
	s2l = ft_strlen((char*)s2);
	if (!(str = (char*)malloc((s1l + s2l + 1) * sizeof(char))))
		return (NULL);
	while (s1[i] != '\0')
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
		str[i++] = s2[j++];
	str[i] = '\0';
	return (str);
}
