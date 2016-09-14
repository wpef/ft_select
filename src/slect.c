#include "ft_select.h"

int	get_termdata(t_term *term)
{
	char	*termtype;
	int		success;

	termtype = getenv("TERM");
	if (termtype == NULL)
		return (sl_termerror("not set", termtype));
	success = tgetent(NULL, termtype);
	if (success == 0)
		return (sl_termerror("type", termtype));
	else if (success < 0)
		return (sl_termerror("terminfo", termtype));
	else if (tcgetattr(0, &term->termios) == -1)
		return (sl_termerror("info", termtype));
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
	sl_signal(SIGWINCH, signal_handler);
	if (init_newterm(&g_infos.term) == -1)
		return (-1);
	if (get_infos(ac, av, &g_infos) == -1)
		return (-1);
	run_select(&g_infos);
	tcsetattr(0, TCSADRAIN, &g_infos.term.origin_termios);
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


/*debug
	t_files *ptr;
	t_files *last;
	ptr = infos.files;
	last = infos.files;
	while (last->next)
		last = last->next;
	while (ptr)
	{
		printf("%s::\tsi %d == %d-1 && %d > %d\n", ptr->file, ptr->col, infos.nb_col, ptr->y_pos, last->y_pos);
		ptr = ptr->next;
	}
	
END OF*/
