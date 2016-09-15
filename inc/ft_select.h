/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-monc <fde-monc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/15 17:51:52 by fde-monc          #+#    #+#             */
/*   Updated: 2016/09/15 18:29:34 by fde-monc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SELECT_H
# define FT_SELECT_H
# include "libft.h"
# include <curses.h>
# include <sys/ioctl.h>
# include <signal.h>
# include <term.h>
# include <termcap.h>
# include <termios.h>
# define ERROR(ID) (ft_strcmp(ID, id) == 0 ? 1 : 0)

typedef struct termios	t_termios;

typedef struct		s_term
{
	t_termios	origin_termios;
	t_termios	termios;
}					t_term;

typedef struct		s_files
{
	struct s_files	*prev;
	char			*file;
	int				len;
	int				slect;
	int				x_pos;
	int				y_pos;
	int				col;
	struct s_files	*next;
	int				loop;
}					t_files;

typedef	struct		s_infos
{
	t_term			term;
	int				nbfiles;
	t_files			*files;
	int				ws_row;
	int				ws_col;
	t_files			*cr_pos;
	t_files			*old_pos;
	int				cr_col;
	int				cr_row;
	int				nb_col;
	int				nb_row;
	int				width;
	int				fd;
}					t_infos;

t_infos				g_infos;

/*
** INITIALISING NEWTERM MODE
*/

int					init_newterm(t_term *term);
int					get_termdata(t_term *term);
int					set_newterm(t_termios *term);
int					my_putchar(int c);

/*
** GET INFOS
*/

int					get_infos(int ac, char **av, t_infos *infos);
int					get_files(int ac, char **av, t_infos *infos);
int					get_winsize(t_infos *infos);
int					check_winsize(t_infos *infos);

/*
** GET FILES
*/

t_files				*make_filelist(char **av);
t_files				*init_list(char *av);
int					get_maxlen(t_infos *infos);
int					get_filepos(t_infos *infos);
int					make_loop(t_files *file);

/*
** RUNNING
*/

int					run_select(t_infos *infos);
int					open_newterm(t_infos *infos);
int					init_print(t_infos *infos);
int					clean(int fd);
int					print_list(t_infos *infos);
int					putchar_std(int c);
int					putchar_fd(int c);

/*
** COMMANDS
*/

int					read_commands(t_infos *infos);
int					select_it(t_infos *infos);
int					sl_error(char *id, t_infos *infos);
int					delete_it(t_infos *infos);
int					slect_return(t_infos *infos);

/*
** MOTION
*/

int					cursor_origin(t_infos *infos);
int					cursor_commands(char c, t_infos *infos);
int					curs_right(t_infos *infos);
int					no_right(t_files *file, t_infos *infos);
int					curs_left(t_infos *infos);
int					curs_down(t_infos *infos);
int					curs_up(t_infos *infos);
int					curs_to(t_files *dest, t_infos *infos);

/*
** PRINTS
*/

int					print_file(t_files *ptr, char *opt, t_infos *infos);
int					print_ulfile(t_files *ptr);
int					print_file_at(t_files *ptr);

/*
** MISC
*/

int					has_no_next(t_files *ptr, char *pos, t_infos *infos);
int					has_no_next2(t_files *ptr, char *pos, t_infos *infos);
int					free_node(t_files *file, t_infos *infos);
int					make_unloop(t_files *file);
int					sl_termerror(char *id, char *termtype);

/*
** SIGNAL
*/

void				sl_signal(void);
void				signal_handler(int sig);
void				signal_sigwinch(void);
int					wait_winsize(t_infos *infos);

/*
** EXIT
*/

void				sl_exit(int success, t_infos *infos);
void				sl_suspend(void);
void				sl_cont(void);
#endif
