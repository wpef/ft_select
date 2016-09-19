/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-monc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 12:13:34 by fde-monc          #+#    #+#             */
/*   Updated: 2015/12/02 20:48:47 by fde-monc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_wordscount(char const *s, char c)
{
	int	i;
	int	cmp;

	i = 0;
	cmp = 0;
	if (s[0] != c && s[0] != '\0')
		cmp++;
	while (s[i])
	{
		while (s[i] != c && s[i] != '\0')
			i++;
		if (s[i] && s[i] == c && (s[i + 1] != c && s[i + 1]))
			cmp++;
		if (s[i])
			i++;
	}
	return (cmp);
}

char		**ft_strsplit(char const *s, char c)
{
	int		i;
	int		strt;
	int		len;
	char	**tab;

	i = 0;
	if (!s)
		return (NULL);
	tab = (char **)malloc(sizeof(char*) * ft_wordscount(s, c) + 1);
	if (!tab)
		return (NULL);
	strt = 0;
	while (i < ft_wordscount(s, c))
	{
		while (s[strt] && s[strt] == c)
			strt++;
		len = 0;
		while (s[strt + len] != c && s[strt + len] != '\0')
			len++;
		tab[i] = ft_strsub(s, strt, len);
		strt = strt + len;
		i++;
	}
	tab[ft_wordscount(s, c)] = NULL;
	return (tab);
}
