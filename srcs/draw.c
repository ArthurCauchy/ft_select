/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acauchy <acauchy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 14:38:55 by acauchy           #+#    #+#             */
/*   Updated: 2018/03/28 15:30:18 by acauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static void	draw_word(int fd, t_wordlist *word)
{
	int	padding;

	if (word->isselected)
		ft_putstr_fd((*get_term())->invstr, fd);
	if (word->iscurrent)
		ft_putstr_fd((*get_term())->ulstr, fd);
	ft_putstr_fd(word->word, fd);
	ft_putstr_fd((*get_term())->resetstr, fd);
	padding = (*get_term())->display->colsize - ft_strlen(word->word);
	while (padding > 0)
	{
		ft_putchar_fd(' ', fd);
		--padding;
	}
}

/*void		draw_wordlist(int fd)
{
	t_wordlist	*cur;

	cur = *get_wordlist();
	while (cur)
	{
		draw_word(fd, cur);
		if (cur->next)
			ft_putchar_fd(' ', fd);
		cur = cur->next;
	}
}*/

void	draw_wordlist(int fd)
{
	t_wordlist	*cur;
	int			curr_col;
	int			curr_line;

	cur = *get_wordlist();
	curr_col = 1;
	curr_line = 1; 
	while (cur)
	{
		if (curr_col != 1)
			ft_putchar_fd(' ', fd);
		draw_word(fd, cur);
		if ((curr_col == (*get_term())->display->col_per_line)
				&& cur->next)
		{
			ft_putchar_fd('\n', fd);
			curr_col = 1;
			++curr_line;
		}
		else
			++curr_col;
		cur = cur->next;
	}
	while (curr_line > 1)
	{
		ft_putstr_fd(tgoto((*get_term())->goupstr, 0, 0), fd);
		--curr_line;
	}
	ft_putstr_fd(tgoto((*get_term())->gostartlinestr, 0, 0), fd);
	ft_putstr_fd((*get_term())->savecurstr, fd);
}


void		draw_selected_wordlist(int fd)
{
	t_wordlist	*cur;
	char		isfirst;

	isfirst = 1;
	cur = *get_wordlist();
	while (cur)
	{
		if (cur->isselected)
		{
			if (!isfirst)
				ft_putchar_fd(' ', fd);
			ft_putstr_fd(cur->word, fd);
			isfirst = 0;
		}
		cur = cur->next;
	}
}

/*void		draw_clear(int fd)
{
	ft_putstr_fd(tgoto((*get_term())->gostartlinestr, 0, 0), fd);
	ft_putstr_fd((*get_term())->clearlinestr, fd);
}*/

void		draw_clear(int fd)
{
	ft_putstr_fd((*get_term())->restorecurstr, fd);
	ft_putstr_fd((*get_term())->clearscreenstr, fd);
}
