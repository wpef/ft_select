#include "ft_select.h"

int		get_infos(int ac, char **av, t_infos *infos)
{
	if (ac == 1)
		return (sl_error("usage", NULL, infos));
	get_files(ac, av, infos);
	get_winsize(infos);
	return (1);
}

int		get_winsize(t_infos *infos)
{
	struct winsize w;

	ioctl(0, TIOCGWINSZ, &w);
	infos->ws_row = w.ws_row;
	infos->ws_col = w.ws_col;
	return (1);
}

int		check_winsize(t_infos *infos)
{
	int	max_col;
	int	max_row;
	
	max_col = infos->ws_col / (infos->maxlen + 1);
	max_row = infos->nbfiles / max_col;
	infos->max_col = max_col;
	infos->max_row = max_row;
	if (max_row <= infos->ws_row)
		return (1);
	else
		return (-1);
}
