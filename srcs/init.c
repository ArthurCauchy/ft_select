/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acauchy <acauchy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 12:06:59 by acauchy           #+#    #+#             */
/*   Updated: 2018/03/15 13:27:32 by arthur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	init_termcap(struct termios *orig_termios)
{
	char	*termtype;
	int		success;

	termtype = getenv("TERM");
	if (!termtype)
		exit_error(orig_termios, NULL, "TERM env variable is not set !");
	success = tgetent(NULL, termtype);
	if (success < 0)
		exit_error(orig_termios, NULL, "Can't access the termcap database.");
	if (success == 0)
		exit_error(orig_termios, NULL, "This terminal type is not defined.");
}

void	init_term_struct(struct termios *orig_termios, t_termcaps **term)
{
	if (!(*term = (t_termcaps*)ft_memalloc(sizeof(t_termcaps))))
		exit_error(orig_termios, NULL, "malloc() error");
	(*term)->clearstr = tgetstr("cl", NULL);
	(*term)->gotostr = tgetstr("cm", NULL);
	(*term)->goupstr = tgetstr("up", NULL);
	(*term)->godownstr = tgetstr("do", NULL);
	(*term)->gorightstr = tgetstr("nd", NULL);
	(*term)->goleftstr = tgetstr("le", NULL);
	(*term)->invvidstr = tgetstr("mr", NULL);
	(*term)->ulstr = tgetstr("us", NULL);
	(*term)->resetstr = tgetstr("me", NULL);
}

void	delete_term_struct(t_termcaps **term)
{
	if (*term)
	{
		free(*term);
		*term = NULL;
	}
}

//TODO init wordlist here
