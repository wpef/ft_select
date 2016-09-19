/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-monc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 17:29:02 by fde-monc          #+#    #+#             */
/*   Updated: 2015/11/27 19:44:16 by fde-monc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t		len;
	char		*s2;

	if (!s1)
		return (NULL);
	len = ft_strlen(s1);
	s2 = ft_strnew(len);
	if (!s2)
		return (NULL);
	s2 = ft_strcpy(s2, s1);
	return (s2);
}
