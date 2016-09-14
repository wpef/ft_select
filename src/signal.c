#include "ft_select.h"

void	sl_signal(void)
{
	int	i;

	i = 0;
	while (i < 32)
	{
		signal(i, signal_handler);
		i++;
	}
}

void	signal_handler(int sig)
{
	if (sig == SIGWINCH)
		return (signal_sigwinch());
	if (sig == SIGINT || sig == SIGQUIT)
		return (sl_exit(0, &g_infos));
	if (sig == SIGTSTP)
		return (sl_suspend());
	if (sig == SIGCONT)
		return (sl_cont());
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
