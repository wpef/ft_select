#ifndef FT_SELECT_H
# define FT_SELECT_H
# include "libft.h"
# include <curses.h>
# include <term.h>
# include <termcap.h>
# include <termios.h>

typedef struct termios	t_termios;

typedef struct		s_term
{
	t_termios	*origin_termios;
	t_termios	*termios;
}			t_term;	

#endif
