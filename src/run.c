#include "ft_select.h"

int run_select(t_term *term, t_infos *infos)
{
	if (term == NULL || infos == NULL)
		return (-1);
	clean(1);
	while (42)
	{
		if (check_winsize(infos) == 1)
			print_list(infos);
		else
			ft_putendl("ERROR");
			read_commands(term, infos);
		return (1);
	}
}

int	clean(int fd)
{
	char *str;

	str = tgetstr("cl", NULL);
	tputs(str, 0, (fd == 1 ? putchar_std : putchar_fd));
	return (1);
}

int	print_list(t_infos *infos)
{
	t_files *ptr;

	ptr = infos->files;
	while (ptr != NULL)
	{
		print_file(ptr, infos);
		ptr = ptr->next;
	}
	return (1);
}

int	print_file(t_files *ptr, t_infos *infos)
{
	static int	col = 0;
	int			len;

	ft_putstr(ptr->file);
	col++;
	if (col % infos->max_col == 0)
	{
		ft_putchar('\n');
		return (1);
	}
	len = ptr->len;
	while (len <= infos->maxlen)
	{
		ft_putchar(' ');
		len++;
	}
	return (1);
}

int	putchar_std(int c)
{
	ft_putchar(c);
	return (c);
}

int	putchar_fd(int c)
{
	ft_putchar_fd(c, 3);
	return (c);
}