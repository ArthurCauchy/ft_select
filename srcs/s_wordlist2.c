/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_wordlist2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acauchy <acauchy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 11:02:22 by acauchy           #+#    #+#             */
/*   Updated: 2018/03/28 16:02:14 by acauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int	wordlist_count_words(t_wordlist **wordlist)
{
	t_wordlist	*cur;
	int			count;

	cur = *wordlist;
	count = 0;
	while (cur)
	{
		cur = cur->next;
		++count;
	}
	return (count);
}
