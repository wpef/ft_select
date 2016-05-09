#ifndef FT_SELECT_H
# define FT_SELECT_H
# include "libft.h"
# include <curses.h>
# include <sys/ioctl.h>
# include <stdio.h> //to tej
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
	int			len;
	struct s_files	*next;
}					t_files;

typedef	struct		s_infos
{
	t_term	term;
	int		nbfiles;
	t_files	*files;
	int		ws_row;
	int		ws_col;
	int		cr_col;
	int		cr_row;
	int		max_col;
	int		max_row;
	int		maxlen;
	int		fd;
}					t_infos;

/*
** INITIALISING NEWTERM MODE
*/

int	init_newterm(t_term *term);
int	get_termdata(t_term *term);
int	set_newterm(t_termios *term);
int	my_putchar(int c);

/*
** GET INFOS
*/

int	get_infos(int ac, char **av, t_infos *infos);
int	get_files(int ac, char **av, t_infos *infos);
int	get_winsize(t_infos *infos);
int	check_winsize(t_infos *infos);

/*
** GET FILES
*/

t_files	*make_filelist(char **av);
t_files	*init_list(char *av);
int	get_maxlen(t_infos *infos);

/*
** RUNNING
*/

int run_select(t_infos *infos);
int	open_newterm(t_infos *infos);
int	clean(int fd);
int	print_file(t_files *ptr, t_infos *infos);
int	print_list(t_infos *infos);
int	putchar_std(int c);
int	putchar_fd(int c);

/*
** COMMANDS
*/

int	read_commands(t_infos *infos);
int	sl_error(char *id, t_infos *infos);

/*
** MOTION
*/

int cursor_origin(t_infos *infos);

#endif
