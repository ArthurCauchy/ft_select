/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acauchy <acauchy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 14:12:27 by acauchy           #+#    #+#             */
/*   Updated: 2018/03/28 15:59:04 by acauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static void	sig_handler(int signo)
{
	struct ttysize  ts;
	int				tmp;

	if (signo == SIGWINCH)
	{
		ioctl(0, TIOCGSIZE, &ts);
		(*get_term())->nbcol = ts.ts_cols;
		(*get_term())->nbrow = ts.ts_lines;
		draw_clear((*get_term())->ttyfd);
		if ((*get_term())->nbcol < ((*get_term())->display->col_per_line * (*get_term())->display->colsize) + ((*get_term())->display->col_per_line - 1))
		{
			tmp = (*get_term())->display->lines;
			while (tmp > 1)
			{
				ft_putstr_fd(tgoto((*get_term())->goupstr, 0, 0), (*get_term())->ttyfd);
				ft_putstr_fd((*get_term())->clearlinestr, (*get_term())->ttyfd);
				--tmp;
			}
			ft_putstr_fd((*get_term())->savecurstr, (*get_term())->ttyfd);
		}
		compute_display_size();
		draw_wordlist((*get_term())->ttyfd);
	}
	else if (signo == SIGINT)
	{
		draw_clear((*get_term())->ttyfd);
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
