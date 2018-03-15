/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acauchy <acauchy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 09:40:51 by acauchy           #+#    #+#             */
/*   Updated: 2018/03/15 17:43:18 by acauchy          ###   ########.fr       */
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
	draw_wordlist(*term, wordlist);
	while ((read_size = read(0, &keybuff, 3)) > 0)
	{
		keybuff[read_size] = '\0';
		draw_clearline(*term);
		draw_wordlist(*term, wordlist);
		if (ft_iscntrl(keybuff[0]))
		{
			arrowkey_code = which_arrowkey(keybuff);
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
			else if (keybuff[0] == 27)
				break ;
		}
		else
		{
			if (keybuff[0] == 'i')
				ft_putstr((*term)->invstr);
			else if (keybuff[0] == 32)
				curr_word->isselected = (curr_word->isselected ? 0 : 1);
			else if (keybuff[0] == 'o')
				ft_putstr((*term)->resetstr);
			else if (keybuff[0] == 'u')
				ft_putstr((*term)->ulstr);
			else if (keybuff[0] == 'r')
				ft_putstr((*term)->hidecurstr);
			else if (keybuff[0] == 't')
				ft_putstr((*term)->showcurstr);
		}
	}
	if (read_size == -1)
		exit_error(orig_termios, term, "read() error");
}

int			main(int argc, char **argv)
{
	struct termios	orig_termios;
	t_termcaps		*term;
	t_wordlist		*wordlist;

	(void)argc;
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
	ft_putchar('\n');
	return (0);
}
