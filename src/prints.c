#include "ft_select.h"

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
		ft_putstr_fd(ptr->file, 2);
	if (ptr->slect == 1)
		tputs(tgetstr("me", NULL), 1, putchar_std);
	tputs(tgoto(tgetstr("cm", NULL), ptr->x_pos, ptr->y_pos), 1, putchar_std);
	return (1);
}

int	print_ulfile(t_files *ptr)
{
		if (tputs(tgetstr("us", NULL), 1, putchar_std) == ERR)
			return (-1);
		ft_putstr_fd(ptr->file, 2);
		if (tputs(tgetstr("ue", NULL), 1, putchar_std) == ERR)
			return (-1);
		return (1);
}
