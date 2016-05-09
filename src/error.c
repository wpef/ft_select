#include "ft_select.h"

int	sl_error(char *idi, t_term *term, t_term *infos)
{
	if (ft_strcmp("winsize", id) == 0)
	{
		get_winsize(infos);
		return (run_select(term, infos));
	}
	else
	{
		ft_sdebug("UNEXEPCTED ERROR : %", id);
		return (0);
	}
}
