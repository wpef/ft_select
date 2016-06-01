#include "ft_select.h"

int	read_commands(t_infos *infos)
{
	char *buf;

	buf = ft_strnew(3); 
	if (infos->files == NULL)
		return (-1);
	while (read(0, buf, 3) > 0)
	{
		if (buf[0] == 27 && !buf[1])
			return (0);
		else if (buf[0] == 27 && buf[1] == 91)
			cursor_commands(buf[2], infos);
		else if (buf[0] == 32 && buf[1] == 0)
			select_it(infos);
		else if (buf[0] == 127 && buf[1] == 0)
			return (delete_it(infos));
	//	else if (buf[0] == 10)
	//		return (slect_return(infos);
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

int	delete_it(t_infos *infos)
{
	infos->old_pos = infos->cr_pos->next;
	if (infos->nbfiles == 1)
		exit(0); //un jolie return ICI
	free_node(infos->cr_pos, infos);
	make_unloop(infos->files);
	get_filepos(infos);
	infos->nbfiles--;
	run_select(infos);
	return (1);
}

/*
** XX FLECHES :
** XX up	: 27/91/65
** XX down	: 27/91/66
** XX right: 27/91/67
** XX left	: 27/91/68
**
** SPC	: 32/91/67 //FAUX
** DEL1	: 127/91/68 //FAUX
** DEL2	: 126/91/51 //FAUX
** RETN	: 10/91/68 //FAUX
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
