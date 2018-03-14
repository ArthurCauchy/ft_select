/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acauchy <acauchy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 11:03:30 by acauchy           #+#    #+#             */
/*   Updated: 2018/03/14 11:17:49 by acauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int	which_arrowkey(char *keybuff)
{
	if (ft_strlen(keybuff) == 3)
	{
		if (keybuff[2] == 'A')
			return (1);
		if (keybuff[2] == 'B')
			return (2);
		if (keybuff[2] == 'C')
			return (3);
		if (keybuff[2] == 'D')
			return (4);
	}
	return (0);
}
