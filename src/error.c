/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-monc <fde-monc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/15 17:55:06 by fde-monc          #+#    #+#             */
/*   Updated: 2016/09/15 17:55:09 by fde-monc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int	sl_error(char *id, t_infos *infos)
{
	if (ERROR("winsize"))
		return (wait_winsize(infos));
	else if (ERROR("usage"))
	{
		ft_putendl("usage :\tft_select");
		ft_putendl("\t./ft_select [file1, file2, file3, ...]");
		return (-1);
	}
	else
		return (sl_termerror(id, NULL));
}

int	sl_termerror(char *id, char *termtype)
{
	ft_putendl("ERROR :\tft_select");
	if (ERROR("not set"))
	{
		ft_putstr("\tSpecify a terminal type ");
		ft_putendl("with 'export TERM <yourtype>'.");
	}
	else if (ERROR("terminfo"))
		ft_putendl("\t Could not access the terminfo data base.");
	else if (ERROR("type"))
		ft_sdebug("\tTerminal type % is not define.", termtype);
	else if (ERROR("info"))
		ft_putendl("\tTerm info not reached");
	else
		ft_sdebug("UNEXEPCTED ERROR :\tft_select\n\t%", id);
	return (-1);
}

int	wait_winsize(t_infos *infos)
{
	clean(2);
	clean(1);
	if (infos == NULL)
		ft_putchar('?');
	ft_putendl("THE WINDOW YOU ARE TRYING TO USE IS TOO");
	ft_putendl("SMALL TO DISPLAY THE LIST OF FILE !");
	ft_putendl("");
	ft_putendl("You might resize the current window");
	ft_putendl("or press ESC or CTR+C and retry with less file");
	return (0);
}
