/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acauchy <acauchy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 14:38:55 by acauchy           #+#    #+#             */
/*   Updated: 2018/03/29 12:32:12 by acauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

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

void		draw_clear(int fd)
{
	ft_putstr_fd((*get_term())->restorecurstr, fd);
	ft_putstr_fd((*get_term())->clearscreenstr, fd);
}
