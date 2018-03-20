/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_delkey.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acauchy <acauchy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 13:48:09 by acauchy           #+#    #+#             */
/*   Updated: 2018/03/20 14:54:21 by acauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	perform_delkey_action(t_wordlist **curr_word)
{
	*curr_word = wordlist_delete_elem(get_wordlist(), *curr_word);
	if (*curr_word == NULL)
	{
		draw_clearline((*get_term())->ttyfd);
		wordlist_delete_all(get_wordlist());
		disable_raw_mode();
		delete_term_struct();
		exit(0);
	}
	(*curr_word)->iscurrent = 1;
}
