#include "ft_select.h"

int	sl_error(char *id, t_infos *infos)
{
	if (ERROR("winsize"))
	{
		get_winsize(infos);
		return (run_select(infos));
	}
	else if (ERROR("usage"))
	{
		ft_putendl("usage :\tft_select");
		ft_putendl("\t./ft_select [file1, file2, file3, ...]");
		return (-1);
	}
	else
		return (sl_termerror(id, NULL));
}

int	sl_termerror(char *id, char *termtype)
{
	ft_putendl("ERROR :\tft_select");
	if (ERROR("not set"))
	{
		ft_putstr("\tSpecify a terminal type ");
		ft_putendl("with 'export TERM <yourtype>'.");
	}
	else if (ERROR("terminfo"))
		ft_putendl("\t Could not access the terminfo data base.");
	else if (ERROR("type"))
		ft_sdebug("\tTerminal type % is not define.", termtype);
	else if (ERROR("info"))
		ft_putendl("\tTerm info not reached");
	else	
		ft_sdebug("UNEXEPCTED ERROR :\tft_select\n\t%", id);
	return (-1);
}
