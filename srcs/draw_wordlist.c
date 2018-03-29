/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wordlist.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acauchy <acauchy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 14:38:55 by acauchy           #+#    #+#             */
/*   Updated: 2018/03/29 15:36:55 by acauchy          ###   ########.fr       */
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

static void	replace_cursor_origin(int fd)
{
	int	cur;

	cur = (*get_term())->display->lines;
	while (cur > 1)
	{
		ft_putstr_fd(tgoto((*get_term())->goupstr, 0, 0), fd);
		--cur;
	}
	ft_putstr_fd(tgoto((*get_term())->gostartlinestr, 0, 0), fd);
	ft_putstr_fd((*get_term())->savecurstr, fd);
}

static void	draw_wordlist_margins(int fd,
		t_wordlist *cur, int *curr_col, int *i)
{
	if (*curr_col < (*get_term())->display->col_per_line)
	{
		ft_putchar_fd(' ', fd);
		++*i;
		++*curr_col;
		if (!cur->next)
		{
			while ((*i)++ < (*get_term())->nbcol)
				ft_putchar_fd(' ', fd);
		}
	}
	else
	{
		while ((*i)++ < (*get_term())->nbcol)
			ft_putchar_fd(' ', fd);
		if (cur->next)
			ft_putchar_fd('\n', fd);
		*curr_col = 1;
		*i = 0;
	}
}

void		draw_wordlist(int fd)
{
	t_wordlist	*cur;
	int			i;
	int			curr_col;

	if ((*get_term())->display->colsize > (*get_term())->nbcol ||
			(*get_term())->display->lines > (*get_term())->nbrow)
	{
		ft_putnbr_fd((*get_term())->display->lines, fd);
		return ;
	}
	cur = *get_wordlist();
	i = 0;
	curr_col = 1;
	while (cur)
	{
		draw_word(fd, cur);
		i += (*get_term())->display->colsize;
		draw_wordlist_margins(fd, cur, &curr_col, &i);
		cur = cur->next;
	}
	replace_cursor_origin(fd);
}
