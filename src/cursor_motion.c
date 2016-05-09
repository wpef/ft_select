#include "ft_select.h"

int	cursor_origin(t_infos *infos)
{
	char *res;

	if (infos == NULL)
		return (-1);
	res = tgetstr("cm", NULL);
	if (tputs(tgoto(res, 0, 0), 1, putchar_std) == ERR)
		return (-1);
	infos->cr_col = 0;
	infos->cr_row = 0;
	return (1);
}
