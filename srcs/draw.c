/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acauchy <acauchy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 14:38:55 by acauchy           #+#    #+#             */
/*   Updated: 2018/03/15 17:36:31 by acauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static void	draw_word(t_termcaps *term, t_wordlist *word)
{
	if (word->isselected)
		ft_putstr(term->invstr);
	if (word->iscurrent)
		ft_putstr(term->ulstr);
	ft_putstr(word->word);
	ft_putstr(term->resetstr);
}

void		draw_wordlist(t_termcaps *term, t_wordlist **wordlist)
{
	t_wordlist	*cur;

	cur = *wordlist;
	while (cur)
	{
		draw_word(term, cur);
		if (cur->next)
			ft_putchar(' ');
		cur = cur->next;
	}
}

void		draw_clearline(t_termcaps *term)
{
	ft_putstr(tgoto(term->gostartlinestr, 0, 0));
	ft_putstr(term->clearlinestr);
}
