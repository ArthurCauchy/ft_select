/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acauchy <acauchy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 09:39:03 by acauchy           #+#    #+#             */
/*   Updated: 2018/03/20 12:04:38 by acauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FT_SELECT_H
# define __FT_SELECT_H

# include <stdio.h>

# include <stdlib.h>
# include <termcap.h>
# include <termios.h>
# include <unistd.h>
# include <fcntl.h>
# include "libft.h"

typedef struct	s_term
{
	struct termios	orig_termios;
	int				ttyfd;
	char			*hidecurstr;
	char			*showcurstr;
	char			*clearlinestr;
	char			*gotostr;
	char			*gostartlinestr;
	char			*invstr;
	char			*ulstr;
	char			*resetstr;
}				t_term;

typedef struct	s_wordlist
{
	char				*word;
	char				isselected;
	char				iscurrent;
	struct s_wordlist	*next;
	struct s_wordlist	*prev;
}				t_wordlist;

/*
** s_wordlist.c
*/

t_wordlist		*wordlist_new(char *str);
t_wordlist		*wordlist_add_elem(t_wordlist **list, t_wordlist *new);
t_wordlist		*wordlist_delete_elem(t_wordlist **head, t_wordlist *elem);

/*
** term.c
*/

t_term			**get_term(void);

/*
** init.c
*/

void			init_termcap(void);
void			init_term_struct(void);
void			delete_term_struct(void);
void			init_wordlist(t_wordlist **wordlist, char **argv);

/*
** utils.c
*/

void			exit_error(char *errmsg);
void			enable_raw_mode(void);
void			disable_raw_mode(void);

/*
** keyboard.c
*/

int				which_arrowkey(char *keybuff);
int				is_delkey(char *keybuff);
int				is_esckey(char *keybuff);

/*
** draw.c
*/

void			draw_wordlist(int fd, t_wordlist **wordlist);
void			draw_selected_wordlist(int fd, t_wordlist **wordlist);
void			draw_clearline(int fd);

/*
** signals.c
*/

void			init_signals(void);

#endif
