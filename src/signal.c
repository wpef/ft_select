/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-monc <fde-monc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/15 18:05:04 by fde-monc          #+#    #+#             */
/*   Updated: 2016/09/15 18:05:06 by fde-monc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	sl_signal(void)
{
	int	i;

	i = 0;
	while (i < 32)
	{
		signal(i, signal_handler);
		i++;
	}
}

void	signal_handler(int sig)
{
	if (sig == SIGWINCH)
		return (signal_sigwinch());
	if (sig == SIGINT || sig == SIGQUIT)
		return (sl_exit(0, &g_infos));
	if (sig == SIGTSTP)
		return (sl_suspend());
	if (sig == SIGCONT)
		return (sl_cont());
}

void	signal_sigwinch(void)
{
	clean(2);
	get_winsize(&g_infos);
	if (check_winsize(&g_infos) == 1)
	{
		init_print(&g_infos);
		return ;
	}
	else
		wait_winsize(&g_infos);
}
