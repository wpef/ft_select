#include "ft_select.h"

void	signal_handler(int sig)
{
	if (sig == SIGWINCH)
	{
		ft_putendl("IN");
		return (signal_sigwinch());
	}
}

void	signal_sigwinch(void)
{
	if (g_infos.files->loop)
		make_unloop(g_infos.files);
	clean(2);
	get_winsize(&g_infos);
	if (check_winsize(&g_infos) == 1)
	{
		init_print(&g_infos);
		return ;
	}
	else
		wait_winsize(&g_infos);
}
