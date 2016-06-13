#include "ft_select.h"

void	signal_handler(int sig)
{
	if (sig == SIGWINCH)
		return (signal_sigwinch());
}

void	signal_sigwinch(void)
{
	get_winsize(&infos);
	if (check_winsize(&infos))
		ft_putendl("SI SI LA FAMILLE");
}	
