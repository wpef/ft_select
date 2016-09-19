/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-monc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/09 12:27:29 by fde-monc          #+#    #+#             */
/*   Updated: 2016/03/06 15:05:15 by fde-monc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*res;
	t_list	*tmp;
	t_list	*tmp2;
	t_list	*lst2;

	tmp = lst->next;
	res = f(lst);
	tmp2 = res;
	lst2 = tmp2;
	while (tmp != NULL)
	{
		tmp2->next = f(tmp);
		tmp = tmp->next;
		tmp2 = tmp2->next;
	}
	tmp2->next = NULL;
	return (lst2);
}
