/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   slect.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-monc <fde-monc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/15 18:15:53 by fde-monc          #+#    #+#             */
/*   Updated: 2016/09/15 18:15:55 by fde-monc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
** THIS FUNCTION SETS THE TERMINAL TO CANONIC MODE WHICH MEANS THE
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

int	main(int ac, char **av)
{
	sl_signal();
	if (init_newterm(&g_infos.term) == -1)
		return (-1);
	if (get_infos(ac, av, &g_infos) == -1)
		return (-1);
	run_select(&g_infos);
	tcsetattr(0, TCSADRAIN, &g_infos.term.origin_termios);
	return (1);
}
