/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acauchy <acauchy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 12:06:59 by acauchy           #+#    #+#             */
/*   Updated: 2018/03/20 12:10:45 by acauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void		init_termcap(void)
{
	char	*termtype;
	int		success;

	termtype = getenv("TERM");
	if (!termtype)
		exit_error("TERM env variable is not set !");
	success = tgetent(NULL, termtype);
	if (success < 0)
		exit_error("Can't access the termcap database.");
	if (success == 0)
		exit_error("This terminal type is not defined.");
}

static void	init_tty(void)
{
	int	fd;

	if (!isatty(0))
	{
		free(*get_term());
		exit_error("Not a tty !");
	}
	fd = open(ttyname(0), O_RDWR);
	if (fd < 0)
	{
		free(*get_term());
		exit_error("Can't open term file !");
	}
	(*get_term())->ttyfd = fd;
}

void		init_term_struct(void)
{
	if (!(*get_term() = (t_term*)ft_memalloc(sizeof(t_term))))
		exit_error("malloc() error");
	init_tty();
	(*get_term())->hidecurstr = tgetstr("vi", NULL);
	(*get_term())->showcurstr = tgetstr("ve", NULL);
	(*get_term())->clearlinestr = tgetstr("ce", NULL);
	(*get_term())->gotostr = tgetstr("cm", NULL);
	(*get_term())->gostartlinestr = tgetstr("ch", NULL);
	(*get_term())->invstr = tgetstr("mr", NULL);
	(*get_term())->ulstr = tgetstr("us", NULL);
	(*get_term())->resetstr = tgetstr("me", NULL);
}

void		delete_term_struct(void)
{
	if (*get_term())
	{
		close((*get_term())->ttyfd);
		free(*get_term());
		*get_term() = NULL;
	}
}

void		init_wordlist(t_wordlist **wordlist, char **argv)
{
	int isfirst;

	isfirst = 1;
	++argv;
	while (*argv)
	{
		wordlist_add_elem(wordlist, wordlist_new(ft_strdup(*argv)));
		if (isfirst)
		{
			(*wordlist)->iscurrent = 1;
			isfirst = 0;
		}
		++argv;
	}
}
