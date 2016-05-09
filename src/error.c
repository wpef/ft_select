#include "ft_select.h"

int	sl_error(char *id, t_infos *infos)
{
	if (ft_strcmp("winsize", id) == 0)
	{
		get_winsize(infos);
		return (run_select(infos));
	}
	else if (ft_strcmp("usage", id) == 0)
	{
		ft_putendl("usage :\tft_select\n\t./ft_select [file1, file2, file3, ...]");
		return (-1);
	}
	else
	{
		ft_sdebug("UNEXEPCTED ERROR : %", id);
		return (-1);
	}
}
