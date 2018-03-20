/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_enterkey.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acauchy <acauchy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 13:48:09 by acauchy           #+#    #+#             */
/*   Updated: 2018/03/20 14:56:01 by acauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	perform_enterkey_action(void)
{
	draw_clearline((*get_term())->ttyfd);
	draw_selected_wordlist(1);
	wordlist_delete_all(get_wordlist());
	disable_raw_mode();
	delete_term_struct();
	exit(0);
}
