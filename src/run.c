#include "ft_select.h"

int run_select(t_infos *infos)
{
	if (init_print(infos) == -1)
		return (-1);
	if (infos->old_pos != NULL)
	{
		curs_to(infos->old_pos, infos);
		infos->old_pos = NULL;
	}
	make_loop(infos->files);
	read_commands(infos);
	return (1);
}

int	init_print(t_infos *infos)
{
	if (infos->files == NULL)
		return (-1);
	clean(1);
	if (check_winsize(infos) == 1)
	{
		//open_newterm(infos);
		print_list(infos);
		cursor_origin(infos);
		print_file(infos->files, "ul", infos);
		cursor_origin(infos);
		return (1);
	}
	ft_putendl("ERROR");
	return (sl_error("winsize", infos));
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
	int		col;

	col = 0;
	ptr = infos->files;
	while (ptr != NULL)
	{
		print_file(ptr, NULL, infos);
		ptr = ptr->next;
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
