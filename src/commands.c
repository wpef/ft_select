/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-monc <fde-monc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/15 17:54:14 by fde-monc          #+#    #+#             */
/*   Updated: 2016/09/15 17:54:21 by fde-monc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int	read_commands(t_infos *infos)
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
			return (-1);
		}
		else if (buf[0] == 27 && buf[1] == 91)
			cursor_commands(buf[2], infos);
		else if (buf[0] == 32 && buf[1] == 0)
			select_it(infos);
		else if ((buf[0] == 127 || buf[0] == 126) && buf[1] == 0)
			return (delete_it(infos));
		else if (buf[0] == 10)
			return (slect_return(infos));
		ft_bzero(buf, 3);
	}
	return (1);
}

int	select_it(t_infos *infos)
{
	if (infos->cr_pos->slect == 0)
		infos->cr_pos->slect = 1;
	else
		infos->cr_pos->slect = 0;
	curs_down(infos);
	return (1);
}

int	delete_it(t_infos *infos)
{
	infos->old_pos = infos->cr_pos->next;
	if (infos->nbfiles == 1)
		sl_exit(0, infos);
	free_node(infos->cr_pos, infos);
	make_unloop(infos->files);
	infos->nbfiles--;
	get_filepos(infos);
	return (run_select(infos));
}

int	slect_return(t_infos *infos)
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
