/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acauchy <acauchy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 09:40:51 by acauchy           #+#    #+#             */
/*   Updated: 2018/03/20 14:01:05 by acauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static void	mainloop(t_wordlist **wordlist)
{
	char		keybuff[4];
	int			read_size;
	t_wordlist	*curr_word;

	curr_word = *wordlist;
	draw_wordlist((*get_term())->ttyfd, wordlist);
	while ((read_size = read(0, &keybuff, 3)) > 0)
	{
		keybuff[read_size] = '\0';
		perform_actions(keybuff, wordlist, &curr_word);
		draw_clearline((*get_term())->ttyfd);
		draw_wordlist((*get_term())->ttyfd, wordlist);
	}
	if (read_size == -1)
		exit_error("read() error");
}

int			main(int argc, char **argv)
{
	t_wordlist		*wordlist;

	if (argc < 2)
		return (0);
	wordlist = NULL;
	init_termcap();
	init_term_struct();
	init_signals();
	enable_raw_mode();
	init_wordlist(&wordlist, argv);
	mainloop(&wordlist);
	return (0);
}
