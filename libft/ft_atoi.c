/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-monc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 16:21:11 by fde-monc          #+#    #+#             */
/*   Updated: 2015/12/09 15:02:51 by fde-monc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int n;
	int i;
	int csign;

	i = 0;
	n = 0;
	while (ft_ismoreblank(str[i]))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		i++;
		csign = i - 1;
	}
	while (ft_isdigit(str[i]))
	{
		n = n * 10 + (str[i] - 48);
		i++;
	}
	if (str[csign] == '-')
		n = -n;
	return (n);
}
