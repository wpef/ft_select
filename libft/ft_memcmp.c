/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-monc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 15:45:48 by fde-monc          #+#    #+#             */
/*   Updated: 2015/12/08 15:41:36 by fde-monc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*cs1;
	unsigned char	*cs2;
	size_t			i;

	cs1 = (unsigned char *)s1;
	cs2 = (unsigned char *)s2;
	i = 0;
	if (s1 == NULL && s2 == NULL)
		return (0);
	while (i < n && cs1[i] == cs2[i])
		i++;
	if (i == n || (cs1[i] == '\0' && cs2[i] == '\0'))
		return (0);
	return (cs1[i] - cs2[i]);
}
