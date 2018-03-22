/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_esckey.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acauchy <acauchy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 13:42:33 by acauchy           #+#    #+#             */
/*   Updated: 2018/03/22 14:16:59 by acauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	perform_esckey_action(void)
{
	draw_clear((*get_term())->ttyfd);
	wordlist_delete_all(get_wordlist());
	disable_raw_mode();
	delete_term_struct();
	exit(0);
}
