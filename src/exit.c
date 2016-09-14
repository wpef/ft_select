#include "ft_select.h"

void	sl_exit(int success, t_infos *infos)
{
	if (infos == NULL)
		infos = &g_infos;
	tcsetattr(0, TCSADRAIN, &infos->term.origin_termios);
	exit(success);
}
