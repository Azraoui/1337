/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-azra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 13:13:05 by ael-azra          #+#    #+#             */
/*   Updated: 2019/11/15 09:56:14 by ael-azra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*check_re(char **line, char **re, int fd)
{
	char	*ptr;
	char	*tmp;

	ptr = NULL;
	if (re[fd])
	{
		if ((ptr = ft_strchr(re[fd], '\n')))
		{
			*ptr = '\0';
			*line = ft_strdup(re[fd]);
			tmp = re[fd];
			re[fd] = ft_strdup(++ptr);
			free(tmp);
		}
		else
		{
			*line = ft_strdup(re[fd]);
			free(re[fd]);
			re[fd] = NULL;
		}
	}
	else
		*line = ft_strdup("");
	return (ptr);
}

int		re_ad(int fd, char **line, char *buf)
{
	int			o_r;
	static char	*re[OPEN_MAX];
	char		*ptr;
	char		*tmp;

	ptr = check_re(line, re, fd);
	while (!ptr && (o_r = read(fd, buf, BUFFER_SIZE)))
	{
		buf[o_r] = '\0';
		if ((ptr = ft_strchr(buf, '\n')))
		{
			*ptr = '\0';
			tmp = re[fd];
			re[fd] = ft_strdup(++ptr);
			free(tmp);
		}
		tmp = *line;
		*line = ft_strjoin(*line, buf);
		free(tmp);
	}
	return ((o_r != 0 || ft_strlen(re[fd]) != 0) ? 1 : 0);
}

int		get_next_line(int fd, char **line)
{
	char	*buf;
	int		o_r;

	if (read(fd, NULL, 0) < 0 || BUFFER_SIZE < 0 || line == NULL)
		return (-1);
	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (-1);
	o_r = re_ad(fd, line, buf);
	free(buf);
	return (o_r);
}
