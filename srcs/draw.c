/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acauchy <acauchy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 14:38:55 by acauchy           #+#    #+#             */
/*   Updated: 2018/03/19 16:22:54 by acauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static void	draw_word(int fd, t_termcaps *term, t_wordlist *word)
{
	if (word->isselected)
		ft_putstr_fd(term->invstr, fd);
	if (word->iscurrent)
		ft_putstr_fd(term->ulstr, fd);
	ft_putstr_fd(word->word, fd);
	ft_putstr_fd(term->resetstr, fd);
}

void		draw_wordlist(int fd, t_termcaps *term, t_wordlist **wordlist)
{
	t_wordlist	*cur;

	cur = *wordlist;
	while (cur)
	{
		draw_word(fd, term, cur);
		if (cur->next)
			ft_putchar_fd(' ', fd);
		cur = cur->next;
	}
}

void		draw_selected_wordlist(int fd, t_wordlist **wordlist)
{
	t_wordlist	*cur;
	char		isfirst;

	isfirst = 1;
	cur = *wordlist;
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

void		draw_clearline(int fd, t_termcaps *term)
{
	ft_putstr_fd(tgoto(term->gostartlinestr, 0, 0), fd);
	ft_putstr_fd(term->clearlinestr, fd);
}
