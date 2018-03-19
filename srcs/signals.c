/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acauchy <acauchy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 14:12:27 by acauchy           #+#    #+#             */
/*   Updated: 2018/03/19 14:58:47 by acauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static void	sig_handler(int signo)
{
	if (signo == SIGWINCH)
	{
		ft_putstr("SIGWINCH");
	}
}

void		init_signals(struct termios *orig_termios)
{
	if (signal(SIGWINCH, sig_handler) == SIG_ERR)
		exit_error(orig_termios, NULL, "System won't let us catch SIGWINCH.");
}
