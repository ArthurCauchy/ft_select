/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acauchy <acauchy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 14:37:32 by acauchy           #+#    #+#             */
/*   Updated: 2018/03/29 15:33:11 by acauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int			compute_maxcol(t_wordlist **wordlist)
{
	t_wordlist	*cur;
	int			max;

	cur = *wordlist;
	max = 0;
	while (cur)
	{
		if ((int)ft_strlen(cur->word) > max)
			max = ft_strlen(cur->word);
		cur = cur->next;
	}
	return (max);
}

static void	apply_display_size(int col_per_line, int lines, int colsize)
{
	(*get_term())->display->col_per_line = col_per_line;
	(*get_term())->display->lines = lines;
	(*get_term())->display->colsize = colsize;
}

void		compute_display_size(void)
{
	int	colsize;
	int	col_per_line;
	int	remaining;
	int lines;

	colsize = compute_maxcol(get_wordlist());
	if (colsize > (*get_term())->nbcol)
	{
		col_per_line = 0;
		lines = 0;
	}
	else
	{
		col_per_line = 1;
		remaining = (*get_term())->nbcol - colsize;
		while (remaining >= colsize + 1)
		{
			remaining -= colsize + 1;
			++col_per_line;
		}
		lines = wordlist_count_words(get_wordlist()) / col_per_line;
		if ((wordlist_count_words(get_wordlist()) % col_per_line) > 0)
			++lines;
	}
	apply_display_size(col_per_line, lines, colsize);
}
