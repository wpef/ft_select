#include "ft_select.h"

void	signal_handler(int sig)
{
	if (sig == SIGWINCH)
		return (signal_sigwinch());
}

void	signal_sigwinch(void)
{
	get_winsize(&infos);
	if (check_winsize(&infos) == 1)
		ft_putendl("SI SI LA FAMILLE");
	else
		ft_putendl ("WTFFFFFFFFFFFFFFFFFFFF");
}	
