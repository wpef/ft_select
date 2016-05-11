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

int	curs_right(t_infos *infos)
{
	t_files	*file;
	
	file = infos->cr_pos;
	print_file(file, NULL, infos);
	infos->cr_pos = file->next;
	file = file->next;
	tputs(tgoto(tgetstr("cm", NULL), file->x_pos, file->y_pos), 1, putchar_std);
	print_file(file, "ul", infos);
	tputs(tgoto(tgetstr("cm", NULL), file->x_pos, file->y_pos), 1, putchar_std);
	return (1);
}

int	curs_left(t_infos *infos)
{
	t_files	*file;
	
	file = infos->cr_pos;
	print_file(file, NULL, infos);
	infos->cr_pos = file->prev;
	file = file->prev;
	tputs(tgoto(tgetstr("cm", NULL), file->x_pos, file->y_pos), 1, putchar_std);
	print_file(file, "ul", infos);
	tputs(tgoto(tgetstr("cm", NULL), file->x_pos, file->y_pos), 1, putchar_std);
	return (1);
}

int	curs_down(t_infos *infos)
{
	t_files	*file;
	int i;

	i = 1;
	file = infos->cr_pos;
	print_file(file, NULL, infos);
	while (i <= infos->max_col)
	{
		infos->cr_pos = file->next;
		file = file->next;
		i++;
	}
	tputs(tgoto(tgetstr("cm", NULL), file->x_pos, file->y_pos), 1, putchar_std);
	print_file(file, "ul", infos);
	tputs(tgoto(tgetstr("cm", NULL), file->x_pos, file->y_pos), 1, putchar_std);
	return (1);
}

int	curs_up(t_infos *infos)
{
	t_files	*file;
	int i;

	i = 1;
	file = infos->cr_pos;
	print_file(file, NULL, infos);
	while (i <= infos->max_col)
	{
		infos->cr_pos = file->prev;
		file = file->prev;
		i++;
	}
	tputs(tgoto(tgetstr("cm", NULL), file->x_pos, file->y_pos), 1, putchar_std);
	print_file(file, "ul", infos);
	tputs(tgoto(tgetstr("cm", NULL), file->x_pos, file->y_pos), 1, putchar_std);
	return (1);
}

