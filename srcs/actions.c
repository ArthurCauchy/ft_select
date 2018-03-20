/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acauchy <acauchy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 12:29:12 by acauchy           #+#    #+#             */
/*   Updated: 2018/03/20 14:13:25 by acauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	perform_actions(char *keybuff,
		t_wordlist **wordlist, t_wordlist **curr_word)
{
	int	arrowkey_code;

	if ((arrowkey_code = which_arrowkey(keybuff)))
		perform_arrowkey_action(wordlist, curr_word, arrowkey_code);
	else if (is_esckey(keybuff))
		perform_esckey_action();
	else if (is_delkey(keybuff))
		perform_delkey_action(wordlist, curr_word);
	else if (keybuff[0] == 32)
		perform_spacekey_action(curr_word);
	else if (keybuff[0] == 10)
		perform_enterkey_action(wordlist);
}
