/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acauchy <acauchy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 09:39:03 by acauchy           #+#    #+#             */
/*   Updated: 2018/03/15 13:26:52 by arthur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FT_SELECT_H
# define __FT_SELECT_H

# include <stdio.h>

# include <stdlib.h>
# include <termcap.h>
# include <termios.h>
# include <unistd.h>
# include "libft.h"

typedef struct	s_termcaps
{
	char	*clearstr;
	char	*gotostr;
	char	*goupstr;
	char	*godownstr;
	char	*gorightstr;
	char	*goleftstr;
	char	*invvidstr;
	char	*ulstr;
	char	*resetstr;
}				t_termcaps;

typedef struct	s_wordlist
{
	char				*word;
	struct s_wordlist	*next;
	struct s_wordlist	*prev;
}				t_wordlist;

/*
** s_wordlist.c
*/

t_wordlist		*wordlist_new(char *str);
t_wordlist		*wordlist_delete(t_wordlist *elem);
t_wordlist		*wordlist_add_elem(t_wordlist **list, t_wordlist *new);
void			wordlist_delete_elem(t_wordlist *elem);

/*
** init.c
*/

void			init_termcap(struct termios *orig_termios);
void			init_term_struct(struct termios *orig_termios,
		t_termcaps **term);
void			delete_term_struct(t_termcaps **term);

/*
** utils.c
*/

void			exit_error(struct termios *orig_termios,
		t_termcaps **term, char *errmsg);
void			enable_raw_mode(struct termios *orig_termios);
void			disable_raw_mode(struct termios *orig_termios);

/*
** keyboard.c
*/

int				which_arrowkey(char *keybuff);

#endif
