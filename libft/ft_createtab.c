/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_createtab.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-monc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/22 15:16:18 by hponcet           #+#    #+#             */
/*   Updated: 2015/12/22 20:09:20 by hponcet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		**ft_createtab(int x, int y)
{
	char		**tab;
	int			i;

	i = 0;
	tab = (char**)malloc(sizeof(char*) * (x + 1));
	if (!tab)
		return (NULL);
	tab[x] = NULL;
	while (i < x)
	{
		tab[i] = ft_strnew(y);
		if (!tab[i])
			return (NULL);
		tab[i][y] = '\0';
		i++;
	}
	return (tab);
}
