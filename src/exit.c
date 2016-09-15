#include "ft_select.h"

void	sl_exit(int success, t_infos *infos)
{
	if (infos == NULL)
		infos = &g_infos;
	tcsetattr(0, TCSADRAIN, &infos->term.origin_termios);
	exit(success);
}

void	sl_suspend()
{
	char	c[2];

	signal(SIGTSTP, SIG_DFL);
	c[0] = g_infos.term.origin_termios.c_cc[VSUSP];
	c[1] = '\0';
	ioctl(0, TIOCSTI, c);
	clean(1);
}

void		sl_cont()
{
	clean(1);
	sl_signal();
	set_newterm(&g_infos.term.termios);
	get_winsize(&g_infos);
	init_print(&g_infos);
}
