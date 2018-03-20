/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acauchy <acauchy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 14:12:27 by acauchy           #+#    #+#             */
/*   Updated: 2018/03/20 12:01:54 by acauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static void	sig_handler(int signo)
{
	if (signo == SIGWINCH)
	{
		ft_putstr("SIGWINCH");
	}
	// TODO gerer sigint et sigstop
}

void		init_signals(void)
{
	if (signal(SIGWINCH, sig_handler) == SIG_ERR)
		exit_error("System won't let us catch SIGWINCH.");
}
