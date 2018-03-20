/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acauchy <acauchy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 14:38:55 by acauchy           #+#    #+#             */
/*   Updated: 2018/03/20 14:47:00 by acauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static void	draw_word(int fd, t_wordlist *word)
{
	if (word->isselected)
		ft_putstr_fd((*get_term())->invstr, fd);
	if (word->iscurrent)
		ft_putstr_fd((*get_term())->ulstr, fd);
	ft_putstr_fd(word->word, fd);
	ft_putstr_fd((*get_term())->resetstr, fd);
}

void		draw_wordlist(int fd)
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

void		draw_clearline(int fd)
{
	ft_putstr_fd(tgoto((*get_term())->gostartlinestr, 0, 0), fd);
	ft_putstr_fd((*get_term())->clearlinestr, fd);
}
