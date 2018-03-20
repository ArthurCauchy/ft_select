/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_spacekey.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acauchy <acauchy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 13:48:09 by acauchy           #+#    #+#             */
/*   Updated: 2018/03/20 14:00:28 by acauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	perform_spacekey_action(t_wordlist **curr_word)
{
	(*curr_word)->isselected = ((*curr_word)->isselected ? 0 : 1);
}
