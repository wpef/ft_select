/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cursor_motion.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-monc <fde-monc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/15 18:01:28 by fde-monc          #+#    #+#             */
/*   Updated: 2016/09/19 15:51:24 by fde-monc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int	cursor_commands(char c, t_infos *infos)
{
	if (c == 65)
		return (curs_up(infos));
	if (c == 66)
		return (curs_down(infos));
	if (c == 67)
		return (curs_right(infos));
	if (c == 68)
		return (curs_left(infos));
	return (-1);
}

int	curs_down(t_infos *infos)
{
	t_files	*file;

	file = infos->cr_pos;
	print_file(file, NULL, infos);
	infos->cr_pos = file->next;
	file = file->next;
	print_file(file, "ul", infos);
	return (1);
}

int	curs_up(t_infos *infos)
{
	t_files	*file;

	file = infos->cr_pos;
	print_file(file, NULL, infos);
	infos->cr_pos = file->prev;
	file = file->prev;
	print_file(file, "ul", infos);
	return (1);
}

int	curs_right(t_infos *infos)
{
	t_files	*file;
	int		i;

	i = 1;
	file = infos->cr_pos;
	print_file(file, NULL, infos);
	if (has_no_next(file, "ri", infos) == 1)
		file = infos->files->prev;
	else
	{
		file = file->next;
		while (file->y_pos != infos->cr_pos->y_pos)
			file = file->next;
		if (file->y_pos != infos->nb_row - 1
			&& file->x_pos < infos->cr_pos->x_pos)
			file = file->next;
	}
	infos->cr_pos = file;
	print_file(file, "ul", infos);
	return (1);
}

int	curs_left(t_infos *infos)
{
	t_files	*file;
	int		no_next;

	file = infos->cr_pos;
	no_next = has_no_next(file, "le", infos);
	print_file(file, NULL, infos);
	if (no_next == 2)
		file = infos->files->prev;
	else
	{
		file = file->prev;
		while (file->y_pos != infos->cr_pos->y_pos)
			file = file->prev;
	}
	infos->cr_pos = file;
	print_file(file, "ul", infos);
	return (1);
}
