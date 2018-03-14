/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acauchy <acauchy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 12:06:59 by acauchy           #+#    #+#             */
/*   Updated: 2018/03/14 15:05:17 by acauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	init_termcap(struct termios *orig_termios, t_termcaps **term)
{
	if (!(*term = (t_termcaps*)ft_memalloc(sizeof(t_termcaps))))
		exit_error(orig_termios, NULL, "malloc() error");
	(*term)->clearstr = tgetstr("cl", NULL);
	(*term)->gotostr = tgetstr("cm", NULL);
	(*term)->goupstr = tgetstr("up", NULL);
	(*term)->godownstr = tgetstr("do", NULL);
	(*term)->gorightstr = tgetstr("nd", NULL);
	(*term)->goleftstr = tgetstr("le", NULL);
}

void	delete_termcap(t_termcaps **term)
{
	if (*term)
	{
		free(*term);
		*term = NULL;
	}
}
