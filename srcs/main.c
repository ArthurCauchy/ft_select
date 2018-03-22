/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acauchy <acauchy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 09:40:51 by acauchy           #+#    #+#             */
/*   Updated: 2018/03/22 10:27:07 by acauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>

#include "ft_select.h"

static void	restore_term(void)
{
	enable_raw_mode();
	draw_clearline((*get_term())->ttyfd);
	draw_wordlist((*get_term())->ttyfd);
}

static void	mainloop(void)
{
	char		keybuff[4];
	int			read_size;
	t_wordlist	*curr_word;

	curr_word = *get_wordlist();
	draw_wordlist((*get_term())->ttyfd);
	while ((read_size = read(0, &keybuff, 3)) != 0)
	{
		if (read_size == -1 && errno == EINTR)
		{
			restore_term();
			continue ;
		}
		else if (read_size == -1)
			break ;
		keybuff[read_size] = '\0';
		perform_actions(keybuff, &curr_word);
		draw_clearline((*get_term())->ttyfd);
		draw_wordlist((*get_term())->ttyfd);
	}
	if (read_size == -1)
		exit_error("read() error");
}

int			main(int argc, char **argv)
{
	if (argc < 2)
		return (0);
	init_termcap();
	init_term_struct();
	init_signals();
	enable_raw_mode();
	init_wordlist(argv);
	mainloop();
	return (0);
}
