#include "ft_select.h"

t_wordlist	*wordlist_new(char *str)
{
	t_wordlist	*elem;

	elem = (t_wordlist*)ft_memalloc(sizeof(t_wordlist));
	elem->word = str;
	elem->next = NULL;
	elem->prev = NULL;
	return (elem);
}

t_wordlist	*wordlist_delete(t_wordlist *elem)
{
	free(elem->word);
	free(elem);
}

t_wordlist	*wordlist_add_elem(t_wordlist **list, t_wordlist *new)
{
	t_wordlist	*cur;

	if (*list)
	{
		cur = *list;
		while (cur->next)
			cur = cur->next;
		cur->next = new;
	}
	else
		*list = new;
	return (*list);
}

void		wordlist_delete_elem(t_wordlist *elem)
{
	if (elem->next)
		elem->next->prev = elem->prev;
	if (elem->prev)
		elem->prev->next = elem->next;
	wordlist_delete(elem);
}
