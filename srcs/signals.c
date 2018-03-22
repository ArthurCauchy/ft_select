/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acauchy <acauchy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 14:12:27 by acauchy           #+#    #+#             */
/*   Updated: 2018/03/22 11:11:46 by acauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static void	sig_handler(int signo)
{
	if (signo == SIGWINCH)
	{
	}
	else if (signo == SIGINT)
	{
		draw_clearline((*get_term())->ttyfd);
		wordlist_delete_all(get_wordlist());
		disable_raw_mode();
		delete_term_struct();
		exit(0);
	}
}

void		init_signals(void)
{
	if (signal(SIGWINCH, sig_handler) == SIG_ERR)
		exit_error("Can't catch SIGWINCH.");
	if (signal(SIGINT, sig_handler) == SIG_ERR)
		exit_error("Can't catch SIGINT.");
}
