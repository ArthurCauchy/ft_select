/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_arrowkey.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acauchy <acauchy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 13:30:04 by acauchy           #+#    #+#             */
/*   Updated: 2018/03/20 14:14:36 by acauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	perform_arrowkey_action(t_wordlist **wordlist,
		t_wordlist **curr_word, int arrowkey_code)
{
	if (arrowkey_code == 3)
	{
		(*curr_word)->iscurrent = 0;
		if ((*curr_word)->next)
			*curr_word = (*curr_word)->next;
		else
			*curr_word = *wordlist;
		(*curr_word)->iscurrent = 1;
	}
	else if (arrowkey_code == 4)
	{
		(*curr_word)->iscurrent = 0;
		if ((*curr_word)->prev)
			*curr_word = (*curr_word)->prev;
		else
		{
			while ((*curr_word)->next)
				*curr_word = (*curr_word)->next;
		}
		(*curr_word)->iscurrent = 1;
	}
}
