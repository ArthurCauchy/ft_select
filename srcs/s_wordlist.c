/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_wordlist.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acauchy <acauchy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 14:06:51 by acauchy           #+#    #+#             */
/*   Updated: 2018/03/20 12:10:02 by acauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

t_wordlist	*wordlist_new(char *str)
{
	t_wordlist	*elem;

	elem = (t_wordlist*)ft_memalloc(sizeof(t_wordlist));
	elem->word = str;
	elem->isselected = 0;
	elem->iscurrent = 0;
	elem->next = NULL;
	elem->prev = NULL;
	return (elem);
}

t_wordlist	*wordlist_add_elem(t_wordlist **list, t_wordlist *new)
{
	t_wordlist	*cur;
	t_wordlist	*prev;

	if (*list)
	{
		cur = *list;
		prev = cur->prev;
		while (cur->next)
			cur = cur->next;
		cur->next = new;
		new->prev = cur;
	}
	else
		*list = new;
	return (*list);
}

t_wordlist	*wordlist_delete_elem(t_wordlist **head, t_wordlist *elem)
{
	t_wordlist	*new_curr;

	new_curr = NULL;
	if (elem->prev)
	{
		elem->prev->next = elem->next;
		new_curr = elem->prev;
	}
	if (elem->next)
	{
		elem->next->prev = elem->prev;
		new_curr = elem->next;
	}
	if (*head == elem)
		*head = (*head)->next;
	free(elem->word);
	free(elem);
	return (new_curr);
}
