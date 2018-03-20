/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acauchy <acauchy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 11:03:30 by acauchy           #+#    #+#             */
/*   Updated: 2018/03/20 11:44:26 by acauchy          ###   ########.fr       */
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

int	is_delkey(char *keybuff)
{
	return (keybuff[0] == 127 || (keybuff[0] == 27 && keybuff[1] == 91 && keybuff[2] == 51));
}

int	is_esckey(char *keybuff)
{
	return (keybuff[0] == 27 && keybuff[1] == '\0');
}
