#include "ft_select.h"

int		get_infos(int ac, char **av, t_infos *infos)
{
	if (ac == 1)
		return (sl_error("usage", infos));
	get_files(ac, av, infos);
	get_winsize(infos);
	get_filepos(infos);
	return (1);
}

int		get_winsize(t_infos *infos)
{
	struct winsize w;
	int	nb_col;
	int	nb_row;

	ioctl(0, TIOCGWINSZ, &w);
	infos->ws_row = w.ws_row;
	infos->ws_col = w.ws_col;
	nb_col = 1;
	nb_row = infos->nbfiles;
	while (nb_row >= infos->ws_row)
	{
		nb_col++;
		nb_row = nb_row - infos->ws_row;
	}
	infos->nb_col = nb_col;
	infos->nb_row = infos->ws_row;
	return (1);
}

int		check_winsize(t_infos *infos)
{
	if (infos->nb_row <= infos->ws_row &&
		((infos->nb_col * infos->width) <= infos->ws_col))
		return (1);
	else
		return (-1);
}
