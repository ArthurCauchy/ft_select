/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acauchy <acauchy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 09:55:47 by acauchy           #+#    #+#             */
/*   Updated: 2018/03/15 17:05:09 by acauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	exit_error(struct termios *orig_termios,
		t_termcaps **term, char *errmsg)
{
	if (errmsg)
		ft_putendl_fd(errmsg, 2);
	else
		ft_putendl_fd("error", 2);
	disable_raw_mode(orig_termios);
	delete_term_struct(term);
	exit(1);
}

void	enable_raw_mode(struct termios *orig_termios)
{
	struct termios raw;

	tcgetattr(0, orig_termios);
	raw = *orig_termios;
	raw.c_lflag &= ~(ECHO | ICANON);
	tcsetattr(0, TCSAFLUSH, &raw);
}

void	disable_raw_mode(struct termios *orig_termios)
{
	tcsetattr(0, TCSAFLUSH, orig_termios);
}
