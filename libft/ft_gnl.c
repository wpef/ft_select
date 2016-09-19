/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-monc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/06 15:41:23 by fde-monc          #+#    #+#             */
/*   Updated: 2016/03/15 15:43:50 by fde-monc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_gnl(int const fd, char **line)
{
	static char	*rest = NULL;
	int			nindex;

	if (fd < 0 || fd == 2 || line == NULL)
		return (-1);
	*line = NULL;
	if (rest)
	{
		nindex = ft_charindex(rest, '\n');
		if (nindex >= 0)
		{
			*line = ft_strsub(rest, 0, nindex);
			rest = gnl_getrest(rest, nindex);
			return (1);
		}
		else
		{
			*line = ft_strdup(rest);
			free(rest);
			rest = NULL;
		}
	}
	if (!rest)
		return (gnl_read(fd, line, &rest));
	return (-1);
}

int		gnl_read(int const fd, char **line, char **rest)
{
	int		nindex;
	int		bytes;
	char	buf[17];
	char	*tmp;

	nindex = ft_charindex(*line, '\n');
	ft_bzero((void *)buf, 17);
	while ((bytes = read(fd, buf, 16)) > 0)
	{
		tmp = ft_strjoin(*line, buf);
		free(*line);
		nindex = ft_charindex(tmp, '\n');
		if (nindex == -1)
			*line = ft_strdup(tmp);
		else
		{
			*line = ft_strsub(tmp, 0, nindex);
			*rest = gnl_getrest(tmp, nindex);
			return (1);
		}
		free(tmp);
		ft_bzero((void *)buf, 17);
	}
	return ((bytes == 0 && nindex == -1) ? 1 : bytes);
}

char	*gnl_getrest(char *s, int nindex)
{
	char	*ret;
	int		i;
	int		len;

	i = 0;
	len = ft_strlen(s);
	nindex++;
	if (nindex < len)
	{
		ret = ft_strnew(len - nindex);
		while (s[nindex + i] != '\0')
		{
			ret[i] = s[nindex + i];
			i++;
		}
		free(s);
		return (ret);
	}
	free(s);
	return (NULL);
}
