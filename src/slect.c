#include "ft_select.h"

int	get_termdata(t_term *term)
{
	char	*termtype;
	int		success;

	termtype = getenv("TERM");
	if (termtype == NULL)
		ft_putendl("Specify a terminal type with `export TERM <yourtype>'.\n");
	success = tgetent(NULL, termtype);
	if (success < 0)
		ft_putendl("Could not access the termcap data base.\n"); //error
	else if (success == 0)
		ft_sdebug("Terminal type % is not defined.\n", termtype); //error
	else if (tcgetattr(0, &term->termios) == -1)
		ft_putendl("Term info not reached"); //error
	tcgetattr(0, &term->origin_termios);
	return (success);
}

/*
** THIS FUNCTION SETS THE TERMINAL TO CANONIQUE MODE WHICH MEANS THE 
** FUCTION READ WILL RETURN EACH CHARACTERS STROKE INDEPENDANTLY
*/

int	set_newterm(t_termios *term)
{
	term->c_lflag &= ~(ICANON);
	term->c_lflag &= ~(ECHO);
	term->c_cc[VMIN] = 1;
	term->c_cc[VTIME] = 0;
	if (tcsetattr(0, TCSADRAIN, term) == -1)
		return (-1);
	return (1);
}

int	init_newterm(t_term *term)
{
	if (get_termdata(term) == -1)
		return (-1);
	if (set_newterm(&term->termios) == -1)
		return (-1);
	return (1);
}

int main(int ac, char **av)
{
	t_infos	infos;

	if (init_newterm(&infos.term) == -1)
		return (-1);
	if (get_infos(ac, av, &infos) == -1)
		return (-1);
	run_select(&infos);
	//debug
	//end of
	tcsetattr(0, TCSADRAIN, &infos.term.origin_termios);
	return (1);
}

//	t_files *ptr;
//	ptr = infos.files;
//	printf("WINDOW is %d ROWS && %d COL\n", infos.ws_row, infos.ws_col);
//	printf("%d ROWS && %d COL of %d char width\n", infos.nb_row, infos.nb_col, infos.width);
//	while (ptr != NULL)
//	{
//		printf("%s :: row %d col %d\n", ptr->file, ptr->y_pos, ptr->x_pos);
//		ptr = ptr->next;
//	}
