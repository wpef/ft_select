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
	t_termios	origin_termios;
	t_termios	termios;
}			t_term;	

typedef struct		s_files
{
	struct s_files	*prev;
	char			*file;
	struct s_files	*next;
}					t_files;

typedef	struct		s_infos
{
	int	nbfiles;
	t_files	*args;
}					t_infos;

/*
** INITIALISING NEWTERM MODE
*/

int	init_newterm(t_term *term);
int	get_termdata(t_term *term);
int	set_newterm(t_termios *term);

/*
** GET FILES
*/

int	get_infos(int ac, char **av, t_infos *files);
t_files	*make_filelist(char **av);
t_files	*init_list(char *av);

#endif
