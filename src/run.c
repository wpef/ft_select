/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-monc <fde-monc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/15 18:04:47 by fde-monc          #+#    #+#             */
/*   Updated: 2016/09/15 18:19:31 by fde-monc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int	run_select(t_infos *infos)
{
	if (init_print(infos) == -1)
		return (-1);
	if (infos->old_pos != NULL)
	{
		curs_to(infos->old_pos, infos);
		infos->old_pos = NULL;
	}
	return (read_commands(infos));
}

int	init_print(t_infos *infos)
{
	if (infos->files == NULL)
	{
		return (-1);
	}
	clean(1);
	clean(2);
	if (check_winsize(infos) == 1)
	{
		if (infos->files->loop)
			make_unloop(infos->files);
		cursor_origin(infos);
		print_list(infos);
		cursor_origin(infos);
		print_file(infos->files, "ul", infos);
		cursor_origin(infos);
		make_loop(infos->files);
		return (1);
	}
	return (sl_error("winsize", infos));
}

int	print_list(t_infos *infos)
{
	t_files *ptr;
	int		col;

	col = 0;
	ptr = infos->files;
	get_filepos(infos);
	while (ptr != NULL)
	{
		print_file(ptr, NULL, infos);
		ptr = ptr->next;
	}
	return (1);
}

int	putchar_std(int c)
{
	ft_putchar_fd(c, 2);
	return (c);
}

int	putchar_fd(int c)
{
	ft_putchar_fd(c, 3);
	return (c);
}
