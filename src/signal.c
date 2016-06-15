#include "ft_select.h"

void	signal_handler(int sig)
{
	if (sig == SIGWINCH)
		return (signal_sigwinch());
}

void	signal_sigwinch(void)
{
	get_winsize(&g_infos);
	if (check_winsize(&g_infos) == 1)
		run_select(&g_infos);
	else
		ft_putendl ("WTFFFFFFFFFFFFFFFFFFFF");
}	
