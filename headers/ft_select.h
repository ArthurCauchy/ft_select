/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acauchy <acauchy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 09:39:03 by acauchy           #+#    #+#             */
/*   Updated: 2018/03/29 12:42:04 by acauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FT_SELECT_H
# define __FT_SELECT_H

# include <stdlib.h>
# include <termcap.h>
# include <termios.h>
# include <unistd.h>
# include <signal.h>
# include <fcntl.h>
# include <errno.h>
# include <sys/ioctl.h>
# include "libft.h"

typedef struct	s_display
{
	int	col_per_line;
	int	lines;
	int	colsize;
}				t_display;

typedef struct	s_term
{
	struct termios	orig_termios;
	t_display		*display;
	int				ttyfd;
	char			*hidecurstr;
	char			*showcurstr;
	char			*clearscreenstr;
	char			*clearlinestr;
	char			*dellinestr;
	char			*gostartlinestr;
	char			*goupstr;
	char			*savecurstr;
	char			*restorecurstr;
	char			*invstr;
	char			*ulstr;
	char			*resetstr;
	int				nbcol;
	int				nbrow;
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

t_wordlist		**get_wordlist(void);
t_wordlist		*wordlist_new(char *str);
t_wordlist		*wordlist_add_elem(t_wordlist **list, t_wordlist *new);
t_wordlist		*wordlist_delete_elem(t_wordlist **head, t_wordlist *elem);
void			wordlist_delete_all(t_wordlist **head);
int				wordlist_count_words(t_wordlist	**wordlist);

/*
** term.c
*/

t_term			**get_term(void);

/*
** display.c
*/

int				compute_maxcol(t_wordlist **wordlist);
void			compute_display_size(void);

/*
** init.c
*/

void			init_termcap(void);
void			init_term_struct(void);
void			delete_term_struct(void);
void			init_wordlist(char **argv);

/*
** actions.c
*/

void			perform_actions(char *keybuff, t_wordlist **cur_word);

/*
** action_[key].c
*/

void			perform_arrowkey_action(t_wordlist **curr_word,
		int arrowkey_code);
void			perform_esckey_action(void);
void			perform_delkey_action(t_wordlist **curr_word);
void			perform_spacekey_action(t_wordlist **curr_word);
void			perform_enterkey_action(void);

/*
** utils.c
*/

void			exit_error(char *errmsg);
void			enable_raw_mode(void);
void			disable_raw_mode(void);
void			update_term_size(void);

/*
** keyboard.c
*/

int				which_arrowkey(char *keybuff);
int				is_delkey(char *keybuff);
int				is_esckey(char *keybuff);

/*
** draw.c
*/

void			draw_selected_wordlist(int fd);
void			draw_clear(int fd);

/*
** draw_wordlist.c
*/

void			draw_wordlist(int fd);

/*
** signals.c
*/

void			init_signals(void);

#endif
