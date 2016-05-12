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
	else
		return(sl_error("cursor", infos));
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
	int i;

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
	int no_next;

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

