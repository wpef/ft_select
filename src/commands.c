#include "ft_select.h"

int	read_commands(t_infos *infos)
{
	char buf[3];

	if (infos == NULL)
		return (-1);
	while (read(0, buf, 3) > 0)
	{
		if (buf[0] == 27)
		{
			if (buf[1] == 0 && buf[2] == 0)
				break;
			if (buf[1] == 91)
				cursor_commands(buf[2], infos);
		}
	}	
	//return (run_select(term, infos));
	return (1);
}


/*
** FLECHES :
** up	: 27/91/65
** down	: 27/91/66
** right: 27/91/67
** left	: 27/91/68
**
** SPC	: 32/91/67
** DEL1	: 127/91/68
** DEL2	: 126/91/51
** RETN	: 10/91/68
** ESC 	: 27/0/0
*/
