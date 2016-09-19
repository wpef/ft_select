/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-monc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 15:49:13 by fde-monc          #+#    #+#             */
/*   Updated: 2015/12/08 18:54:09 by fde-monc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_case(int n)
{
	int c;

	c = 0;
	if (n < 0)
	{
		c++;
		n = -n;
	}
	while (n > 0)
	{
		n = n / 10;
		c++;
	}
	return (c);
}

char		*ft_itoa(int n)
{
	int		c;
	char	*res;
	int		d;

	d = n;
	if (d == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n == 0 || n == -0)
		return (ft_strdup("0"));
	c = ft_case(n);
	if (n <= 0)
		n = -n;
	res = malloc(sizeof(res) * (c + 1));
	res[c] = '\0';
	while (c > 0)
	{
		c--;
		res[c] = (n % 10) + 48;
		n = n / 10;
	}
	if (d < 0)
		res[0] = '-';
	return (res);
}
