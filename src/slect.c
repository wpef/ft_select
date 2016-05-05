#include "libft.h"
#include <curses.h>
#include <term.h>
#include <termcap.h>
#include <termios.h>
#include <sys/ioctl.h>

int	get_termdata(struct termios *term)
{
	char		*termtype;
	int		success;

	termtype = getenv ("TERM");
	if (termtype == NULL)
		ft_putendl("Specify a terminal type with `export TERM <yourtype>'.\n");
	success = tgetent(NULL, termtype);
	if (success < 0)
		ft_putendl("Could not access the termcap data base.\n");
	else if (success == 0)
		ft_sdebug("Terminal type % is not defined.\n", termtype);
	else if (tcgetattr(0, term) == -1)
		ft_putendl("Term info not reached");
	return (success);
}

int	main(void)
{
	struct termios	*term;

	term = NULL;
	get_termdata(&term);
	if (term->c_cc)
		ft_putendl("WORKS");
	return (1);

}

