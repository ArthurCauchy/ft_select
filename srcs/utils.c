/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acauchy <acauchy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 09:55:47 by acauchy           #+#    #+#             */
/*   Updated: 2018/03/29 15:09:56 by acauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	exit_error(char *errmsg)
{
	if (errmsg)
		ft_putendl_fd(errmsg, 2);
	else
		ft_putendl_fd("error", 2);
	disable_raw_mode();
	delete_term_struct();
	exit(1);
}

void	enable_raw_mode(void)
{
	struct termios raw;

	tcgetattr(0, &(*get_term())->orig_termios);
	raw = (*get_term())->orig_termios;
	raw.c_lflag &= ~(ECHO | ICANON);
	tcsetattr(0, TCSAFLUSH, &raw);
}

void	disable_raw_mode(void)
{
	tcsetattr(0, TCSAFLUSH, &(*get_term())->orig_termios);
}

void	update_term_size(void)
{
	struct ttysize	ts;

	ioctl(0, TIOCGSIZE, &ts);
	(*get_term())->nbcol = ts.ts_cols;
	(*get_term())->nbrow = ts.ts_lines;
}
