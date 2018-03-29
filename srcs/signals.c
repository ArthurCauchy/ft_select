/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acauchy <acauchy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 14:12:27 by acauchy           #+#    #+#             */
/*   Updated: 2018/03/29 15:39:23 by acauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static void	sighandler_sigwinch(int signo)
{
	int				tmp;
	int				fd;
	int				oldnbcol;

	if (signo != SIGWINCH)
		return ;
	fd = (*get_term())->ttyfd;
	oldnbcol = (*get_term())->nbcol;
	update_term_size();
	draw_clear(fd);
	if ((*get_term())->nbcol < oldnbcol)
	{
		tmp = (*get_term())->display->lines;
		while (tmp > 0)
		{
			ft_putstr_fd(tgoto((*get_term())->goupstr, 0, 0), fd);
			ft_putstr_fd(tgoto((*get_term())->gostartlinestr, 0, 0), fd);
			ft_putstr_fd((*get_term())->clearlinestr, fd);
			--tmp;
		}
		ft_putstr_fd((*get_term())->savecurstr, fd);
	}
	compute_display_size();
	draw_wordlist(fd);
}

static void	sighandler_sigint(int signo)
{
	if (signo != SIGINT)
		return ;
	draw_clear((*get_term())->ttyfd);
	wordlist_delete_all(get_wordlist());
	disable_raw_mode();
	delete_term_struct();
	exit(0);
}

void		init_signals(void)
{
	if (signal(SIGWINCH, sighandler_sigwinch) == SIG_ERR)
		exit_error("Can't catch SIGWINCH.");
	if (signal(SIGINT, sighandler_sigint) == SIG_ERR)
		exit_error("Can't catch SIGINT.");
}
