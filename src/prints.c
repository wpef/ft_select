/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prints.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-monc <fde-monc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/15 18:01:38 by fde-monc          #+#    #+#             */
/*   Updated: 2016/09/20 15:14:37 by fde-monc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int	cursor_origin(t_infos *infos)
{
	char *res;

	if (infos == NULL)
		return (-1);
	res = tgetstr("cm", NULL);
	if (tputs(tgoto(res, 0, 0), 1, putchar_std) == ERR)
		return (-1);
	infos->cr_pos = infos->files;
	infos->cr_col = 0;
	infos->cr_row = 0;
	return (1);
}

int	print_file(t_files *ptr, char *opt, t_infos *infos)
{
	if (infos->files == NULL)
		return (-1);
	tputs(tgoto(tgetstr("cm", NULL), ptr->x_pos, ptr->y_pos), 1, putchar_std);
	if (ptr->slect == 1)
		tputs(tgetstr("mr", NULL), 1, putchar_std);
	if (opt && ft_strcmp(opt, "ul") == 0)
		print_ulfile(ptr);
	else
		print_stdfile(ptr);
	if (ptr->slect == 1)
		tputs(tgetstr("me", NULL), 1, putchar_std);
	tputs(tgoto(tgetstr("cm", NULL), ptr->x_pos, ptr->y_pos), 1, putchar_std);
	return (1);
}

int	print_ulfile(t_files *ptr)
{
	if (tputs(tgetstr("us", NULL), 1, putchar_std) == ERR)
		return (-1);
	if (ptr->type == 1)
		ft_putstr_fd("\x1B[31m", 2);
	else if (ptr->type == 2)
		ft_putstr_fd("\x1B[33m", 2);
	ft_putstr_fd(ptr->file, 2);
	ft_putstr_fd("\x1B[0m", 2);
	if (tputs(tgetstr("ue", NULL), 1, putchar_std) == ERR)
		return (-1);
	return (1);
}

int	print_stdfile(t_files *ptr)
{
	if (ptr->type == 1)
		ft_putstr_fd("\x1B[31m", 2);
	else if (ptr->type == 2)
		ft_putstr_fd("\x1B[33m", 2);
	ft_putstr_fd(ptr->file, 2);
	ft_putstr_fd("\x1B[0m", 2);
	return (1);
}

int	curs_to(t_files *dest, t_infos *infos)
{
	t_files	*old;

	old = infos->cr_pos;
	if (old == NULL || dest == NULL || infos == NULL)
		return (-1);
	print_file(old, NULL, infos);
	print_file(dest, "ul", infos);
	infos->cr_pos = dest;
	return (1);
}

int	clean(int fd)
{
	char *str;

	str = tgetstr("cl", NULL);
	tputs(str, 0, (fd == 1 ? putchar_std : putchar_fd));
	return (1);
}
