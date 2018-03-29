/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_arrowkey.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acauchy <acauchy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 13:30:04 by acauchy           #+#    #+#             */
/*   Updated: 2018/03/29 12:30:45 by acauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static void	perform_arrowkey_action_up(t_wordlist **curr_word)
{
	int	i;

	i = 0;
	(*curr_word)->iscurrent = 0;
	while (i < (*get_term())->display->col_per_line)
	{
		if ((*curr_word)->prev)
			*curr_word = (*curr_word)->prev;
		else
			break ;
		++i;
	}
	(*curr_word)->iscurrent = 1;
}

static void	perform_arrowkey_action_down(t_wordlist **curr_word)
{
	int	i;

	i = 0;
	(*curr_word)->iscurrent = 0;
	while (i < (*get_term())->display->col_per_line)
	{
		if ((*curr_word)->next)
			*curr_word = (*curr_word)->next;
		else
			break ;
		++i;
	}
	(*curr_word)->iscurrent = 1;
}

void		perform_arrowkey_action(t_wordlist **curr_word, int arrowkey_code)
{
	if (arrowkey_code == 1)
		perform_arrowkey_action_up(curr_word);
	else if (arrowkey_code == 2)
		perform_arrowkey_action_down(curr_word);
	else if (arrowkey_code == 3)
	{
		(*curr_word)->iscurrent = 0;
		if ((*curr_word)->next)
			*curr_word = (*curr_word)->next;
		else
			*curr_word = *get_wordlist();
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
