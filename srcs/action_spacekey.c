/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_spacekey.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acauchy <acauchy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 13:48:09 by acauchy           #+#    #+#             */
/*   Updated: 2018/03/22 12:07:20 by acauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	perform_spacekey_action(t_wordlist **curr_word)
{
	(*curr_word)->isselected = ((*curr_word)->isselected ? 0 : 1);
	(*curr_word)->iscurrent = 0;
	if ((*curr_word)->next)
		*curr_word = (*curr_word)->next;
	else
		*curr_word = *get_wordlist();
	(*curr_word)->iscurrent = 1;
}
