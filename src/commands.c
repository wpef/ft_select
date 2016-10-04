/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-monc <fde-monc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/15 17:54:14 by fde-monc          #+#    #+#             */
/*   Updated: 2016/10/04 12:43:40 by fde-monc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int		read_commands(t_infos *infos)
{
	char *buf;

	buf = ft_strnew(3);
	if (infos->files == NULL)
		return (-1);
	while (read(0, buf, 3) > 0)
	{
		if (buf[0] == 27 && !buf[1])
		{
			clean(1);
			sl_exit(1, infos);
		}
		else if (buf[0] == 10)
			return (slect_return(infos));
		else
			sl_hook(buf, infos);
		ft_bzero(buf, 3);
	}
	return (1);
}

void	sl_hook(char *buf, t_infos *infos)
{
	if (buf[0] == 1 && buf[1] == 0)
		select_all(infos);
	else if (buf[0] == 4 && buf[1] == 0)
		deselect_all(infos);
	else if (buf[0] == 9 && buf[1] == 0)
		inv_select(infos);
	else if (buf[0] == 27 && buf[1] == 91)
		cursor_commands(buf[2], infos);
	else if (buf[0] == 32 && buf[1] == 0)
		select_it(infos);
	else if ((buf[0] == 127 || buf[0] == 126) && buf[1] == 0)
		delete_it(infos);
}

int		slect_return(t_infos *infos)
{
	t_files	*ptr;
	int		first;

	first = 0;
	ptr = infos->files;
	make_unloop(infos->files);
	clean(1);
	clean(2);
	while (ptr != NULL)
	{
		if (ptr->slect == 1)
		{
			if (first > 0)
				ft_putchar(' ');
			first++;
			ft_putstr(ptr->file);
		}
		ptr = ptr->next;
	}
	sl_exit(1, infos);
	return (1);
}
