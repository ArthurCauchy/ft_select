/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acauchy <acauchy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 09:40:51 by acauchy           #+#    #+#             */
/*   Updated: 2018/03/19 16:37:36 by acauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static void	mainloop(struct termios *orig_termios, t_termcaps **term, t_wordlist **wordlist)
{
	char		keybuff[4];
	int			read_size;
	int			arrowkey_code;
	t_wordlist	*curr_word;

	curr_word = *wordlist;
	draw_wordlist((*term)->ttyfd, *term, wordlist);
	while ((read_size = read(0, &keybuff, 3)) > 0)
	{
		keybuff[read_size] = '\0';
		if ((arrowkey_code = which_arrowkey(keybuff)))
		{
			if (arrowkey_code == 3)
			{
				curr_word->iscurrent = 0;
				if (curr_word->next)
					curr_word = curr_word->next;
				else
					curr_word = *wordlist;
				curr_word->iscurrent = 1;
			}
			else if (arrowkey_code == 4)
			{
				curr_word->iscurrent = 0;
				if (curr_word->prev)
					curr_word = curr_word->prev;
				else
				{
					while (curr_word->next)
						curr_word = curr_word->next;
				}
				curr_word->iscurrent = 1;
			}
		}
		else if (is_esckey(keybuff))
		{
			draw_clearline((*term)->ttyfd, *term);
			break ;
		}
		else if (is_delkey(keybuff))
		{
			curr_word = wordlist_delete_elem(wordlist, curr_word);
			if (curr_word == NULL)
			{
				draw_clearline((*term)->ttyfd, *term);
				break ;
			}
			curr_word->iscurrent = 1;
		}
		else if (keybuff[0] == 32)
			curr_word->isselected = (curr_word->isselected ? 0 : 1);
		else if (keybuff[0] == 10)
		{
			draw_clearline((*term)->ttyfd, *term);
			draw_selected_wordlist(1, wordlist);
			break ;
		}
		draw_clearline((*term)->ttyfd, *term);
		draw_wordlist((*term)->ttyfd, *term, wordlist);
	}
	if (read_size == -1)
		exit_error(orig_termios, term, "read() error");
}

int			main(int argc, char **argv)
{
	struct termios	orig_termios;
	t_termcaps		*term;
	t_wordlist		*wordlist;

	if (argc < 2)
		return (0);
	term = NULL;
	wordlist = NULL;
	enable_raw_mode(&orig_termios);
	init_signals(&orig_termios);
	init_wordlist(&wordlist, argv);
	init_termcap(&orig_termios);
	init_term_struct(&orig_termios, &term);
	mainloop(&orig_termios, &term, &wordlist);
	disable_raw_mode(&orig_termios);
	delete_term_struct(&term);
	return (0);
}
