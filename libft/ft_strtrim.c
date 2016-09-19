/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-monc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/04 19:54:58 by fde-monc          #+#    #+#             */
/*   Updated: 2015/12/05 01:14:21 by fde-monc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isskip(char s)
{
	if (s == ' ' || s == '\t' || s == '\n')
		return (1);
	else
		return (0);
}

char		*ft_strtrim(char const *s)
{
	size_t	start;
	size_t	len;
	char	*res;

	if (!s)
		return (NULL);
	start = 0;
	len = ft_strlen(s);
	while (ft_isskip(s[start]) == 1)
		start++;
	len--;
	while (len > 0 && ft_isskip(s[len]) == 1)
		len--;
	if (len >= start)
		res = ft_strsub(s, start, len - start + 1);
	else
		return (ft_strdup(""));
	return (res);
}
