#include "ft_select.h"

int	print_file(t_files *ptr, char *opt, t_infos *infos)
{
	int			len;

	if (opt)
	{
		if (ft_strcmp(opt, "ul") == 0)
			print_ulfile(ptr);
	}
	else
		ft_putstr(ptr->file);
	len = ptr->len;
	while (len <= infos->maxlen)
	{
		ft_putchar(' ');
		len++;
	}
	return (1);
}

int	print_ulfile(t_files *ptr)
{
		if (tputs(tgetstr("us", NULL), 1, putchar_std) == ERR)
			return (-1);
		ft_putstr(ptr->file);
		if (tputs(tgetstr("ue", NULL), 1, putchar_std) == ERR)
			return (-1);
		return (1);
}
