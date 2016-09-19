/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sdebug.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-monc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/06 15:09:54 by fde-monc          #+#    #+#             */
/*   Updated: 2016/03/16 22:12:06 by fde-monc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_sdebug(char *str, char *s)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] != '%')
			ft_putchar(str[i]);
		if (str[i] == '%')
		{
			if (s == NULL)
				return (ft_putendl("NULL"));
			while (s[j])
			{
				ft_putchar(s[j]);
				j++;
			}
		}
		i++;
	}
	ft_putchar('\n');
}
