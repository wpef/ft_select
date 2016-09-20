/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   padcontrol.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-monc <fde-monc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/20 15:48:56 by fde-monc          #+#    #+#             */
/*   Updated: 2016/09/20 16:24:39 by fde-monc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

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

int	select_all(t_infos *infos)
{
	t_files	*ptr;

	make_unloop(infos->files);
	ptr = infos->files;
	while (ptr != NULL)
	{
		ptr->slect = 1;
		ptr = ptr->next;
	}
	make_loop(infos->files);
	return (run_select(infos));
}

int	deselect_all(t_infos *infos)
{
	t_files	*ptr;

	make_unloop(infos->files);
	ptr = infos->files;
	while (ptr != NULL)
	{
		ptr->slect = 0;
		ptr = ptr->next;
	}
	make_loop(infos->files);
	return (run_select(infos));
}

int	inv_select(t_infos *infos)
{
	t_files *ptr;

	make_unloop(infos->files);
	ptr = infos->files;
	while (ptr != NULL)
	{
		if (ptr->slect == 1)
			ptr->slect = 0;
		else if (ptr->slect == 0)
			ptr->slect = 1;
		ptr = ptr->next;
	}
	make_loop(infos->files);
	return (run_select(infos));
}
