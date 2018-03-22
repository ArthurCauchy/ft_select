/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   columns.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acauchy <acauchy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 14:37:32 by acauchy           #+#    #+#             */
/*   Updated: 2018/03/22 14:47:31 by acauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int	compute_col_size(t_wordlist **wordlist)
{
	t_wordlist	*cur;
	int			max;

	cur = *wordlist;
	max = 0;
	while (cur)
	{
		if (ft_strlen(cur->word) > max)
			max = ft_strlen(cur->word);
		cur = cur->next;
	}
	return (max);
}
