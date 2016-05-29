#include "ft_select.h"

int	read_commands(t_infos *infos)
{
	char *buf;

	buf = ft_strnew(2); 
	if (infos == NULL)
		return (-1);
	while (read(0, buf, 3) > 0)
	{
		if (buf[0] == 27)
		{
			if (buf[1] == '\0')
				return (0);
			if (buf[1] == 91)
				cursor_commands(buf[2], infos);
		}
		else if (buf[0] == 32 && buf[1] == 0)
			select_it(infos);
		ft_bzero(buf, 3); 
	}	
	//return (run_select(term, infos));
	return (1);
}

int	select_it(t_infos *infos)
{
	if (infos->cr_pos->slect == 0)
		infos->cr_pos->slect = 1;
	else 
		infos->cr_pos->slect = 0;
	curs_down(infos);
	return (1);
}

/*
** XX FLECHES :
** XX up	: 27/91/65
** XX down	: 27/91/66
** XX right: 27/91/67
** XX left	: 27/91/68
**
** SPC	: 32/91/67
** DEL1	: 127/91/68
** DEL2	: 126/91/51
** RETN	: 10/91/68
** XX ESC : 27/0/0 XX
*/


/*
DEBUG POUR AFFICHER LES TOUCHES 

		int i = 0;
		while (buf[i])
		{
			printf("buf[%d] == %d\n", i, buf[i]);
			i++;
		}
		i = 0;
		ft_putendl("");
*/
