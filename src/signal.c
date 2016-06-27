#include "ft_select.h"

void	signal_handler(int sig)
{
	if (sig == SIGWINCH)
		return (signal_sigwinch());
}

void	signal_sigwinch(void)
{
	if (g_infos.files->loop)
		make_unloop(g_infos.files);
	ft_idebug("before : %", g_infos.ws_col);
	get_winsize(&g_infos);
	ft_idebug("after : %\n", g_infos.ws_col);
	sleep(1);
	//if (check_winsize(&g_infos) == 1)
	run_select(&g_infos);
	//else
	//	ft_putendl ("WTFFFFFFFFFFFFFFFFFFFF");
}	
